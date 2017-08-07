#include "PlayingState.hpp"

#include <iostream>

#include "../Application.hpp"

State::PlayingState::PlayingState(Application& app)
:   GameState(app) {
    shape.setSize({256, 256});
    text.setString("Hejka xDxdxdDddDXDXDdd");

    shape.setTexture(&ResourceHolder::get().getTexture(TextureName::Slime));
    text.setFont(ResourceHolder::get().getFont(FontName::Test));
    sound.setBuffer(ResourceHolder::get().getSoundBuffer(SoundName::Test));

    sound.play();

    for(int i = 0; i < 5; i++)
        walkAnimation.addFrame({i * 50, 0, 50, 50}, 0.1f);

    for(int i = 3; i > 0; i--)
        walkAnimation.addFrame({i * 50, 0, 50, 50}, 0.1f);
}

void State::PlayingState::input() {

}

void State::PlayingState::update(float dt) {
    shape.setTextureRect(walkAnimation.getFrame());
}

void State::PlayingState::draw() {
    Display::get().draw(shape);
    Display::get().draw(text);
}
