#include <math.h>

#include <iostream>
using namespace std;

const double PI = 2 * acos(0.0);

class Shape {
   public:
    static double totalArea;
    virtual void updateArea() = 0;
    static void displayArea() { cout << "AREA: " << totalArea << "\n"; }
};

double Shape::totalArea = 0;

class Triangle : public Shape {
    double a, b, c;

   public:
    Triangle() : a(0), b(0), c(0) {}
    Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}

    void updateArea() {
        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        Shape::totalArea += area;
    }
};

class Rectangle : public Shape {
    double length, breadth;

   public:
    Rectangle() : length(0), breadth(0) {}
    Rectangle(double l, double b) : length(l), breadth(b) {}

    void updateArea() {
        double area = length * breadth;
        Shape::totalArea += area;
    }
};

class Circle : public Shape {
    double radius;

   public:
    Circle() : radius(0) {}
    Circle(double radius) : radius(radius) {}

    void updateArea() {
        double area = PI * radius * radius;
        Shape::totalArea += area;
    }
};

int main() {
    Shape::displayArea();

    Triangle t1(3, 3, 3);
    t1.updateArea();
    Shape::displayArea();
    Rectangle r1(4, 5);
    r1.updateArea();
    Shape::displayArea();

    Circle c1(4);
    c1.updateArea();

    Shape::displayArea();
    return 0;
}
