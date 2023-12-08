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
        int s = -1;
        std::string input;
        std::cout << "ADD to add or delete a point, QUIT to quit, EXPORT to export the graph to a PPM file" << std::endl;
        std::cin >> input;
        if (input == "ADD") {
            s = 0;
        } else if (input == "QUIT") {
            s = 1;
        } else if (input == "EXPORT") {
            s = 2;
        } else {
            s = 3;
        }
        switch (s) {
            case 0: {
                std::cout << "please insert a point to add or remove:" << std::endl;
                std::cout << "x: ";
                std::cin >> x;
                while (x < 0 || x > graph.getSize().x) {
                    std::cout << "x must be positive and less than " << graph.getSize().x << std::endl;
                    std::cout << "x: ";
                    std::cin >> x;
                }
                std::cout << "y: ";
                std::cin >> y;
                while (y < 0 || y > graph.getSize().y) {
                    std::cout << "y must be positive and less than " << graph.getSize().y << std::endl;
                    std::cout << "y: ";
                    std::cin >> y;
                }
                graph.addPoint(x, y);
                break;
            }
            case 1:
                return 0;
            case 2:
                std::cout << "please insert the name of the file:" << std::endl;
                std::cin >> input;
                graph.toPPM(input);
                break;
            case 3:
                std::cout << "invalid input" << std::endl;
                break;
        }
    }
}