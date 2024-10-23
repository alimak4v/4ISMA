#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <string>
#include <random>
#include <chrono>
#include <tuple>

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#include "include/Button.h"
#include "include/insur.h"
#include "include/usrs.h"

using namespace std;

// сделать вывод челиков, у которых заканчивается страховка
// добавить анимацию челика

/*
 * ERRORS
 * 2000 - error with loading front
 */

int main() {
    sf::RenderWindow window(sf::VideoMode(720, 720), "");

    double fps = 60.0;
    int capital_p = 1000000; // начальный капитал $
    double tax_p = 0.09; // налог
    int demand_p = 25; // спрос (кол-во людей, которым нужна страховка)
    int period_p = 12; // месяцы игры
    int insurance_p = 25; // процент угрозы

    vector<int> stat_money;

    Button start;
    start.setPosition({315, 340});
    start.setSize({90, 40});
    start.setText("start");
    start.setColor(sf::Color::Green);
    //================================================================================================================
    Button capital;
    capital.setPosition({133, 100});
    capital.setSize({126, 40});
    capital.setText("capital");
    capital.setColor(sf::Color::Yellow);

    Button capital_low;
    capital_low.setPosition({333, 100});
    capital_low.setSize({54, 40});
    capital_low.setText("low");

    Button capital_mid;
    capital_mid.setPosition({397, 100});
    capital_mid.setSize({108, 40});
    capital_mid.setText("middle");
    capital_mid.setColor(sf::Color::Red);

    Button capital_high;
    capital_high.setPosition({515, 100});
    capital_high.setSize({72, 40});
    capital_high.setText("high");
    //------------------------------------
    Button tax;
    tax.setPosition({133, 150});
    tax.setSize({54, 40});
    tax.setText("tax");
    tax.setColor(sf::Color::Yellow);

    Button tax_low;
    tax_low.setPosition({333, 150});
    tax_low.setSize({54, 40});
    tax_low.setText("low");

    Button tax_mid;
    tax_mid.setPosition({397, 150});
    tax_mid.setSize({108, 40});
    tax_mid.setText("middle");
    tax_mid.setColor(sf::Color::Red);

    Button tax_high;
    tax_high.setPosition({515, 150});
    tax_high.setSize({72, 40});
    tax_high.setText("high");
    //------------------------------------
    Button demand;
    demand.setPosition({133, 200});
    demand.setSize({108, 40});
    demand.setText("demand");
    demand.setColor(sf::Color::Yellow);

    Button demand_low;
    demand_low.setPosition({333, 200});
    demand_low.setSize({54, 40});
    demand_low.setText("low");

    Button demand_mid;
    demand_mid.setPosition({397, 200});
    demand_mid.setSize({108, 40});
    demand_mid.setText("middle");
    demand_mid.setColor(sf::Color::Red);

    Button demand_high;
    demand_high.setPosition({515, 200});
    demand_high.setSize({72, 40});
    demand_high.setText("high");
    //------------------------------------
    Button period;
    period.setPosition({133, 250});
    period.setSize({108, 40});
    period.setText("period");
    period.setColor(sf::Color::Yellow);

    Button period_low;
    period_low.setPosition({333, 250});
    period_low.setSize({54, 40});
    period_low.setText("low");

    Button period_mid;
    period_mid.setPosition({397, 250});
    period_mid.setSize({108, 40});
    period_mid.setText("middle");
    period_mid.setColor(sf::Color::Red);

    Button period_high;
    period_high.setPosition({515, 250});
    period_high.setSize({72, 40});
    period_high.setText("high");
    //------------------------------------
    Button insurance;
    insurance.setPosition({133, 300});
    insurance.setSize({180, 40});
    insurance.setText("%insurance");
    insurance.setColor(sf::Color::Yellow);

    Button insurance_low;
    insurance_low.setPosition({333, 300});
    insurance_low.setSize({54, 40});
    insurance_low.setText("low");

    Button insurance_mid;
    insurance_mid.setPosition({397, 300});
    insurance_mid.setSize({108, 40});
    insurance_mid.setText("middle");
    insurance_mid.setColor(sf::Color::Red);

    Button insurance_high;
    insurance_high.setPosition({515, 300});
    insurance_high.setSize({72, 40});
    insurance_high.setText("high");
    //------------------------------------
    Button next;
    next.setPosition({324, 350});
    next.setSize({72, 40});
    next.setText("next");
    next.setColor(sf::Color::Green);
    //------------------------------------
    //================================================================================================================
    int now_capital = 0;
    usrs journal; // (сколько месяцев ост, [сколько надо заплатить в случае ситуации, сколько платит чел в месяц])
    //------------------------------------
    Button capital_b;
    capital_b.setPosition({10, 10});
    capital_b.setSize({180, 40});
    capital_b.setText(to_string(now_capital) + "$");
    capital_b.setColor(sf::Color::Yellow);
    //------------------------------------
    Button minus_b;
    minus_b.setPosition({200, 10});
    minus_b.setSize({180, 40});
    minus_b.setText("-" + to_string(0) + "$");
    minus_b.setColor(sf::Color::Red);
    //------------------------------------
    Button settings_b;
    settings_b.setPosition({566, 10});
    settings_b.setSize({144, 40});
    settings_b.setText("settings");
    settings_b.setColor(sf::Color::Yellow);
    //------------------------------------
    Button next_month;
    next_month.setPosition({530, 60});
    next_month.setSize({180, 40});
    next_month.setText("next month");
    next_month.setColor(sf::Color::Yellow);
    //------------------------------------
    int month = 0;

    Button num_month;
    num_month.setPosition({10, 60});
    num_month.setSize({144, 40});
    num_month.setText(to_string(month) + " month");
    num_month.setColor(sf::Color::Yellow);
    //================================================================================================================
    string type_value = "";

    Button person_type;
    person_type.setPosition({347, 250});
    person_type.setSize({360, 40});
    int r = rng() % 3 + 1;
    if (r == 1) {
        type_value = "insurance for car";
    }
    else if (r == 2) {
        type_value = "insurance for house";
    }
    else {
        type_value = "insurance for health";
    }
    person_type.setText(type_value);
    //------------------------------------
    int risk_mon = 0;

    Button person_risk;
    person_risk.setPosition({501, 300});
    person_risk.setSize({144, 40});
    person_risk.setText(to_string(risk_mon));
    //------------------------------------
    Button name_risk;
    name_risk.setPosition({347, 300});
    name_risk.setSize({144, 40});
    name_risk.setText("ins. pay");
    //------------------------------------
    int ll_pay = 0;

    Button person_ll_pay;
    person_ll_pay.setPosition({501, 350});
    person_ll_pay.setSize({144, 40});
    person_ll_pay.setText(to_string(ll_pay));
    //------------------------------------
    Button name_pay;
    name_pay.setPosition({347, 350});
    name_pay.setSize({144, 40});
    name_pay.setText("will pay");
    //------------------------------------
    Button name_mon;
    name_mon.setPosition({347, 400});
    name_mon.setSize({144, 40});
    name_mon.setText("how long");
    //------------------------------------
    int ll_mon = 0;

    Button person_ll_mon;
    person_ll_mon.setPosition({501, 400});
    person_ll_mon.setSize({198, 40});
    person_ll_mon.setText(to_string(ll_mon) + " month(s)");
    //------------------------------------
    Button agree;
    agree.setPosition({301, 600});
    agree.setSize({54, 40});
    agree.setText("yes");
    agree.setColor(sf::Color::Green);
    //------------------------------------
    Button not_agree;
    not_agree.setPosition({365, 600});
    not_agree.setSize({36, 40});
    not_agree.setText("no");
    not_agree.setColor(sf::Color::Red);
    //================================================================================================================
    string scene = "start_screen";

    int k_new = rng() % (demand_p - 2) + 2;

    int pribil = 0;
    int frame = 0;

    while (window.isOpen()) {
        if (scene == "start_screen") {
            sf::Event event{};

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (start.isPressed(window)) {
                        scene = "settings_screen";
                    }
                }
            }

            window.clear(sf::Color::White);
            start.show(window);
            window.display();
        }
        else if (scene == "settings_screen") {
            sf::Event event{};

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    //------------------------------------
                    {
                        if (capital_low.isPressed(window)) {
                            capital_low.setColor(sf::Color::Red);
                            capital_mid.setColor(sf::Color::White);
                            capital_high.setColor(sf::Color::White);
                            capital_p = 500000;
                        } else if (capital_mid.isPressed(window)) {
                            capital_low.setColor(sf::Color::White);
                            capital_mid.setColor(sf::Color::Red);
                            capital_high.setColor(sf::Color::White);
                            capital_p = 1000000;
                        } else if (capital_high.isPressed(window)) {
                            capital_low.setColor(sf::Color::White);
                            capital_mid.setColor(sf::Color::White);
                            capital_high.setColor(sf::Color::Red);
                            capital_p = 10000000;
                        }
                        if (tax_low.isPressed(window)) {
                            tax_low.setColor(sf::Color::Red);
                            tax_mid.setColor(sf::Color::White);
                            tax_high.setColor(sf::Color::White);
                            tax_p = 0.03;
                        } else if (tax_mid.isPressed(window)) {
                            tax_low.setColor(sf::Color::White);
                            tax_mid.setColor(sf::Color::Red);
                            tax_high.setColor(sf::Color::White);
                            tax_p = 0.13;
                        } else if (tax_high.isPressed(window)) {
                            tax_low.setColor(sf::Color::White);
                            tax_mid.setColor(sf::Color::White);
                            tax_high.setColor(sf::Color::Red);
                            tax_p = 0.25;
                        }
                        if (demand_low.isPressed(window)) {
                            demand_low.setColor(sf::Color::Red);
                            demand_mid.setColor(sf::Color::White);
                            demand_high.setColor(sf::Color::White);
                            demand_p = 5;
                        } else if (demand_mid.isPressed(window)) {
                            demand_low.setColor(sf::Color::White);
                            demand_mid.setColor(sf::Color::Red);
                            demand_high.setColor(sf::Color::White);
                            demand_p = 25;
                        } else if (demand_high.isPressed(window)) {
                            demand_low.setColor(sf::Color::White);
                            demand_mid.setColor(sf::Color::White);
                            demand_high.setColor(sf::Color::Red);
                            demand_p = 50;
                        }
                        if (period_low.isPressed(window)) {
                            period_low.setColor(sf::Color::Red);
                            period_mid.setColor(sf::Color::White);
                            period_high.setColor(sf::Color::White);
                            period_p = 6;
                        } else if (period_mid.isPressed(window)) {
                            period_low.setColor(sf::Color::White);
                            period_mid.setColor(sf::Color::Red);
                            period_high.setColor(sf::Color::White);
                            period_p = 12;
                        } else if (period_high.isPressed(window)) {
                            period_low.setColor(sf::Color::White);
                            period_mid.setColor(sf::Color::White);
                            period_high.setColor(sf::Color::Red);
                            period_p = 24;
                        }
                        if (insurance_low.isPressed(window)) {
                            insurance_low.setColor(sf::Color::Red);
                            insurance_mid.setColor(sf::Color::White);
                            insurance_high.setColor(sf::Color::White);
                            insurance_p = 15;
                        } else if (insurance_mid.isPressed(window)) {
                            insurance_low.setColor(sf::Color::White);
                            insurance_mid.setColor(sf::Color::Red);
                            insurance_high.setColor(sf::Color::White);
                            insurance_p = 30;
                        } else if (insurance_high.isPressed(window)) {
                            insurance_low.setColor(sf::Color::White);
                            insurance_mid.setColor(sf::Color::White);
                            insurance_high.setColor(sf::Color::Red);
                            insurance_p = 90;
                        }
                    }
                    //------------------------------------
                    if (next.isPressed(window)) {
                        scene = "game_screen";

                        now_capital = capital_p;
                        capital_b.setText(to_string(now_capital) + "$");

                        risk_mon = 1000 * (rng() % 500 + 100);
                        person_risk.setText(to_string(risk_mon) + "$");

                        ll_pay = risk_mon * 100.0 / ((rng() % 50) + 90);
                        person_ll_pay.setText(to_string(ll_pay) + "$");

                        ll_mon = rng() % (period_p) + 1;
                        person_ll_mon.setText(to_string(ll_mon) + " month(s)");

                        k_new = rng() % (demand_p - 2) + 2;
                    }
                }
            }

            window.clear(sf::Color::White);

            {
                capital.show(window);
                capital_low.show(window);
                capital_mid.show(window);
                capital_high.show(window);
            }
            //------------------------------------
            {
                tax.show(window);
                tax_low.show(window);
                tax_mid.show(window);
                tax_high.show(window);
            }
            //------------------------------------
            {
                demand.show(window);
                demand_low.show(window);
                demand_mid.show(window);
                demand_high.show(window);
            }
            //------------------------------------
            {
                period.show(window);
                period_low.show(window);
                period_mid.show(window);
                period_high.show(window);
            }
            //------------------------------------
            {
                insurance.show(window);
                insurance_low.show(window);
                insurance_mid.show(window);
                insurance_high.show(window);
            }
            //------------------------------------
            {
                next.show(window);
            }

            window.display();
        }
        else if (scene == "game_screen") {
            sf::Event event{};

            window.clear(sf::Color::White);

            if (month >= period_p) {
                scene = "statistic_screen";
            }

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (settings_b.isPressed(window)) {
                        scene = "settings_screen";
                    }
                    else if (next_month.isPressed(window)) {
                        ++month;
                        stat_money.push_back(pribil);
                        pribil = 0;
                        journal.nextMonth();

                        int minus = journal.check_var(insurance_p);
                        now_capital += minus;
                        pribil += minus;
                        now_capital -= now_capital * tax_p;
                        cout << minus << endl;
                        minus_b.setText("-" + to_string(-minus) + "$");

                        num_month.setText(to_string(month) + " month");

                        k_new = rng() % (demand_p - 2) + 2;

                        risk_mon = 1000 * (rng() % 500 + 100);
                        person_risk.setText(to_string(risk_mon) + "$");

                        ll_pay = 1.5 * risk_mon * 100.0 / ((rng() % 100) + 100);
                        person_ll_pay.setText(to_string(ll_pay) + "$");

                        ll_mon = rng() % (period_p) + 1;
                        person_ll_mon.setText(to_string(ll_mon) + " month(s)");


                    }
                    if (k_new) {
                        if (agree.isPressed(window)) {
                            journal.addUser(ll_mon, risk_mon, ll_pay, type_value);
                            now_capital += ll_pay;
                            pribil += ll_pay;

                            r = rng() % 3 + 1;
                            if (r == 1) {
                                type_value = "insurance for car";
                            }
                            else if (r == 2) {
                                type_value = "insurance for house";
                            }
                            else {
                                type_value = "insurance for health";
                            }
                            person_type.setText(type_value);

                            ll_mon = rng() % (period_p) + 1;
                            person_ll_mon.setText(to_string(ll_mon) + " month(s)");

                            risk_mon = 1000 * (rng() % 500 + 100);
                            person_risk.setText(to_string(risk_mon) + "$");

                            ll_pay = risk_mon * 100.0 / ((rng() % 80) + 100);
                            person_ll_pay.setText(to_string(ll_pay) + "$");

                            --k_new;
                        } else if (not_agree.isPressed(window)) {
                            r = rng() % 3 + 1;

                            if (r == 1) {
                                type_value = "insurance for car";
                            }
                            else if (r == 2) {
                                type_value = "insurance for house";
                            }
                            else {
                                type_value = "insurance for health";
                            }
                            person_type.setText(type_value);

                            ll_mon = rng() % (period_p) + 1;
                            person_ll_mon.setText(to_string(ll_mon) + " month(s)");

                            risk_mon = 1000 * (rng() % 500 + 100);
                            person_risk.setText(to_string(risk_mon) + "$");

                            ll_pay = risk_mon * 100.0 / ((rng() % 80) + 100);
                            person_ll_pay.setText(to_string(ll_pay) + "$");

                            --k_new;
                        }
                    }
                }
                capital_b.setText(to_string(now_capital) + "$");
            }

            capital_b.show(window);
            minus_b.show(window);
            next_month.show(window);
            settings_b.show(window);
            num_month.show(window);

            if (k_new) {
                name_risk.show(window);
                name_pay.show(window);
                name_mon.show(window);

                person_type.show(window);
                person_risk.show(window);
                person_ll_pay.show(window);
                person_ll_mon.show(window);
                agree.show(window);
                not_agree.show(window);
            }

            window.display();
        }
        else if (scene == "statistic_screen") {
            sf::Event event{};

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::White);
            window.display();

            if (frame <= 1000) {
                ++frame;
            }
        }
        usleep(1000/fps);
    }

    for (auto el : stat_money) {
        cout << el << " ";
    }

    return 0;
}