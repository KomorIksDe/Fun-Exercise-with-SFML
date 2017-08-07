#ifndef PLAYINGSTATE_HPP_INCLUDED
#define PLAYINGSTATE_HPP_INCLUDED

#include "GameState.hpp"
#include "../Animation.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace State {
    class PlayingState : public GameState {
        private:
            Animation walkAnimation;

            sf::RectangleShape shape;
            sf::Sound          sound;
            sf::Text           text;

        public:
            PlayingState(Application& app);

            void input()          override;
            void update(float dt) override;
            void draw()           override;
    };
}

#endif // PLAYINGSTATE_HPP_INCLUDED
