#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <string>
#include "Button.h"

using namespace std;

/*
 * ERRORS
 * 2000 - error with loading front
 */

int main() {
    sf::RenderWindow window(sf::VideoMode(540, 720), "");

    Button start;
    start.setPosition({200, 400});
    start.setSize({200, 200});
    start.setText("start");

    Button finish;
    finish.setPosition({10, 670});
    finish.setSize({110, 40});
    finish.setText("finish");

    string scene = "main";
    
    while (window.isOpen()) {
        if (scene == "main") {
            sf::Event event{};

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (start.isPressed(window)) {
                        scene = "second scene";
                    }
                }
            }

            window.clear(sf::Color::White);
            start.show(window);
            window.display();
        }
        else if (scene == "second scene") {
            sf::Event event{};

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (finish.isPressed(window)) {
                        // wait
                    }
                }
            }

            window.clear(sf::Color::White);
            finish.show(window);
            window.display();
        }
    }

    return 0;
}