#include "utils.hpp"
#include <unistd.h>
#include <iostream>
using namespace std;

int main(){
    srand(time(0));
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        puts("error while loading font");
        return 1;
    }
    sf::Text text;

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

   
    long long number_of_stick_touch_lines = 0;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");
    long long number_of_sticks =0;
    while (window.isOpen())
    {   
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Stick s;
        number_of_sticks++;
        draw_lines(window);
        s.draw(window,number_of_stick_touch_lines);
        clearArea(window,sf::Color::White); // Clear area with white color
        // set the string to display
        double aproximated_pi = (2.0*number_of_sticks*l)/(number_of_stick_touch_lines*t);
        text.setString("Aprox_PI="+std::to_string(aproximated_pi));
        window.draw(text);
        window.display();
        usleep(100000);
        
        
        //cout<<aproximated_pi<<endl;
    }



    return 0;
}