//
// Created by Quentin on 11/8/2017.
//

#ifndef FINDING_ROOTS_DISPLAY_H
#define FINDING_ROOTS_DISPLAY_H

#include <SFML/Graphics.hpp>

class Graph
{
private:
    sf::RenderWindow m_window;
    static const unsigned m_windowW = 1080;
    static const unsigned m_windowH = 720;

    float m_graphScale;
    float m_pixelScale;
    float m_originX;
    float m_originY;

protected:

public:
    Graph();

    sf::RenderWindow &getWindow();

    void drawAxes();
    void checkInput();

    void drawPolynomial(float a, float b, float c);
    void drawSqrt();
    void drawLog();
    void drawSin();
    void drawCos();
    void drawTan();

};

#endif //FINDING_ROOTS_DISPLAY_H