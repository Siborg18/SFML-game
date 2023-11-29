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
        window.display();
    }

    return 0;
}