#include "button.hpp"

Button::Button(double x, double y, sf::Sprite notpr, sf::Sprite pr)
    {
        pressed = pr;
        notpressed = notpr;
        active = false;
        setPosition(x, y);
    }


void Button::setPosition(double x, double y)
    {
        // Set position of both pressed and notpressed sprites
        sf::Vector2f pos(x, y);
        sf::Vector2f pos2(x - 6, y - 6); // Adjusted position for pressed sprite
        pressed.setPosition(pos);
        notpressed.setPosition(pos2);
    }

void Button::drawPressedTo(sf::RenderWindow& window)
    {
        window.draw(pressed);
    }

void Button::drawNotPressedTo(sf::RenderWindow& window)
    {
        window.draw(notpressed);
    }

void Button::draw(sf::RenderWindow& window){
    if (active){
        drawPressedTo(window);
    }
    else{
        drawNotPressedTo(window);
    }
}

bool Button::ispressed()
{
    return active;
}

void Button::press()
{
    active = true;
}

void Button::release()
{
    active = false;
}

bool Button::isMouseOver(sf::RenderWindow& window)
    {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = notpressed.getPosition().x;
        float btnPosY = notpressed.getPosition().y;

        float btnxPoswidth = notpressed.getPosition().x + notpressed.getLocalBounds().width;
        float btnyPosheight = notpressed.getPosition().y + notpressed.getLocalBounds().height;

        // Check if the mouse coordinates are within the button's boundaries
        if (mouseX < btnxPoswidth && mouseX > btnPosX && mouseY < btnyPosheight && mouseY > btnPosY)
        {
            return true; // Mouse is over the button
        }
        return false; // Mouse is not over the button
    }