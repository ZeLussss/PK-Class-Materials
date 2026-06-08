// Autor: Ksawery Zelek
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Figure 
{
public:
    Figure( double x = 0, double y = 0 ) : x( x ), y( y ) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX( double x ) { this->x = x; }
    void setY( double y ) { this->y = y; }

    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

protected:
    double x, y;
};

class Circle : public Figure 
{
public:
    Circle( double x = 0, double y = 0, double radius = 0 ) : Figure( x, y ), radius( radius ) 
    {
        if ( radius < 0 ) 
        {
            this->radius = 0;
        }
    }

    double getRadius() const { return radius; }

    void setRadius( double radius ) 
    {
        if (radius >= 0)
            this->radius = radius;
    }

    void print() const 
    {
        cout << "Circle centre = (" << x << "," << y << ") radius = " << radius << endl;
    }

    double getArea() 
    {
        return M_PI * radius * radius;
    }

protected:
    double radius;
};

class Rectangle : public Figure {
public:
    Rectangle( double x = 0, double y = 0, double width = 0, double height = 0 ) : Figure( x, y ) 
    {
        this->width = ( width > 0 ) ? width : 0;
        this->height = std::max( 0.0, height );
    }

    double getWidth() const { return width; }
    double getHeight() const { return height; }

    void setWidth( double width ) { this->width = width; }
    void setHeight( double height ) { this->height = height; }

    void print() const 
    {
        cout << " Rectangle position = (" << x << "," << y << ") width = " << width << " height = " << height << endl;
    }

    double getArea() 
    {
        return width * height;
    }

protected:
    double width, height;
};

int main() 
{
  Circle c(1, 1, 3);
  Rectangle r(0, 1, 5, 6);
  c.print();
  cout << "Area = " << c.getArea() << endl;
  r.print();
  cout << "Area = " << r.getArea() << endl;
  
  return 0;
}