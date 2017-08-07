#include "Animation.hpp"

Animation::Frame::Frame(const sf::IntRect& rect, float timeToNextFrame)
:   m_m_rect(rect), m_m_timeToNextFrame(timeToNextFrame)
{ }

sf::IntRect Animation::getFrame() {
    if(m_timer.getElapsedTime().asSeconds() >= m_frames.at(m_currentFrame).m_m_timeToNextFrame) {
        m_currentFrame++;
        m_timer.restart();

        if(m_currentFrame == m_frames.size())
            m_currentFrame = 0;
    }

    return m_frames.at(m_currentFrame).m_m_rect;
}

void Animation::addFrame(const sf::IntRect& rect, float timeToNextFrame) {
    m_frames.emplace_back(rect, timeToNextFrame);
}
