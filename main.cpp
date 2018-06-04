#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.hpp"



int main(){
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "SFML Textures");

    float posX = WINDOW_X/2;
    float posY = WINDOW_Y/2;

    sf::Image image;
    image.create(255, 255);
    sf::Vector2u imageSize = image.getSize();

    sf::Clock clock;
    float dt;

    for(int y = 0; y < imageSize.y; y++){
        for(int x = 0; x < imageSize.x; x++){
            float dx = (float) x - 100.0f;
            float dy = (float) y - 100.0f;
            if(dx*dx + dy*dy < 100*100) {
                image.setPixel(x, y, sf::Color::Green);
            }
        }
    }

    sf::Texture textureBall;
    textureBall.loadFromImage(image);
    
    sf::Sprite spriteBall(textureBall);

    while (window.isOpen()){
        dt = clock.getElapsedTime().asSeconds();
        sf::Event event;
        while(window.pollEvent(event)){
            dt = clock.getElapsedTime().asSeconds();
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                posX -= 20 * dt;
                spriteBall.move(-(20 * dt), 0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                posX += 20 * dt;
                spriteBall.move(20 * dt, 0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
                posY += 20 * dt;
                spriteBall.move(0, 20 * dt);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
                posY -= 20 * dt;
                spriteBall.move(0, -(20 * dt));
            }
        //spriteBall.setPosition(posX, posY);
        window.clear();
        window.draw(spriteBall);
        window.display();
        clock.restart();
        }
    }
    return EXIT_SUCCESS;
}