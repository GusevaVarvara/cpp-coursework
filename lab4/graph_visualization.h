#pragma once

#include <vector>

struct Point {
    double x, y;

    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};

void generateRandomCoordinates(std::vector<Point>& points, int width, int height);
void fruchtermanReingold(std::vector<Point>& points, const std::vector<std::vector<int>>& adjacencyMatrix, int width, int height);

