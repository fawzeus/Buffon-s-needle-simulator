#ifndef UTILS_HPP
#define UTILS_HPP
#include "constants.hpp"
#include "stick.hpp"
void draw_lines(sf::RenderWindow &window);
void clearArea(sf::RenderWindow &window, sf::Color color,sf::FloatRect &area);
void draw_text(sf::RenderWindow &window, int total, int crossing,sf::Font font);
#endif