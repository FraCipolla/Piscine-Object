#include "Graph.hpp"

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>

Graph::Graph() : _size(0, 0) {}
Graph::Graph(const Graph &graph) {
    this->_size = graph._size;
    this->_list = graph._list;
}
Graph::Graph(Vector2 size) : _size(size) {}
Graph::Graph(float x, float y) : _size(x, y) {}
Graph::Graph(std::string filename) {
    try {
        std::ifstream file(filename.c_str());
        if (!file.is_open()) throw std::exception();
        std::string line;
        std::getline(file, line);
        if (line.empty()) throw std::exception();
        if (line.find("size") == std::string::npos) throw std::exception();
        std::string size = line.substr(line.find("size") + 6, line.size() - 1);
        std::stringstream ss(size.substr(0, size.find(",")));
        ss >> this->_size.x;
        ss.clear();
        ss.str(size.substr(size.find(",") + 1, size.size()));
        ss >> this->_size.y;
        std::cout << this->_size.x << " " << this->_size.y << std::endl;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            std::vector<std::string> tokens = this->split(line, '}');
            for (std::vector<std::string>::iterator it = tokens.begin();
                 it != tokens.end(); it++) {
                std::string token = it->substr(it->find("{") + 1, it->size());
                std::stringstream ss(token.substr(0, token.find(",")));
                float x;
                ss >> x;
                ss.clear();
                ss.str(token.substr(token.find(",") + 1, token.size() - 1));
                float y;
                ss >> y;
                this->addPoint(x, y);
            }
        }
        file.close();
        this->printPoints();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

Graph::~Graph() {}

// Getters
Graph::Vector2 Graph::getSize() const { return this->_size; }
Graph::Vector2 Graph::getSize() { return this->_size; }
std::list<Graph::Vector2> Graph::getList() const { return this->_list; }
std::list<Graph::Vector2> Graph::getList() { return this->_list; }

// Setters
void Graph::setSize(Vector2 size) { this->_size = size; }
void Graph::setList(std::list<Vector2> list) { this->_list = list; }

// Methods
void Graph::addPoint(float x, float y) {
    for (std::list<Vector2>::iterator it = this->_list.begin();
         it != this->_list.end(); it++) {
        if (it->x == x && it->y == y)  {
            this->_list.erase(it);
            return;
        }
    }
    this->_list.push_back(Vector2(x, y));
}

std::vector<std::string> Graph::split(std::string str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);
    while (std::getline(ss, token, delimiter)) tokens.push_back(token);
    return tokens;
}

void Graph::delPoint(Vector2 point) {
    for (std::list<Vector2>::iterator it = this->_list.begin();
         it != this->_list.end(); it++) {
        if (*it == point) {
            this->_list.erase(it);
            return;
        }
    }
}
void Graph::delPoint(float x, float y) {
    for (std::list<Vector2>::iterator it = this->_list.begin();
         it != this->_list.end(); it++) {
        if (it->x == x && it->y == y) {
            this->_list.erase(it);
            return;
        }
    }
}
void Graph::clearPoints() { this->_list.clear(); }

bool Graph::isPoint(float x, float y) {
    for (std::list<Vector2>::iterator it = this->_list.begin();
         it != this->_list.end(); it++) {
        if (it->x == x && it->y == y) return true;
    }
    return false;
}

void Graph::printPoints() {
    for (int i = 0; i < this->_size.y; i++) {
        std::cout << ">& " << this->_size.y - (i + 1) << " ";
        for (int j = 0; j < this->_size.x; j++) {
            if (this->isPoint(j, this->_size.x - (i))) {
                std::cout << "X ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << ">&   ";
    for (int i = 0; i < this->_size.x; i++) std::cout << i << " ";
    std::cout << std::endl;
}