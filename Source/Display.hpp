#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <memory>

class Display {
    private:
        std::unique_ptr<sf::RenderWindow> window;

    public:
        static constexpr int WIDTH  = 1280;
        static constexpr int HEIGHT = 720;

    public:
        Display();

        static Display& get();

        void clear();
        void display();
        void draw(const sf::Drawable& drawable);
        void checkWindowEvents();

        bool windowIsOpen() const;
};

#endif // DISPLAY_HPP_INCLUDED
