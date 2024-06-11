#include "stick.hpp"
#include <bits/stdc++.h> 
Stick::Stick(){
    x = rand()%WIDTH+l;
    y = rand()%HEIGHT; 
    len=l;
    angle = (double)rand() / RAND_MAX  * TWO_PI;
}

void Stick::draw(sf::RenderWindow &window, long long &number_of_stick_touch_lines){
    sf::Color color=sf::Color::Black;
    double dx = (len / 2.0) * cos(angle);
    double dy = (len / 2.0) * sin(angle);
    sf::Vector2f point1(x-dx, y-dy);
    sf::Vector2f point2(x+dx, y+dy);
    for(int i=0 ; i<=WIDTH/t;i++){
        if(std::min(x-dx,x+dx)<=i*t and i*t<=std::max(x-dx,x+dx))
            {
                color=sf::Color::Green;
                number_of_stick_touch_lines++;
            }
    }
    sf::Vertex line[] = {
            sf::Vertex(point1, color),
            sf::Vertex(point2, color)
        };
        window.draw(line, 2, sf::Lines);
}

Stick::Stick(const Stick &s){
    x = s.x;
    y = s.y; 
    len=s.len;
    angle = s.angle ;
}