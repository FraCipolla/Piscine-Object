#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Shape.hpp"

int main() {
    Rectangle rectangle(10, 20);
    Triangle triangle(10, 20);
    Circle circle(10);
    Shape *shape = &rectangle;

    std::cout << "Rectangle area: " << shape->get_area() << std::endl;
    std::cout << "Rectangle perimeter: " << shape->get_perimeter() << std::endl;
    shape = &triangle;
    std::cout << "Triangle area: " << shape->get_area() << std::endl;
    std::cout << "Triangle perimeter: " << shape->get_perimeter() << std::endl;
    shape = &circle;
    std::cout << "Circle area: " << shape->get_area() << std::endl;
    std::cout << "Circle perimeter: " << shape->get_perimeter() << std::endl;

    return 0;
}