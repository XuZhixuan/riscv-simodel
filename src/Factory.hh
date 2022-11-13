#pragma once

#include <map>

#include "common/common.hh"
#include "config/config.hh"
#include "logging/logging.hh"
#include "SimObject.hh"

namespace Sim::Factory
{
    /**
     * @brief Base Register for SimObject
     *
     */
    class BaseRegistry
    {
    public:
        /**
         * @brief Pure virtual function interface of creating components
         *
         * @return SimObjectPtr (std::shared_ptr<SimObject>)
         */
        virtual SimObjectPtr createComponent(Config::JsonConfig, id_t) = 0;
    };

    /**
     * @brief SimObject Construct Factory
     *
     */
    class Factory
    {
    protected:
        /* Mapping registered class name to its contructor */
        std::map<std::string, BaseRegistry *> m_ComponentRegistries{};

    public:
        /**
         * @brief Get the static factory instance
         * 
         * @return Factory& 
         */
        static Factory &instance()
        {
            static Factory instance;
            return instance;
        }

        /**
         * @brief Register a class name with its constructor
         * 
         * @param type 
         * @param registry 
         */
        void registerComponent(const std::string &type, BaseRegistry *registry)
        {
            m_ComponentRegistries[type] = registry;
        }

        /**
         * @brief Get a new SimObject instance with its name and config
         * 
         * @param type 
         * @param cfg 
         * @param id 
         * @return SimObjectPtr (std::shared_ptr<SimObject>)
         */
        SimObjectPtr newComponent(const std::string &type, Config::JsonConfig cfg, id_t id)
        {
            return m_ComponentRegistries[type]->createComponent(std::move(cfg), id);
        }

    private:
        // Instaniate of Factory class is not allowed
        Factory() {};

        // Copying of Factory object is not allowed
        Factory(const Factory &) = delete;
        Factory &operator=(Factory &) = delete;
    };

    /**
     * @brief Drived Register for class drived from SimObject
     * 
     * @tparam Component_T 
     */
    template <class Component_T>
    class Registry : BaseRegistry
    {
    public:
        /**
         * @brief Constructor Registry and register the class to factory map
         * 
         * @param type 
         */
        explicit Registry(const std::string &type)
        {
            Factory::instance().registerComponent(type, this);
        }

        /**
         * @brief Implementation of creating the new SimObject instance
         * 
         * @param cfg 
         * @param id 
         * @return SimObjectPtr (std::shared_ptr<SimObject>)
         */
        SimObjectPtr createComponent(Config::JsonConfig cfg, id_t id) override
        {
            return std::make_shared<Component_T>(cfg, id);
        }
    };
}
