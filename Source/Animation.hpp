#ifndef ANIMATION_HPP_INCLUDED
#define ANIMATION_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
    struct Frame {
        Frame(const sf::IntRect& rect, float timeToNextFrame);

        const sf::IntRect m_m_rect;
        const float       m_m_timeToNextFrame;
    };

    public:
        sf::IntRect getFrame();
        void addFrame(const sf::IntRect& rect, float timeToNextFrame);

    private:
        std::vector<Frame> m_frames;
        sf::Clock          m_timer;
        unsigned           m_currentFrame = 0;
};

#endif // ANIMATION_HPP_INCLUDED
