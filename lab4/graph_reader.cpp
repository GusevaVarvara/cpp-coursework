#include <iostream>
#include <fstream>
#include <vector>
#include "graph_reader.h"

std::vector<std::vector<int>> readGraph(const std::string& filename, int& V, int& E) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }

    file >> V >> E; 

    if (V <= 0 || E <= 0) {
        std::cerr << "Error: Number of vertices or edges is non-positive" << std::endl;
        exit(1);
    }

    std::vector<std::vector<int>> adjacencyMatrix(V, std::vector<int>(V, 0));

    int u, v;
    int edgeCount = 0;
    for (int i = 0; i < E; ++i) {
        file >> u >> v;

        if (u <= 0 || u > V || v <= 0 || v > V) {
            std::cerr << "Error: Vertex indices are out of range" << std::endl;
            exit(1);
        }
      
        adjacencyMatrix[u - 1][v - 1] = 1; 
        adjacencyMatrix[v - 1][u - 1] = 1; 

        edgeCount++;
    }

    if (file >> u >> v) {
        std::cerr << "Error: Too many edges in the file!" << std::endl;
        exit(1);
    }

    if (edgeCount != E) {
        std::cerr << "Error: Number of edges doesn't match the specified count in the file!" << std::endl;
        exit(1);
    }

    file.close();

    return adjacencyMatrix;
}

