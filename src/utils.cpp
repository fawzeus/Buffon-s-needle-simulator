#include "utils.hpp"
void draw_lines(sf::RenderWindow &window) {
    float thickness = 2.0f;
    sf::RectangleShape line;
    line.setFillColor(sf::Color::Magenta);
    line.setSize(sf::Vector2f(thickness, HEIGHT));

    for (int i = 1; i <= WIDTH / t; i++) {
        line.setPosition(i * t, 0);
        window.draw(line);
    }
}


void clearArea(sf::RenderWindow &window, sf::Color color,sf::FloatRect &area) {
    //sf::FloatRect areaToClear(0,0, 230, 30); // Position and size of the area
    sf::RectangleShape rectangle;
    rectangle.setPosition(area.left, area.top);
    rectangle.setSize(sf::Vector2f(area.width, area.height));
    rectangle.setFillColor(color);
    window.draw(rectangle);
}
void draw_text(sf::RenderWindow &window, int total, int crossing, sf::Font font) {
    double value = 1.0 * total / crossing;

    sf::Text text_total, text_crossing, text_val, text_equals1, text_equals2, text_result;

    text_total.setFont(font);
    text_crossing.setFont(font);
    text_val.setFont(font);
    text_equals1.setFont(font);
    text_equals2.setFont(font);
    text_result.setFont(font);

    text_total.setCharacterSize(14);
    text_crossing.setCharacterSize(14);
    text_val.setCharacterSize(14);
    text_equals1.setCharacterSize(14);
    text_equals2.setCharacterSize(14);
    text_result.setCharacterSize(14);

    text_total.setFillColor(sf::Color::Black);
    text_crossing.setFillColor(sf::Color::Black);
    text_val.setFillColor(sf::Color::Black);
    text_equals1.setFillColor(sf::Color::Black);
    text_equals2.setFillColor(sf::Color::Black);
    text_result.setFillColor(sf::Color::Black);

    text_total.setString("Total");
    text_crossing.setString("Crossing");
    text_val.setString(std::to_string(total));
    text_result.setString(std::to_string(crossing));
    text_equals1.setString("=");
    text_equals2.setString("=");

    // Set positions starting from (WIDTH + l + 40, 150)
    double start_x = WIDTH + l + 40;
    double start_y = 150;

    text_total.setPosition(start_x, start_y);
    text_crossing.setPosition(start_x, start_y + 50);
    text_equals1.setPosition(start_x + 60, start_y + 25);
    text_val.setPosition(start_x + 90, start_y);
    text_result.setPosition(start_x + 90, start_y + 50);
    text_equals2.setPosition(start_x + 140, start_y + 25);

    // Draw horizontal lines
    sf::VertexArray line1(sf::Lines, 2);
    line1[0].position = sf::Vector2f(start_x, start_y + 35);
    line1[1].position = sf::Vector2f(start_x + 55, start_y + 35);

    sf::VertexArray line2(sf::Lines, 2);
    line2[0].position = sf::Vector2f(start_x + 75, start_y + 35);
    line2[1].position = sf::Vector2f(start_x + 125, start_y + 35);

    line1[0].color = sf::Color::Black;
    line1[1].color = sf::Color::Black;
    line2[0].color = sf::Color::Black;
    line2[1].color = sf::Color::Black;

    // Draw all the text and lines
    window.draw(text_total);
    window.draw(text_crossing);
    window.draw(text_equals1);
    window.draw(text_val);
    window.draw(text_result);
    window.draw(text_equals2);
    window.draw(line1);
    window.draw(line2);

    // Draw the result value
    std::stringstream ss;
    ss << std::fixed << std::setprecision(4) << value;
    text_result.setString(ss.str());
    text_result.setPosition(start_x + 190, start_y + 25);
    window.draw(text_result);
}

void draw_sticks(std::vector<Stick> sticks,sf::RenderWindow& window, long long &number_of_sticks_touching_line){
    for(Stick stick:sticks){
        stick.draw(window,number_of_sticks_touching_line);
    }
}