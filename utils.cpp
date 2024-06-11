#include "utils.hpp"

void draw_lines(sf::RenderWindow &window){
    for(int i=0;i<WIDTH/t;i++){
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(i*t,0)),
            sf::Vertex(sf::Vector2f(i*t, HEIGHT))
        };
        window.draw(line, 2, sf::Lines);
    }
}

void clearArea(sf::RenderWindow &window, sf::Color color) {
    sf::FloatRect areaToClear(0,0, 230, 30); // Position and size of the area
    sf::RectangleShape rectangle;
    rectangle.setPosition(areaToClear.left, areaToClear.top);
    rectangle.setSize(sf::Vector2f(areaToClear.width, areaToClear.height));
    rectangle.setFillColor(color);
    window.draw(rectangle);
}