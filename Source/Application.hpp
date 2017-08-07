#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "Display.hpp"
#include "States/GameState.hpp"
#include "ResourceManagers/ResourceHolder.hpp"

#include <memory>
#include <stack>

class Application {
    private:
        ResourceHolder m_resources;
        std::stack<std::unique_ptr<State::GameState>> m_states;

    public:
        Application();

        void runMainLoop();

        void pushState(std::unique_ptr<State::GameState> state);
        void popState();
        void changeState(std::unique_ptr<State::GameState> state);

        const ResourceHolder& getResources() const;
};

#endif // APPLICATION_HPP_INCLUDED
