//
// Created by Синицын Алексей on 28.09.2024.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <string>

#ifndef INC_4ISMA_BUTTON_H
#define INC_4ISMA_BUTTON_H


class Button {
public:
    Button();
    void setPosition(std::pair<float, float> position);
    void setText(std::string text);
    void setSize(std::pair<float, float> size);
    void show(sf::RenderWindow &window);
    bool isPressed(sf::RenderWindow &window);
private:
    sf::RectangleShape rectangle_;
    sf::Font font_;
    sf::Text text_;
};


#endif //INC_4ISMA_BUTTON_H
