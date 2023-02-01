#include<Libraries.hpp>

#define W 1000
#define H 500

int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "AnimatedText");
    std::string str = "Hello, world!";

    AnimatedText text(20, 20, 30, str);
    text.Setup();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        text.Animation();

        window.clear();

        window.draw(*text.Get());

        window.display();
    }

    return 0;
}