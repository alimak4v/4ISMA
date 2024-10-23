//
// Created by Синицын Алексей on 23.10.2024.
//
#include <iostream>
#include <unistd.h>
#include <utility>
#include <string>
#include <random>
#include <chrono>
#include <tuple>
#include "Button.h"
#include "insur.h"

#ifndef INC_4ISMA_USRS_H
#define INC_4ISMA_USRS_H

class usrs : public insur {
public:
    void addUser(int months, int risk, int lpay, std::string type);

    void nextMonth();

    int check_var(int ins_p);

    std::string get_type(int index);
private:
    //           .f \.s.f\.s.s\ non
    std::vector<std::tuple<int, int, int, std::string>> journal_; // type, months, risk, lpay
};


#endif //INC_4ISMA_USRS_H
