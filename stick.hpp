#ifndef STICK_HPP
#define STICK_HPP
#include "constants.hpp"
class Stick {
    private:
        double x,y;
        double angle;
        double len;
    public:
        Stick();
        Stick(const Stick &s);
        void draw(sf::RenderWindow &window,long long &number_of_stick_touch_lines);
};

#endif