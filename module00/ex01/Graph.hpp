#pragma once

#include <list>

typedef struct Vector2 {
    float x;
    float y;
};

class Graph {
    private:
        Vector2 vec;
        std::list<Vector2> _list;
};