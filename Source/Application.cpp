#include "Application.hpp"
#include "States/SplashScreenState.hpp"

Application::Application() {
    pushState(std::make_unique<State::SplashScreenState>(*this));
}

void Application::runMainLoop() {
    while (Display::get().windowIsOpen()) {
        Display::get().checkWindowEvents();
        Display::get().clear();

        m_states.top()->input();
        m_states.top()->update(0.0f);
        m_states.top()->draw();

        Display::get().display();
    }
}


void Application::pushState(std::unique_ptr<State::GameState> state) {
    m_states.push(std::move(state));
}

void Application::popState() {
    m_states.pop();
}

void Application::changeState(std::unique_ptr<State::GameState> state) {
    m_states.pop();
    m_states.push(std::move(state));
}

const ResourceHolder& Application::getResources() const {
    return m_resources;
}

