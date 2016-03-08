#include "StateSubclass.h"
#include "Vector2Plus.h"
#include <iostream>
#define FPS 30.0
#define SPF 1/FPS

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "Touhou Clone", sf::Style::Close);

    StateManager sm;
    sm.addState(new SplashState(&sm));
    sm.addState(new GameState(&sm));
    sm.push(0);

    sf::Clock clock;
    while(window.isOpen())
    {
        clock.restart();
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
        }
        auto mousePos = sf::Mouse::getPosition(window);
        sm.handleInput(mousePos);
        sm.update(SPF);

        window.clear();
        sm.render(window);
        window.display();
        float timeSpent = clock.getElapsedTime().asSeconds();
        if(timeSpent<=SPF)
            sf::sleep(sf::seconds(SPF-timeSpent));
    }
}
