#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
public:
    // Constructeurs
     Circle();
     Circle(double x, double y,double rad);

     //Accesseurs et mutateurs
     void setX(double x);
     void setY(double y);
     void setRad(double rad);
     double getX() const;
     double getY() const;
     double getRad() const;

     // Autres méthodes
     double distance(const Circle &P) const;
     Circle middle(const Circle &P) const;

     void saisir();
     void afficher() const;

   private:
     double x,y,rad;
};

#endif // CIRCLE_H

