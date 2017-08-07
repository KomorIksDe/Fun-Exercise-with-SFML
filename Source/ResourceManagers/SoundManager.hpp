#ifndef SOUNDMANAGER_HPP_INCLUDED
#define SOUNDMANAGER_HPP_INCLUDED

#include <SFML/Audio.hpp>

#include "ResourceManager.hpp"

enum class SoundName {
    Test,
    Splash1,
    Splash2
};

class SoundManager : public ResourceManager<SoundName, sf::SoundBuffer> {
    public:
        SoundManager();
};

#endif // SOUNDMANAGER_HPP_INCLUDED
