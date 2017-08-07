#ifndef SPLASHSCREENSTATE_HPP_INCLUDED
#define SPLASHSCREENSTATE_HPP_INCLUDED

#include "GameState.hpp"
#include "../Animation.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <queue>

namespace State {
    class SplashScreenState : public GameState {
        class Splash {
            public:
                Splash(const sf::Texture& texture, float time);
                Splash(const sf::Texture& texture, const sf::SoundBuffer& buffer, float time);

                bool isOver() const;
                void start();
                void draw();

            private:
                float              m_time;
                bool               m_hasSound;
                sf::Clock          m_timer;
                sf::Sound          m_sound;
                sf::RectangleShape m_sprite;
        };

        public:
            SplashScreenState(Application& app);

            void input()          override;
            void update(float dt) override;
            void draw()           override;

        private:
            std::queue<Splash> m_splashes;
    };
}

#endif // SPLASHSCREENSTATE_HPP_INCLUDED
