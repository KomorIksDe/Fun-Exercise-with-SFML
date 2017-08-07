#include "Display.hpp"

Display::Display() {
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "Hejka xd");
}

Display& Display::get() {
    static Display display;

    return display;
}

void Display::clear() {
    window->clear();
}

void Display::display() {
    window->display();
}

void Display::draw(const sf::Drawable& drawable) {
    window->draw(drawable);
}

void Display::checkWindowEvents() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}

bool Display::windowIsOpen() const {
    return window->isOpen();
}
