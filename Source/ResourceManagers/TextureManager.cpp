#include "TextureManager.hpp"

TextureManager::TextureManager() {
    addResource(TextureName::Splash1, "Resources/Textures/Splash1.png");
    addResource(TextureName::Splash2, "Resources/Textures/Splash2.png");

    addResource(TextureName::MenuLogo,       "Resources/Textures/MenuLogo.png");
    addResource(TextureName::MenuBackground, "Resources/Textures/MenuBackground.png");
    addResource(TextureName::PlayButton,     "Resources/Textures/PlayButton.png");
    addResource(TextureName::ConfigButton,   "Resources/Textures/ConfigButton.png");
    addResource(TextureName::ExitButton,     "Resources/Textures/ExitButton.png");
}
