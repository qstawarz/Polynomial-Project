#include <iostream>
#include <SFML/Graphics.hpp>

#include "Graph.h"
#include "Functions.h"

int main()
{
    //Polynomial equation
    float a = 1;
    float b = 2;
    float c = 3;
//    float a, b, c;
//    std::cout << "ENTER A" << std::endl;
//    std::cin >> a;
//    std::cout << "ENTER B" << std::endl;
//    std::cin >> b;
//    std::cout << "ENTER C" << std::endl;
//    std::cin >> c;

    Functions function;

    function.polynomialRoots(a, b, c);

    Graph graph;

    while (graph.getWindow().isOpen())
    {
        graph.getWindow().clear();

        graph.checkInput();

        graph.drawAxes();

        graph.drawPolynomial(a, b, c);
        graph.drawSqrt();
        graph.drawLog();
        graph.drawSin();
        graph.drawCos();
        graph.drawTan();

        graph.getWindow().display();
    }

    return 0;
}