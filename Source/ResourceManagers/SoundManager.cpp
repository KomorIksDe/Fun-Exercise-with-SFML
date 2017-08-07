#include "SoundManager.hpp"

SoundManager::SoundManager() {
    addResource(SoundName::Test, "Resources/Sounds/dck.ogg");
    addResource(SoundName::Splash1, "Resources/Sounds/Splash1.ogg");
    addResource(SoundName::Splash2, "Resources/Sounds/Splash2.ogg");
}
