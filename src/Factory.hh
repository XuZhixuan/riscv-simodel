#pragma once

#include <map>
#include <functional>

#include "common/common.hh"
#include "config/config.hh"
#include "logging/logging.hh"
#include "SimObject.hh"

namespace Sim::Factory
{
    /**
     * SimObject Construct Factory
     * @tparam Args
     */
    template<typename ...Args>
    class BaseFactory
    {
    protected:
        typedef std::function<SimObjectPtr(const Config::JsonConfig &, Args...)> createComponentFunc;

        /* Mapping registered class name to its constructor */
        std::map<std::string, createComponentFunc> m_ComponentRegistries{};

        // Instantiate of Factory class out of this scope is not allowed
        BaseFactory() = default;

    public:
        /**
         * @brief Get the static factory instance
         * 
         * @return Factory& 
         */
        static BaseFactory &instance()
        {
            static BaseFactory instance;
            return instance;
        }

        /**
         * @brief Register a class name with its constructor
         * 
         * @param type 
         * @param registry 
         */
        void registerComponent(const std::string &type, createComponentFunc registry)
        {
            m_ComponentRegistries[type] = registry;
        }

        template<class Component_T>
        class Register
        {
        public:
            /**
             * Constructor of register, used to register typename with class constructor
             * @param type
             */
            explicit Register(const std::string &type)
            {
                BaseFactory::instance().registerComponent(
                        type,
                        &Register::createComponent
                );
            }

        protected:
            /**
             * Internal function called to create a Component_T instance
             * @param cfg
             * @param id
             * @param args
             * @return
             */
            static SimObjectPtr createComponent(const Config::JsonConfig &cfg, Args... args)
            {
                return std::make_shared<Component_T>(cfg, args...);
            }
        };

        /**
         * Get a new SimObject instance with its name and config
         * @param type
         * @param cfg
         * @param id
         * @param args
         * @return SimObjectPtr new component with given config
         */
        SimObjectPtr newComponent(const std::string &type, const Config::JsonConfig &cfg, Args ...args)
        {
            return m_ComponentRegistries[type](cfg, args...);
        }

    public:
        // Copying of Factory object is not allowed
        BaseFactory(const BaseFactory &) = delete;

        BaseFactory(BaseFactory &&) = delete;

        BaseFactory &operator=(BaseFactory &) = delete;
    };
}
