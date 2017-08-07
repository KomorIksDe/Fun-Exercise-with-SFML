#include "ConfigState.hpp"
#include "../Application.hpp"
#include "../ResourceManagers/ResourceHolder.hpp"

#include <iostream>

void State::ConfigState::setButton(sf::RectangleShape& button, TextureName name, float ratio) {
    button.setSize({200, 100});
    button.setOrigin({100, 50});
    button.setPosition({Display::get().WIDTH / 2, Display::get().HEIGHT / ratio});
    button.setTexture(&ResourceHolder::get().getTexture(name));
}

State::ConfigState::ConfigState(Application& app)
:   GameState(app) {

    m_background.setSize({Display::get().WIDTH, Display::get().HEIGHT});
    m_background.setTexture(&ResourceHolder::get().getTexture(TextureName::MenuBackground));

    setButton(m_testOption, TextureName::TestOption, 3.0f);
    setButton(m_backButton, TextureName::BackButton, 1.5f);
}

void State::ConfigState::input() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(isPressedOn(m_testOption))
            std::cout<<"Dizla"<<std::endl;
        else if(isPressedOn(m_backButton))
            m_p_app->popState();
    }
}

void State::ConfigState::update(float dt) {

}

void State::ConfigState::draw() {
    Display::get().draw(m_background);
    Display::get().draw(m_testOption);
    Display::get().draw(m_backButton);
}

bool State::ConfigState::isPressedOn(const sf::RectangleShape& button) {
    if(sf::Mouse::getPosition(*Display::get().window).x >= button.getPosition().x - button.getSize().x / 2
    && sf::Mouse::getPosition(*Display::get().window).x <= button.getPosition().x + button.getSize().x / 2
    && sf::Mouse::getPosition(*Display::get().window).y >= button.getPosition().y - button.getSize().y / 2
    && sf::Mouse::getPosition(*Display::get().window).y <= button.getPosition().y + button.getSize().y / 2) {
        return true;
    }
    else
        return false;
}
