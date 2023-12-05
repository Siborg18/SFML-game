#include <iostream>
#include <limits.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>
#include "shapes.h"


std::string getexepath()
{
  char result[ PATH_MAX ];
  ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
  return std::string( result, (count > 0) ? count : 0 );
}

sf::Font loadmyFont()
{
    sf::Font font;
    if (!font.loadFromFile("NimbusMonoPS-Regular.otf"))
    {
        std::cout << "Could not load font." << std::endl;
    }
    return font;
}


bool locationValid(sf::Shape &shape)
{
    sf::Vector2f temp = shape.getPosition();
    int x = temp.x + 1;
    int y = temp.y + 1;

    if (x > 800 || x < 0)
    {
        return false;
    }

    if (y > 600 || y < 0)
    {
        return false;
    }

return true;
}

bool locationValid(sf::Text &text)
{
    sf::Vector2f temp = text.getPosition();
    int x = temp.x + 1;
    int y = temp.y + 1;

    if (x > 800 || x < 0)
    {
        return false;
    }

    if (y > 600 || y < 0)
    {
        return false;
    }

return true;
}

void printCurrentLocation(sf::Shape &shape)
{
    sf::Vector2 myLocation = shape.getPosition();
    std::cout << "x: " << myLocation.x << " y: " << myLocation.y << std::endl;
}


int main()
{ 
    std::cout << getexepath();
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "SFML window");
    //sf::RenderWindow window(sf::VideoMode(200, 200));
    sf::CircleShape myCircleShape(10.f);
    myCircleShape.setFillColor(sf::Color::Green);
    sf::RectangleShape myRectangleShape;
    myRectangleShape.setFillColor(sf::Color::Green);
    myRectangleShape.setSize(sf::Vector2f(10, 5));
    sf::RectangleShape anotherRectangleShape;
    anotherRectangleShape.setFillColor(sf::Color::Blue);
    anotherRectangleShape.setSize(sf::Vector2f(15.f, 15.f));
    sf::Font font = loadmyFont();
    sf::Text someText("", font, 20U);
    sf::Text someMoreText("", font, 20U);
    if(locationValid(someText))
    {
        someText.setPosition(0.f, 20.f);
    }
    if (locationValid(anotherRectangleShape))
    {
        anotherRectangleShape.setPosition(20.f, 600 / 2.f);
    }
    if (locationValid(myRectangleShape))
    {   
        myRectangleShape.setPosition(0, 0);
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }
        window.clear();
        //window.draw(myCircleShape);
        window.draw(myRectangleShape);
        window.draw(anotherRectangleShape);
        sf::FloatRect boundingAnotherBox = anotherRectangleShape.getGlobalBounds();
        sf::FloatRect boundingRectangleBox = myRectangleShape.getGlobalBounds();
        // printCurrentLocation(myRectangleShape);
        // std::cout << (boundingAnotherBox.intersects(boundingRectangleBox));
        window.draw(someText);
        window.draw(someMoreText);
        if (boundingAnotherBox.intersects(boundingRectangleBox) && myRectangleShape.getPosition() != sf::Vector2f(0, 0));
        {
            sf::Vector2f rectanglePosition {myRectangleShape.getPosition()};
            sf::Vector2f anotherRectanglePosition {anotherRectangleShape.getPosition()};

            int x1 = rectanglePosition.x;
            int y1 = rectanglePosition.y;
            int x2 = anotherRectanglePosition.x;
            int y2 = anotherRectanglePosition.y;
            std::string someString = "Intersected at: x: " + std::to_string(x1) + " y: " + std::to_string(y1);
            std::string someOtherString = "Intersected at: x: " + std::to_string(x2) + " y: " + std::to_string(y2);
            someText.setString(someString);
            someMoreText.setString(someOtherString);
            anotherRectangleShape.setFillColor(sf::Color::Red);
        }

        if (locationValid(myRectangleShape))
        {
            myRectangleShape.move(0.f, 0.1);
        }
        window.display();
        
    }

    return 0;
}