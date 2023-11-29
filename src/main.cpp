#include <iostream>
#include <limits.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <unistd.h>

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



int main()
{
    std::cout << getexepath();
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "SFML window");
    //sf::RenderWindow window(sf::VideoMode(200, 200));
    sf::CircleShape shape(100.f);
    sf::Font font = loadmyFont();
    sf::Text someText("Some test text", font, 15U);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(someText);
        if (locationValid(shape))
        {
            shape.move(1.5 , 1.5);  
        }
        if (locationValid(someText))
        {
            someText.move(1.f, 1.f);
        }
        window.display();
        
    }

    return 0;
}