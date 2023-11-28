#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "SFML window");
    //sf::RenderWindow window(sf::VideoMode(200, 200));
    sf::CircleShape shape(100.f);
    sf::Font font;
    font.loadFromFile("src/NimbusMonoPS-Regular.otf");
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