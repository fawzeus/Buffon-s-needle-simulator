#include "utils.hpp"
#include "button.hpp"
#include <unistd.h>
#include <iostream>
using namespace std;

int main(){
    vector<Stick> sticks;
    bool add_100=false;
    long long needles_added=0;
    srand(time(0));
    sf::Font font;
    if (!font.loadFromFile("./fonts/arial.ttf"))
    {
        puts("error while loading font");
        return 1;
    }

    // create a button to add 100 needles
    sf::Texture add_needles_np_sprite, add_needles_p_sprite;
	add_needles_np_sprite.loadFromFile("images/button_add-needle_not_pressed.png");
	add_needles_p_sprite.loadFromFile("images/button_add-needle_pressed.png");

	sf::Sprite add_needles_np(add_needles_np_sprite), add_needles_p(add_needles_p_sprite);
	Button add_needles(WIDTH+l+40,300,add_needles_np, add_needles_p);

    //create a button to restart simulation
    sf::Texture new_simulation_np_sprite, new_simulation_p_sprite;
    new_simulation_np_sprite.loadFromFile("images/button_new-simulation_not_pressed.png");
    new_simulation_p_sprite.loadFromFile("images/button_new-simulation_pressed.png");

    sf::Sprite new_simulation_np(new_simulation_np_sprite),new_simulation_p(new_simulation_p_sprite);
    Button new_simulation(WIDTH+l+40,400,new_simulation_np,new_simulation_p);

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
    draw_lines(window);
    long long number_of_sticks =0;
    while (window.isOpen())
    {   
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type==sf::Event::MouseButtonPressed){
                if(add_needles.isMouseOver(window) and !add_needles.ispressed()){
                    add_needles.press();
                    add_100=true;
                }
                if(new_simulation.isMouseOver(window) and !new_simulation.ispressed()){
                    new_simulation.press();
                    add_100=false;
                    needles_added=0;
                    number_of_stick_touch_lines=0;
                    number_of_sticks=0;
                    window.clear(sf::Color::White);
                    draw_lines(window);
                    sticks.erase(sticks.begin(),sticks.end());
                }
            }
            else if(event.type==sf::Event::MouseButtonReleased){
                if(add_needles.ispressed()){
                    add_needles.release();
                }
                if(new_simulation.ispressed()){
                    new_simulation.release();
                }
            }
        }
        if(needles_added==100){
            add_100=false;
            needles_added=0;
        }
        if(add_100){
            needles_added++;
            Stick s;
            number_of_sticks++;
            //s.draw(window,number_of_stick_touch_lines);
            sticks.push_back(s);
        }
            window.clear(sf::Color::White);
            number_of_stick_touch_lines=0;
            draw_lines(window);
            // set the strings to display
            draw_sticks(sticks,window,number_of_stick_touch_lines);
            total_count.setString("Total Count :"+std::to_string(number_of_sticks));
            total_crossed.setString("Total Crossed :"+std::to_string(number_of_stick_touch_lines));
            window.draw(total_count);
            window.draw(total_crossed);
            add_needles.draw(window);
            new_simulation.draw(window);
            draw_text(window,number_of_sticks,number_of_stick_touch_lines,font);
            //double aproximated_pi = (2.0*number_of_sticks*l)/(number_of_stick_touch_lines*t);
            //text.setString("Aprox_PI="+std::to_string(aproximated_pi));
            //window.draw(text);
        window.display();
        usleep(10000);
        
        
        //cout<<aproximated_pi<<endl;
    }



    return 0;
}