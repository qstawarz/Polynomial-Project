//
// Created by Quentin on 11/8/2017.
//
#include <iostream>
#include <cmath>

#include "Functions.h"

Functions::Functions()
{

}

void Functions::polynomialRoots(float a, float b, float c)
{
    float root1 = 0;
    float root2 = 0;

    if (a != 0)
    {
        float delta = pow(b, 2) - (4 * a * c);
        std::cout << "Delta : " << delta << std::endl;

        if (delta < 0)
            std::cout << "No real roots" << std::endl;

        if (delta > 0)
        {
            std::cout << "2 different roots" << std::endl;
            root1 = (-b + sqrt(delta)) / (2 * a);
            root2 = (-b - sqrt(delta)) / (2 * a);
        }

        if (delta == 0)
        {
            std::cout << "2 same roots" << std::endl;
            root1 = (-b + sqrt(delta)) / (2 * a);
            root2 = (-b - sqrt(delta)) / (2 * a);
        }
    }

    std::cout << "Root1 : " << root1 << std::endl;
    std::cout << "Root2 : " << root2 << std::endl;
}