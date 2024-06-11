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


    sf::Text text,total_count,total_crossed;

    // select the font
    text.setFont(font);
    total_count.setFont(font);
    total_crossed.setFont(font);

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    total_count.setCharacterSize(24);
    total_crossed.setCharacterSize(24);

    // set the color
    text.setFillColor(sf::Color::Red);
    total_count.setFillColor(sf::Color::Black);
    total_crossed.setFillColor(sf::Color::Black);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    total_count.setStyle(sf::Text::Bold);
    total_crossed.setStyle(sf::Text::Bold);

    //set the position of texts
    total_count.setPosition(sf::Vector2f(WIDTH+l+40,50));
    total_crossed.setPosition(sf::Vector2f(WIDTH+l+40,100));
    
   

   
    long long number_of_stick_touch_lines = 0;
    sf::RenderWindow window(sf::VideoMode(WIDTH+parameters_width, HEIGHT), "Buffon's Needle");
    window.clear(sf::Color::White);
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
        sf::FloatRect areaToClear(0,0, 230, 30), clearTotalCount(WIDTH+l+40,50,300,40), clearTotalCrossed(WIDTH+l+40,100,300,40), clearFraction(WIDTH+l+40,150,300,80);
        clearArea(window,sf::Color::White,areaToClear); // Clear area with white color
        clearArea(window,sf::Color::White,clearTotalCount); // Clear area with white color
        clearArea(window,sf::Color::White,clearTotalCrossed); // Clear area with white color
        clearArea(window,sf::Color::White,clearFraction);
        // set the strings to display
        total_count.setString("Total Count :"+std::to_string(number_of_sticks));
        total_crossed.setString("Total Crossed :"+std::to_string(number_of_stick_touch_lines));
        window.draw(total_count);
        window.draw(total_crossed);
        draw_text(window,number_of_sticks,number_of_stick_touch_lines,font);
        double aproximated_pi = (2.0*number_of_sticks*l)/(number_of_stick_touch_lines*t);
        text.setString("Aprox_PI="+std::to_string(aproximated_pi));
        window.draw(text);
        window.display();
        usleep(10000);
        
        
        //cout<<aproximated_pi<<endl;
    }



    return 0;
}