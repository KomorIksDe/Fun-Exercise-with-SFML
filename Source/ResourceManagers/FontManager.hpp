#ifndef FONTMANAGER_HPP_INCLUDED
#define FONTMANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

enum class FontName {
    Test
};

class FontManager : public ResourceManager<FontName, sf::Font> {
    public:
        FontManager();
};

#endif // FONTMANAGER_HPP_INCLUDED
