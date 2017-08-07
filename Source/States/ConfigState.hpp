#ifndef CONFIGSTATE_HPP_INCLUDED
#define CONFIGSTATE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "GameState.hpp"

namespace State {
    class ConfigState : public GameState {
        private:
            sf::RectangleShape m_background;
            sf::RectangleShape m_testOption;
            sf::RectangleShape m_backButton;

            void setButton(sf::RectangleShape& button, TextureName name, float ratio);

        public:
            ConfigState(Application& app);

            void input()          override;
            void update(float dt) override;
            void draw()           override;

            bool isPressedOn(const sf::RectangleShape& button);
    };
}

#endif // CONFIGSTATE_HPP_INCLUDED
