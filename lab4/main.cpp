#include <iostream>
#include "graph_reader.h"
#include "graph_visualization.h"
#include "graph_drawing.h"
#include <cmath>


int main() {
    int V, E;
    std::vector<std::vector<int>> adjacencyMatrix = readGraph("input.txt", V, E);

    int sideLength = static_cast<int>(std::round(std::sqrt(V)));

    const int width = sideLength * 88;
    const int height = sideLength * 88;
    std::vector<std::vector<uint8_t>> image(height, std::vector<uint8_t>(width, 255)); 

    std::vector<Point> points(V);
    generateRandomCoordinates(points, width, height);
    fruchtermanReingold(points, adjacencyMatrix, width, height);

    GraphDrawer drawer(width, height, image);
    drawer.drawGraph(points, adjacencyMatrix);

    std::cout << "Graph image saved to file graph.bmp" << std::endl;

    return 0;
}


