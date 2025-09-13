#include <iostream>
using namespace std;
class Circle {
private:
    double radius;
    double pi = 3.14159;
public:
    Circle() {
        radius = 0.0;
    }
    Circle(double r) {
        radius = r;
    }
    void setRadius(double r) {
        radius = r;
    }
    double getRadius() const {
        return radius;
    }
    double getArea() const {
        return pi * radius * radius;
    }
    double getDiameter() const {
        return radius * 2;
    }
    double getCircumference() const {
        return 2 * pi * radius;
    }
};
int main() {
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    Circle c1(r);
    cout << "Area: " << c1.getArea() << endl;
    cout << "Diameter: " << c1.getDiameter() << endl;
    cout << "Circumference: " << c1.getCircumference() << endl;
    return 0;
}
