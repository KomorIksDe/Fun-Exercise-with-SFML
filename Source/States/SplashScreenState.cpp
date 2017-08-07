#include "SplashScreenState.hpp"
#include "MainMenuState.hpp"
#include "../Application.hpp"
#include "../ResourceManagers/ResourceHolder.hpp"

State::SplashScreenState::SplashScreenState(Application& app)
:   GameState(app) {

    m_splashes.emplace(ResourceHolder::get().getTexture(TextureName::Splash1),
                       ResourceHolder::get().getSoundBuffer(SoundName::Splash1),
                       1.0f);

    m_splashes.emplace(ResourceHolder::get().getTexture(TextureName::Splash2),
                       ResourceHolder::get().getSoundBuffer(SoundName::Splash2),
                       1.0f);



    m_splashes.front().start();
}

void State::SplashScreenState::input() {

}

void State::SplashScreenState::update(float dt) {
    if(!m_splashes.empty()) {
        if(m_splashes.front().isOver()) {
            m_splashes.pop();

            if(!m_splashes.empty())
                m_splashes.front().start();
        }
    }
    else {
        m_p_app->changeState(std::make_unique<MainMenuState>(*m_p_app));
    }
}

void State::SplashScreenState::draw() {
    if(!m_splashes.empty())
        m_splashes.front().draw();
}

State::SplashScreenState::Splash::Splash(const sf::Texture& texture, float time)
:   m_sprite  ({Display::get().WIDTH, Display::get().HEIGHT})
,   m_time    (time)
,   m_hasSound(false) {

    m_sprite.setTexture(&texture);
}

State::SplashScreenState::Splash::Splash(const sf::Texture& texture, const sf::SoundBuffer& buffer, float time)
:   m_sprite  ({Display::get().WIDTH, Display::get().HEIGHT})
,   m_time    (time)
,   m_hasSound(true)
,   m_sound   (buffer) {

    m_sprite.setTexture(&texture);
}

bool State::SplashScreenState::Splash::isOver() const {
    return m_timer.getElapsedTime().asSeconds() >= m_time;
}

void State::SplashScreenState::Splash::start() {
    if(m_hasSound)
        m_sound.play();

    m_timer.restart();
}

void State::SplashScreenState::Splash::draw() {
    Display::get().draw(m_sprite);
}

