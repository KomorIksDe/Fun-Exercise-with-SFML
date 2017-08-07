#ifndef RESOURCEMANAGER_HPP_INCLUDED
#define RESOURCEMANAGER_HPP_INCLUDED

#include <map>

template<typename Enum, typename Resource>
class ResourceManager {
    private:
        std::map<Enum, Resource> m_resources;

    public:
        const Resource& get(Enum name) const {
            return m_resources.at(name);
        }

    protected:
        void addResource(Enum name, const std::string& path) {
            Resource res;

            res.loadFromFile(path);
            m_resources.insert(std::make_pair(name, res));
        }
};

#endif // RESOURCEMANAGER_HPP_INCLUDED
