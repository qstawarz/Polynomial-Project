//
// Created by Quentin on 11/8/2017.
//
#include <cmath>
#include <iostream>

#include "Graph.h"

Graph::Graph() :  m_window {sf::VideoMode(this->m_windowW, this->m_windowH), "Finding_Roots"},
                  m_graphScale {100.0f}, m_pixelScale {1.0f},
                  m_originX {m_windowW / 2}, m_originY {m_windowH / 2}
{

}

sf::RenderWindow &Graph::getWindow()
{
    return this->m_window;
}

void Graph::checkInput()
{
    sf::Event event;

    while (this->m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->m_window.close();

        if (event.key.code == sf::Keyboard::Escape)
            this->m_window.close();

        if (event.type == sf::Event::MouseWheelMoved)
        {
            if (this->m_graphScale < 10)
                this->m_graphScale = 10;

            if (this->m_graphScale > 10)
                this->m_graphScale += event.mouseWheel.delta * 10;
            else if(this->m_graphScale <= 10 && event.mouseWheel.delta > 0)
                this->m_graphScale += event.mouseWheel.delta * 10;
        }
    }
}

void Graph::drawAxes()
{
    //X Axes
    sf::RectangleShape axeX(sf::Vector2f(this->m_windowW, this->m_pixelScale));
    axeX.setPosition(0.0f, this->m_originY);
    axeX.setFillColor(sf::Color::White);

    //Y Axes
    sf::RectangleShape axeY(sf::Vector2f(this->m_pixelScale, this->m_windowH));
    axeY.setPosition(this->m_originX, 0.0f);
    axeY.setFillColor(sf::Color::White);

    this->m_window.draw(axeX);
    this->m_window.draw(axeY);
}

void Graph::drawPolynomial(float a, float b, float c)
{
    sf::RectangleShape pixels;
    pixels.setSize(sf::Vector2f(this->m_pixelScale, this->m_pixelScale));
    pixels.setFillColor(sf::Color::Magenta);

    float y;

    for (int x = 0; x < this->m_windowW; ++x)
    {
        y = static_cast<float>(-(a * pow((1 / this->m_graphScale) * x, 2) +
                b * (1 / this->m_graphScale) * x + c) * this->m_graphScale);
        pixels.setPosition(x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);

        y = static_cast<float>(-(a * pow((1 / this->m_graphScale) * -x, 2) +
                b * (1 / this->m_graphScale) * -x + c) * this->m_graphScale);
        pixels.setPosition(-x + this->m_originX,  y + this->m_originY);
        this->m_window.draw(pixels);
    }
}

void Graph::drawSqrt()
{
    sf::RectangleShape pixels;
    pixels.setSize(sf::Vector2f(this->m_pixelScale, this->m_pixelScale));
    pixels.setFillColor(sf::Color::Red);

    float y;

    for (int x = 0; x < this->m_windowW; ++x)
    {
        y = static_cast<float>(-sqrt((1 / this->m_graphScale) * x) * this->m_graphScale);
        pixels.setPosition(x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);

        y = static_cast<float>(-sqrt((1 / this->m_graphScale) * -x) * this->m_graphScale);
        pixels.setPosition(-x + this->m_originX,  y + this->m_originY);
        this->m_window.draw(pixels);
    }
}

void Graph::drawLog()
{
    sf::RectangleShape pixels;
    pixels.setSize(sf::Vector2f(this->m_pixelScale, this->m_pixelScale));
    pixels.setFillColor(sf::Color::Green);

    float y;

    for (int x = 0; x < this->m_windowW; ++x)
    {
        y = static_cast<float>(-log((1 / this->m_graphScale) * x) * this->m_graphScale);
        pixels.setPosition(x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);

        y = static_cast<float>(-log((1 / this->m_graphScale) * -x) * this->m_graphScale);
        pixels.setPosition(-x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);
    }
}

void Graph::drawSin()
{
    sf::RectangleShape pixels;
    pixels.setSize(sf::Vector2f(this->m_pixelScale, this->m_pixelScale));
    pixels.setFillColor(sf::Color::Blue);

    float y;

    for (int x = 0; x < this->m_windowW; ++x)
    {
        y = static_cast<float>(-sin((1 / this->m_graphScale) * x) * this->m_graphScale);
        pixels.setPosition(x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);

        y = static_cast<float>(-sin((1 / this->m_graphScale) * -x) * this->m_graphScale);
        pixels.setPosition(-x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);
    }
}

void Graph::drawCos()
{
    sf::RectangleShape pixels;
    pixels.setSize(sf::Vector2f(this->m_pixelScale, this->m_pixelScale));
    pixels.setFillColor(sf::Color::Cyan);

    float y;

    for (int x = 0; x < this->m_windowW; ++x)
    {
        y = static_cast<float>(-cos((1 / this->m_graphScale) * x) * this->m_graphScale);
        pixels.setPosition(x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);

        y = static_cast<float>(-cos((1 / this->m_graphScale) * -x) * this->m_graphScale);
        pixels.setPosition(-x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);
    }
}

void Graph::drawTan()
{
    sf::RectangleShape pixels;
    pixels.setSize(sf::Vector2f(this->m_pixelScale, this->m_pixelScale));
    pixels.setFillColor(sf::Color::Yellow);

    float y;

    for (int x = 0; x < this->m_windowW; ++x)
    {
        y = static_cast<float>(-tan((1 / this->m_graphScale) * x) * this->m_graphScale);
        pixels.setPosition(x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);

        y = static_cast<float>(-tan((1 / this->m_graphScale) * -x) * this->m_graphScale);
        pixels.setPosition(-x + this->m_originX, y + this->m_originY);
        this->m_window.draw(pixels);
    }
}
