// https://neetcode.io/problems/adapter/question
#pragma once

class Circle
{
    int radius;
public:
    Circle(int radius) : radius{radius}
    {}
    virtual int getRadius()
    {
        return radius;
    }
};

class Square
{
    int sideLength;

public:
    Square(int sideLength) : sideLength{sideLength}
    {}
    virtual int getSideLength() 
    {
        return sideLength;
    }
};

class SquareHole
{  
    double sideLength;

public:
    SquareHole(double sideLength) : sideLength{sideLength} {}

    bool canFit(Square& square)
    {
        return sideLength >= square.getSideLength();
    }
};

class CircleToSquareAdapter : public Square
{
    Circle circle;

public:
    CircleToSquareAdapter(const Circle& circle) : circle{circle} {}
    int getSideLength() override
    {
        return circle.getRadius() * 2;
    }
};