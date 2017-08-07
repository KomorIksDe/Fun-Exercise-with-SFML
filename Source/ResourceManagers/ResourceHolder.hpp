#ifndef RESOURCEHOLDER_HPP_INCLUDED
#define RESOURCEHOLDER_HPP_INCLUDED

#include "TextureManager.hpp"
#include "SoundManager.hpp"
#include "FontManager.hpp"

struct ResourceHolder {
    private:
        TextureManager textures;
        SoundManager   sounds;
        FontManager    fonts;

    public:
        static ResourceHolder& get();

        const sf::Texture& getTexture(TextureName name)       const;
        const sf::SoundBuffer& getSoundBuffer(SoundName name) const;
        const sf::Font& getFont(FontName name)                const;

        const sf::Vector2f& getTextureSize(TextureName name)  const;
};

#endif // RESOURCEHOLDER_HPP_INCLUDED
