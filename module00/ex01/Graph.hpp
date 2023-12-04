#pragma once

#include <list>
#include <string>
#include <vector>

class Graph {
    private:
        struct Vector2 {
            float x;
            float y;

            Vector2() : x(0), y(0) {}
            Vector2(float x, float y) : x(x), y(y) {}
            Vector2(const Vector2 &vector) {
                this->x = vector.x;
                this->y = vector.y;
            }
            ~Vector2() {}
            bool operator==(const Vector2 &vector) const {
                return (this->x == vector.x && this->y == vector.y);
            }
            bool operator!=(const Vector2 &vector) const {
                return (this->x != vector.x || this->y != vector.y);
            }
        };
        Vector2 _size;
        std::list<Vector2> _list;
        
        std::vector<std::string> split(std::string str, char delimiter);

    public:
        Graph();
        Graph(std::string filename);
        Graph(Vector2 size);
        Graph(float x, float y);
        Graph(const Graph &graph);
        ~Graph();

        // Getters
        Vector2 getSize() const;
        Vector2 getSize();

        std::list<Vector2> getList() const;
        std::list<Vector2> getList();

        // Setters
        void setSize(Vector2 size);
        void setList(std::list<Vector2> list);

        // Methods
        void addPoint(float x, float y);
        void delPoint(Vector2 point);
        void delPoint(float x, float y);
        void clearPoints();
        bool isPoint(float x, float y);
        void toPPM(std::string filename);
        void printPoints();
};