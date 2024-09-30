#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <string>
#include <random>
#include <chrono>
#include "Button.h"

using namespace std;

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

/*
 * ERRORS
 * 2000 - error with loading front
 */

int main() {
    sf::RenderWindow window(sf::VideoMode(720, 720), "");

    Button start;
    start.setPosition({315, 340});
    start.setSize({90, 40});
    start.setText("start");

    //================================================================================================================
    Button capital;
    capital.setPosition({133, 100});
    capital.setSize({126, 40});
    capital.setText("capital");

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
    //------------------------------------
    int capital_p = 1000000; // начальный капитал $
    double tax_p = 0.09; // налог
    int demand_p = 25; // спрос (кол-во людей, которым нужна страховка)
    int period_p = 12; // месяцы игры
    int insurance_p = 25; // процент угрозы
    //================================================================================================================
    int now_capital = 0;
    vector<pair<int, pair<int, int>>> journal; // (сколько месяцев ост, [сколько надо заплатить в случае ситуации, сколько платит чел в месяц])
    //------------------------------------
    Button capital_b;
    capital_b.setPosition({10, 10});
    capital_b.setSize({180, 40});
    capital_b.setText(to_string(now_capital) + "$");
    //------------------------------------
    Button settings_b;
    settings_b.setPosition({566, 10});
    settings_b.setSize({144, 40});
    settings_b.setText("settings");
    //------------------------------------
    Button next_month;
    next_month.setPosition({530, 60});
    next_month.setSize({180, 40});
    next_month.setText("next month");
    //------------------------------------
    int month = 0;

    Button num_month;
    num_month.setPosition({10, 60});
    num_month.setSize({144, 40});
    num_month.setText(to_string(month) + " month");
    //================================================================================================================
    int risk_mon = 0;

    Button person_risk;
    person_risk.setPosition({301, 300});
    person_risk.setSize({144, 40});
    person_risk.setText(to_string(risk_mon));
    //------------------------------------
    Button name_risk;
    name_risk.setPosition({57, 300});
    name_risk.setSize({234, 40});
    name_risk.setText("insurance pay");
    //------------------------------------
    int ll_pay = 0;

    Button person_ll_pay;
    person_ll_pay.setPosition({301, 350});
    person_ll_pay.setSize({144, 40});
    person_ll_pay.setText(to_string(ll_pay));
    //------------------------------------
    Button name_pay;
    name_pay.setPosition({147, 350});
    name_pay.setSize({144, 40});
    name_pay.setText("will pay");
    //------------------------------------
    Button name_mon;
    name_mon.setPosition({147, 400});
    name_mon.setSize({144, 40});
    name_mon.setText("how long");
    //------------------------------------
    int ll_mon = 0;

    Button person_ll_mon;
    person_ll_mon.setPosition({301, 400});
    person_ll_mon.setSize({198, 40});
    person_ll_mon.setText(to_string(ll_mon) + " month(s)");
    //------------------------------------
    Button agree;
    agree.setPosition({301, 600});
    agree.setSize({54, 40});
    agree.setText("yes");
    //------------------------------------
    Button not_agree;
    not_agree.setPosition({365, 600});
    not_agree.setSize({36, 40});
    not_agree.setText("no");
    //================================================================================================================

    string scene = "start_screen";

    int k_new = rng() % (demand_p - 2) + 2;

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
                            capital_mid.setColor(sf::Color::Yellow);
                            capital_high.setColor(sf::Color::Yellow);
                            capital_p = 500000;
                        } else if (capital_mid.isPressed(window)) {
                            capital_low.setColor(sf::Color::Yellow);
                            capital_mid.setColor(sf::Color::Red);
                            capital_high.setColor(sf::Color::Yellow);
                            capital_p = 1000000;
                        } else if (capital_high.isPressed(window)) {
                            capital_low.setColor(sf::Color::Yellow);
                            capital_mid.setColor(sf::Color::Yellow);
                            capital_high.setColor(sf::Color::Red);
                            capital_p = 10000000;
                        }
                        if (tax_low.isPressed(window)) {
                            tax_low.setColor(sf::Color::Red);
                            tax_mid.setColor(sf::Color::Yellow);
                            tax_high.setColor(sf::Color::Yellow);
                            tax_p = 0.01;
                        } else if (tax_mid.isPressed(window)) {
                            tax_low.setColor(sf::Color::Yellow);
                            tax_mid.setColor(sf::Color::Red);
                            tax_high.setColor(sf::Color::Yellow);
                            tax_p = 0.09;
                        } else if (tax_high.isPressed(window)) {
                            tax_low.setColor(sf::Color::Yellow);
                            tax_mid.setColor(sf::Color::Yellow);
                            tax_high.setColor(sf::Color::Red);
                            tax_p = 0.18;
                        }
                        if (demand_low.isPressed(window)) {
                            demand_low.setColor(sf::Color::Red);
                            demand_mid.setColor(sf::Color::Yellow);
                            demand_high.setColor(sf::Color::Yellow);
                            demand_p = 5;
                        } else if (demand_mid.isPressed(window)) {
                            demand_low.setColor(sf::Color::Yellow);
                            demand_mid.setColor(sf::Color::Red);
                            demand_high.setColor(sf::Color::Yellow);
                            demand_p = 25;
                        } else if (demand_high.isPressed(window)) {
                            demand_low.setColor(sf::Color::Yellow);
                            demand_mid.setColor(sf::Color::Yellow);
                            demand_high.setColor(sf::Color::Red);
                            demand_p = 50;
                        }
                        if (period_low.isPressed(window)) {
                            period_low.setColor(sf::Color::Red);
                            period_mid.setColor(sf::Color::Yellow);
                            period_high.setColor(sf::Color::Yellow);
                            period_p = 6;
                        } else if (period_mid.isPressed(window)) {
                            period_low.setColor(sf::Color::Yellow);
                            period_mid.setColor(sf::Color::Red);
                            period_high.setColor(sf::Color::Yellow);
                            period_p = 12;
                        } else if (period_high.isPressed(window)) {
                            period_low.setColor(sf::Color::Yellow);
                            period_mid.setColor(sf::Color::Yellow);
                            period_high.setColor(sf::Color::Red);
                            period_p = 24;
                        }
                        if (insurance_low.isPressed(window)) {
                            insurance_low.setColor(sf::Color::Red);
                            insurance_mid.setColor(sf::Color::Yellow);
                            insurance_high.setColor(sf::Color::Yellow);
                            insurance_p = 10;
                        } else if (insurance_mid.isPressed(window)) {
                            insurance_low.setColor(sf::Color::Yellow);
                            insurance_mid.setColor(sf::Color::Red);
                            insurance_high.setColor(sf::Color::Yellow);
                            insurance_p = 25;
                        } else if (insurance_high.isPressed(window)) {
                            insurance_low.setColor(sf::Color::Yellow);
                            insurance_mid.setColor(sf::Color::Yellow);
                            insurance_high.setColor(sf::Color::Red);
                            insurance_p = 50;
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
                        num_month.setText(to_string(month) + " month");

                        k_new = rng() % (demand_p - 2) + 2;

                        risk_mon = 1000 * (rng() % 500 + 100);
                        person_risk.setText(to_string(risk_mon) + "$");

                        ll_pay = risk_mon * 100.0 / ((rng() % 50) + 90);
                        person_ll_pay.setText(to_string(ll_pay) + "$");

                        ll_mon = rng() % (period_p) + 1;
                        person_ll_mon.setText(to_string(ll_mon) + " month(s)");
                    }
                    if (k_new) {
                        if (agree.isPressed(window)) {
                            risk_mon = 1000 * (rng() % 500 + 100);
                            person_risk.setText(to_string(risk_mon) + "$");

                            ll_pay = risk_mon * 100.0 / ((rng() % 50) + 90);
                            person_ll_pay.setText(to_string(ll_pay) + "$");

                            ll_mon = rng() % (period_p) + 1;
                            person_ll_mon.setText(to_string(ll_mon) + " month(s)");

                            --k_new;
                        } else if (not_agree.isPressed(window)) {
                            risk_mon = 1000 * (rng() % 500 + 100);
                            person_risk.setText(to_string(risk_mon) + "$");

                            ll_pay = risk_mon * 100.0 / ((rng() % 50) + 90);
                            person_ll_pay.setText(to_string(ll_pay) + "$");

                            ll_mon = rng() % (period_p) + 1;
                            person_ll_mon.setText(to_string(ll_mon) + " month(s)");

                            --k_new;
                        }
                    }
                }
                capital_b.setText(to_string(now_capital) + "$");
            }

            window.clear(sf::Color::White);

            capital_b.show(window);
            next_month.show(window);
            settings_b.show(window);
            num_month.show(window);

            if (k_new) {
                name_risk.show(window);
                name_pay.show(window);
                name_mon.show(window);

                person_risk.show(window);
                person_ll_pay.show(window);
                person_ll_mon.show(window);
                agree.show(window);
                not_agree.show(window);
            }

            window.display();
        }
    }

    return 0;
}