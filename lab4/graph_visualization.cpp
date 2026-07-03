#include "graph_visualization.h"
#include <cmath>
#include <random>

const int vertexRadius = 5;
const double minVertexDistance = 30;

int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}

void generateRandomCoordinates(std::vector<Point>& points, int width, int height) {

    for (int i = 0; i < points.size(); ++i) {
        points[i].x = getRandomNumber(vertexRadius, width - vertexRadius);
        points[i].y = getRandomNumber(vertexRadius, height - vertexRadius);
    }
}


double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void fruchtermanReingold(std::vector<Point>& points, const std::vector<std::vector<int>>& adjacencyMatrix, int width, int height) {
    const int numVertices = points.size();

    const double k5Vertices = 0.5;
    const double c5Vertices = 0.005;
    const int maxIterFor5Vertices = 100;

    const double kFor500Vertices = 2.0;
    const double cFor500Vertices = 0.06;
    const int maxIterFor500Vertices = 300;

    double alpha = static_cast<double>(numVertices - 5) / (500 - 5);
    double k = k5Vertices + alpha * (kFor500Vertices - k5Vertices);
    double c = c5Vertices + alpha * (cFor500Vertices - c5Vertices);
    int maxIterations = maxIterFor5Vertices + static_cast<int>(alpha * (maxIterFor500Vertices - maxIterFor5Vertices));

    for (int iter = 0; iter < maxIterations; ++iter) {
        std::vector<Point> repulsiveForces(numVertices, Point(0, 0));
        std::vector<Point> attractiveForces(numVertices, Point(0, 0));

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (i != j) {
                    double d = distance(Point(points[i].x, points[i].y), Point(points[j].x, points[j].y));
                    double force = k * k / d;

                    repulsiveForces[i].x += force * (points[i].x - points[j].x) / d;
                    repulsiveForces[i].y += force * (points[i].y - points[j].y) / d;

                    if (adjacencyMatrix[i][j]) {
                        attractiveForces[i].x += c * (points[j].x - points[i].x);
                        attractiveForces[i].y += c * (points[j].y - points[i].y);
                    }
                }
            }
        }

        for (int i = 0; i < numVertices; ++i) {
            points[i].x += repulsiveForces[i].x + attractiveForces[i].x;
            points[i].y += repulsiveForces[i].y + attractiveForces[i].y;

            for (int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j]) {
                    double dist = distance(points[i], points[j]);
                    if (dist < minVertexDistance) {
                        if (points[i].x < points[j].x)
                            points[i].x -= minVertexDistance;
                        else
                            points[i].x += minVertexDistance;
                    }
                }
            }

            if (points[i].x < vertexRadius) {
                points[i].x = vertexRadius;
            }
            else if (points[i].x > width - vertexRadius) {
                points[i].x = width - vertexRadius;
            }

            if (points[i].y < vertexRadius) {
                points[i].y = vertexRadius;
            }
            else if (points[i].y > height - vertexRadius) {
                points[i].y = height - vertexRadius;
            }

        }
    }
}
