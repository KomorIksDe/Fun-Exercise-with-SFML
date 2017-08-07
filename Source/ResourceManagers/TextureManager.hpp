#ifndef TEXTUREMANAGER_HPP_INCLUDED
#define TEXTUREMANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

enum class TextureName {
    Slime,
    Splash1,
    Splash2,
    MenuLogo,
    MenuBackground,
    PlayButton,
    ConfigButton,
    ExitButton
};

class TextureManager : public ResourceManager<TextureName, sf::Texture> {
    public:
        TextureManager();
};

#endif // TEXTUREMANAGER_HPP_INCLUDED
