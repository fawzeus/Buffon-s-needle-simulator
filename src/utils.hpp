#ifndef UTILS_HPP
#define UTILS_HPP
#include "constants.hpp"
#include "stick.hpp"
#include <iomanip>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <vector>
void draw_lines(sf::RenderWindow &window);
void clearArea(sf::RenderWindow &window, sf::Color color,sf::FloatRect &area);// a function to clear a given area of the window
void draw_text(sf::RenderWindow &window, int total, int crossing,sf::Font font);
void draw_sticks(std::vector<Stick> sticks,sf::RenderWindow& window, long long &number_of_sticks_touching_line);
#endif