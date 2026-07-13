#include "CircleToSquareAdapter.h"

#include <iostream>

int main()
{
    Circle circle(4);
    Square square(5);
    SquareHole squareHole(5);
    if (squareHole.canFit(square))
    {
        std::cout << "\nSquare can fit inside hole.";        
    }
    else
    {
        std::cout << "\nSquare can't fit.";        
    }

    CircleToSquareAdapter adapter(circle);
    if (squareHole.canFit(adapter))
    {
        std::cout << "\nCircle can fit inside hole.";        
    }
    else
    {
        std::cout << "\nCircle can't fit.";        
    }
}