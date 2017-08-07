#ifndef GAMESTATE_HPP_INCLUDED
#define GAMESTATE_HPP_INCLUDED

#include "../ResourceManagers/ResourceHolder.hpp"

class Application;

namespace State {
    class GameState {
        protected:
            Application* m_p_app;

        public:
            GameState(Application& app);

            virtual void input()          = 0;
            virtual void update(float dt) = 0;
            virtual void draw()           = 0;
    };
}

#endif // GAMESTATE_HPP_INCLUDED
