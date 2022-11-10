#include <iostream>
#include <string>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "Lib.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
#pragma region Circle
    sf::CircleShape circle1(450.f);
    circle1.setFillColor(sf::Color::Color(255, 229, 153, 255));
    circle1.setPosition(sf::Vector2f::Vector2(510, 90));
    sf::CircleShape circle2(400.f);
    circle2.setFillColor(sf::Color::Color(0, 128, 128, 255));
    circle2.setPosition(sf::Vector2f::Vector2(560, 140));
    sf::CircleShape circle3(350.f);
    circle3.setFillColor(sf::Color::Color(234, 202, 202, 255));
    circle3.setPosition(sf::Vector2f::Vector2(610, 190));
    sf::CircleShape circle4(300.f);
    circle4.setFillColor(sf::Color::Color(255, 229, 153, 255));
    circle4.setPosition(sf::Vector2f::Vector2(660, 240));
    sf::CircleShape circle5(250.f);
    circle5.setFillColor(sf::Color::Color(0, 128, 128, 255));
    circle5.setPosition(sf::Vector2f::Vector2(710, 290));
    sf::CircleShape circle6(200.f);
    circle6.setFillColor(sf::Color::Color(234, 202, 202, 255));
    circle6.setPosition(sf::Vector2f::Vector2(760, 340));
    sf::CircleShape circle7(150.f);
    circle7.setFillColor(sf::Color::Color(255, 229, 153, 255));
    circle7.setPosition(sf::Vector2f::Vector2(810, 390));
    sf::CircleShape circle8(100.f);
    circle8.setFillColor(sf::Color::Color(0, 128, 128, 255));
    circle8.setPosition(sf::Vector2f::Vector2(860, 440));
    sf::CircleShape circle9(50.f);
    circle9.setFillColor(sf::Color::Color(234, 202, 202, 255));
    circle9.setPosition(sf::Vector2f::Vector2(910, 490));
#pragma endregion
    sf::ConvexShape convex;
    convex.setPointCount(6);

    // définit les points
    convex.setPoint(0, sf::Vector2f(960, 880));
    convex.setPoint(1, sf::Vector2f(660, 280));
    convex.setPoint(2, sf::Vector2f(810, 80));
    convex.setPoint(3, sf::Vector2f(960, 280));
    convex.setPoint(4, sf::Vector2f(1110, 80));
    convex.setPoint(5, sf::Vector2f(1260, 280));
    convex.setFillColor(sf::Color::Red);
    sf::Texture texture;
    if (!texture.loadFromFile("Asset/Chiaki Padoru.png")) return EXIT_FAILURE;
    sf::RectangleShape square(sf::Vector2f(512.f, 512.f));
    square.setTexture(&texture);
    //square.setFillColor(sf::Color::Color(234, 202, 202, 255));
    square.setPosition(sf::Vector2f::Vector2(704, 284));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        /*window.draw(circle1);
        window.draw(circle2);
        window.draw(circle3);
        window.draw(circle4);
        window.draw(circle5);
        window.draw(circle6);
        window.draw(circle7);
        window.draw(circle8);
        window.draw(circle9);*/
        window.draw(convex);
        window.draw(square);
        window.display();
    }

    return 0;
}