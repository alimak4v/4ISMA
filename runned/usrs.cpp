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
#include "usrs.h"

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void usrs::addUser(int months, int risk, int lpay, std::string type) {
    journal_.push_back({months, risk, lpay, type});
    sort(journal_.begin(), journal_.end());
}

void usrs::nextMonth() {
    std::vector<std::tuple<int, int, int, std::string>> temp_journal;
    for (int i = 0; i < journal_.size(); ++i) {
        if (--get<0>(journal_[i]) > 0) {
            temp_journal.push_back(journal_[i]);
        }
    }
    journal_ = temp_journal;
}

int usrs::check_var(int ins_p) {
    int kr = 0; // how many should you pay

    for (int i = 0; i < journal_.size(); ++i) {
        if (rng() % 300 < ins_p) {
            kr -= get<1>(journal_[i]);
        }
    }

    return kr;
}

std::string usrs::get_type(int index) {
    return get<3>(journal_[index]);
}