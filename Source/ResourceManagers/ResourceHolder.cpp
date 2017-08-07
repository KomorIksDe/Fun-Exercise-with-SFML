#include "ResourceHolder.hpp"

ResourceHolder& ResourceHolder::get() {
    static ResourceHolder rsholder;

    return rsholder;
}

const sf::Texture& ResourceHolder::getTexture(TextureName name) const {
    return textures.get(name);
}

const sf::SoundBuffer& ResourceHolder::getSoundBuffer(SoundName name) const {
    return sounds.get(name);
}

const sf::Font& ResourceHolder::getFont(FontName name) const {
    return fonts.get(name);
}

const sf::Vector2f& ResourceHolder::getTextureSize(TextureName name) const {
    return {textures.get(name).getSize().x, textures.get(name).getSize().y};
}

