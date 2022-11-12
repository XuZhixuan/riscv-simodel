#pragma once

#include <map>
#include <utility>

#include "common/common.hh"
#include "config/config.hh"
#include "logging/logging.hh"
#include "SimObject.hh"

namespace Sim::Factory {
    class BaseRegistry {
    public:
        virtual SimObjectPtr createComponent(Config::JsonConfig, id_t) = 0;
    };

    class Factory {
    protected:
        std::map<std::string, BaseRegistry *> m_ComponentRegistries{};
    public:
        static Factory &instance() {
            static Factory instance;
            return instance;
        }

        void registerComponent(const std::string &type, BaseRegistry *registry) {
            m_ComponentRegistries[type] = registry;
        }

        SimObjectPtr newComponent(const std::string &type, Config::JsonConfig cfg, id_t id) {
            return m_ComponentRegistries[type]->createComponent(std::move(cfg), id);
        }
    };

    template<class Component_T>
    class Registry : BaseRegistry {
    public:
        explicit Registry(const std::string &type) {
            Factory::instance().registerComponent(type, this);
        }

        SimObjectPtr createComponent(Config::JsonConfig cfg, id_t id) override {
            return std::make_shared<Component_T>(cfg, id);
        }
    };
}
