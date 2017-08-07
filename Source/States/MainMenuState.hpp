#ifndef MAINMENUSTATE_HPP_INCLUDED
#define MAINMENUSTATE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "GameState.hpp"

namespace State {
    class MainMenuState : public GameState {
        private:
            sf::RectangleShape m_logo;
            sf::RectangleShape m_background;
            sf::RectangleShape m_playButton;
            sf::RectangleShape m_configButton;
            sf::RectangleShape m_exitButton;

            void setButton(sf::RectangleShape& button, TextureName name, float ratio);

        public:
            MainMenuState(Application& app);

            void input()          override;
            void update(float dt) override;
            void draw()           override;
    };
}

#endif // MAINMENUSTATE_HPP_INCLUDED
