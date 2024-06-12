#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
    // Default constructor
    Button() {}

    // Constructor with initialization of pressed and notpressed sprites
    Button(double x,double y, sf::Sprite notpr, sf::Sprite pr);

    // Set position of the button
    void setPosition(double x, double y);

    // Draw the pressed sprite to the window
    void drawPressedTo(sf::RenderWindow& window);

    // Draw the notpressed sprite to the window
    void drawNotPressedTo(sf::RenderWindow& window);

    //Draw the Button to The window
    void draw(sf::RenderWindow& window);
    // Check if the button is pressed
    bool ispressed();

    // Set the button as pressed
    void press();

    // Set the button as released
    void release();

    // Check if the mouse is over the button
    bool isMouseOver(sf::RenderWindow& window);

private:
    sf::Sprite pressed;   // Sprite for the pressed state of the button
    sf::Sprite notpressed; // Sprite for the not pressed state of the button
    bool active;           // Flag to indicate if the button is currently pressed
};

#endif