#include "MainMenuState.hpp"
#include "../Application.hpp"
#include "../ResourceManagers/ResourceHolder.hpp"

#include <iostream>

void State::MainMenuState::setButton(sf::RectangleShape& button, TextureName name, float ratio){
    button.setSize({200, 100});
    button.setOrigin({100, 50});
    button.setPosition({Display::get().WIDTH / 2, Display::get().HEIGHT / ratio});
    button.setTexture(&ResourceHolder::get().getTexture(name));
}

State::MainMenuState::MainMenuState(Application& app)
:   GameState(app) {

    m_background.setSize({Display::get().WIDTH, Display::get().HEIGHT});
    m_background.setTexture(&ResourceHolder::get().getTexture(TextureName::MenuBackground));

    m_logo.setSize(sf::Vector2f(ResourceHolder::get().getTextureSize(TextureName::MenuLogo)));
    m_logo.setOrigin({m_logo.getSize().x / 2, m_logo.getSize().y / 2});
    m_logo.setPosition({Display::get().WIDTH / 2, 100});
    m_logo.setTexture(&ResourceHolder::get().getTexture(TextureName::MenuLogo));

    setButton(m_playButton,   TextureName::PlayButton,   2.5f);
    setButton(m_configButton, TextureName::ConfigButton, 1.62f);
    setButton(m_exitButton,   TextureName::ExitButton,   1.2f);
}

void State::MainMenuState::input() {

}

void State::MainMenuState::update(float dt) {

}

void State::MainMenuState::draw() {
    Display::get().draw(m_background);
    Display::get().draw(m_logo);
    Display::get().draw(m_playButton);
    Display::get().draw(m_configButton);
    Display::get().draw(m_exitButton);
}
