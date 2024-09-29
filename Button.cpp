//
// Created by Синицын Алексей on 28.09.2024.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <string>
#include "Button.h"

Button::Button() {
    rectangle_.setFillColor(sf::Color::Yellow);
    if (!font_.loadFromFile("PTMono.ttc")) {
        exit(2000);
    }
    text_.setFont(font_);
    text_.setCharacterSize(30);
    text_.setFillColor(sf::Color::Black);
}

void Button::setPosition(std::pair<float, float> position) {
    rectangle_.setPosition({position.first, position.second});
    text_.setPosition({position.first, position.second});
}

void Button::setText(std::string text) {
    text_.setString(text);
}

void Button::setSize(std::pair<float, float> size) {
    rectangle_.setSize({size.first, size.second});
}

void Button::show(sf::RenderWindow &window) {
    window.draw(rectangle_);
    window.draw(text_);
}

bool Button::isPressed(sf::RenderWindow &window) {
    if (sf::Mouse::getPosition(window).x >= rectangle_.getPosition().x &&
        sf::Mouse::getPosition(window).y >= rectangle_.getPosition().y &&
        sf::Mouse::getPosition(window).x <= rectangle_.getPosition().x + rectangle_.getSize().x &&
        sf::Mouse::getPosition(window).y <= rectangle_.getPosition().y + rectangle_.getSize().y) {
        std::cout << "BUTTON " << std::string(text_.getString())  << " PRESSED" << std::endl;
        return true;
    }
    return false;
}

void Button::setColor(sf::Color color) {
    rectangle_.setFillColor(color);
}