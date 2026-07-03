#pragma once

#include <vector>
#include <string>
#include "graph_visualization.h"


struct BMPixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

class GraphDrawer {
public:
    GraphDrawer(int width, int height, const std::vector<std::vector<uint8_t>>& image_);
    void drawGraph(const std::vector<Point>& points, const std::vector<std::vector<int>>& adjacencyMatrix);
    void saveImage(const char* filename, int width, int height, const std::vector<std::vector<uint8_t>>& image);

private:
    std::vector<std::vector<uint8_t>> image;
    int imageWidth;
    int imageHeight;

    std::vector<std::vector<int>> createDigitMatrix(int digit);

    void drawVertex(Point center, int radius);
    void drawEdge(Point start, Point end, int radius);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawText(Point position, const std::string& text);
    void drawDigit(Point position, const std::vector<std::vector<int>>& digitMatrix);
};


