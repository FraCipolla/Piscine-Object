#include "Graph.hpp"

#include <iostream>
#include <istream>
#include <fstream>
#include <string>


int main(int argc, char **argv)
{
    if (argc == 2) {
        Graph graph(argv[1]);
        return 0;
    }
    std::cout << "please insert the size of the graph:" << std::endl;
    std::cout << "x: ";
    float x, y;
    std::cin >> x;
    while (x < 0) {
        std::cout << "x must be positive" << std::endl;
        std::cout << "x: ";
        std::cin >> x;
    }
    std::cout << "y: ";
    std::cin >> y;
    while (y < 0) {
        std::cout << "y must be positive" << std::endl;
        std::cout << "y: ";
        std::cin >> y;
    }

    Graph graph(x, y);

    for (;;) {
        graph.printPoints();
        graph.toPPM("graph.ppm");
        std::cout << "please insert a point to add or remove:" << std::endl;
        std::cout << "x: ";
        std::cin >> x;
        while (x < 0) {
            std::cout << "x must be positive" << std::endl;
            std::cout << "x: ";
            std::cin >> x;
        }
        std::cout << "y: ";
        std::cin >> y;
        while (y < 0) {
            std::cout << "y must be positive" << std::endl;
            std::cout << "y: ";
            std::cin >> y;
        }
        graph.addPoint(x, y);
    }
}