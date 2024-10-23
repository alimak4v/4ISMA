//
// Created by Синицын Алексей on 23.10.2024.
//

#include "insur.h"
#include <iostream>
#include <unistd.h>
#include <utility>
#include <string>
#include <random>
#include <chrono>
#include <tuple>

void insur::game_started() {
    std::cout << "__________________________________________" << std::endl;
    std::cout << "|==========>   GAME STARTED   <==========|" << std::endl;
    std::cout << "|________________________________________|" << std::endl;
    std::cout << "|           In                           |" << std::endl;
    std::cout << "|                Su                      |" << std::endl;
    std::cout << "|                     Ra                 |" << std::endl;
    std::cout << "|                          Nce           |" << std::endl;
    std::cout << "|________________________________________|" << std::endl;
}