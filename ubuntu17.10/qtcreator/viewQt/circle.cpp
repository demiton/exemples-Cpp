#include "circle.h"
#include <cmath>
#include <iostream>
using namespace std;


Circle::Circle() : x(0), y(0),rad(1)
{}

Circle::Circle(double x, double y, double rad) : x(x), y(y),rad(rad)
{}

void Circle::setX(double x)
{
    this->x = x;
}

void Circle::setY(double y)
{
    this->y = y;
}

void Circle::setRad(double r)
{
    this->rad = r;
}

double Circle::getX() const
{
    return this->x;
}

double Circle::getY() const
{
    return this->y;
}

double Circle::getRad() const
{
    return this->rad;
}

double Circle::distance(const Circle &C) const
{
    double dx = this->x - C.x;
    double dy = this->y - C.y;
    return sqrt(dx*dx + dy*dy);
}

Circle Circle::middle(const Circle &C) const
{
    Circle result;
    result.x = (C.x + this->x) / 2;
    result.y = (C.y + this->y) / 2;
    return result;
}

void Circle::saisir()
{
    cout << "Tapez l'abscisse : ";  cin >> this->x;
    cout << "Tapez l'ordonnée : ";  cin >> this->y;
}

void Circle::afficher() const
{
    cout << "L'abscisse vaut " << this->x << endl;
    cout << "L'ordonnée vaut " << this->y << endl;
}

