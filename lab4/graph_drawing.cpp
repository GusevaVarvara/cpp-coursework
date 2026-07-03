#include "graph_drawing.h"
#include <iostream>
#include <fstream>
#include <cmath>

GraphDrawer::GraphDrawer(int width, int height, const std::vector<std::vector<uint8_t>>& image_)
    : image(image_), imageWidth(width), imageHeight(height) {}

void GraphDrawer::drawGraph(const std::vector<Point>& points, const std::vector<std::vector<int>>& adjacencyMatrix) {
    const int vertexRadius = 5; 

    for (size_t i = 0; i < points.size(); ++i) {
        drawVertex(points[i], vertexRadius);
        drawText(Point(points[i].x - 3, points[i].y - 12), std::to_string(i+1));
    }


    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j]) {
                if (i < j) { 
                    drawEdge(points[i], points[j], vertexRadius);
                }
            }
        }
    }

    saveImage("graph.bmp", imageWidth, imageHeight, image);
}

void GraphDrawer::drawVertex(Point center, int radius) {
    if (center.x < radius || center.x >= imageWidth - radius || center.y < radius || center.y >= imageHeight - radius) {
        std::cerr << "Vertex center is out of image bounds." << std::endl;
        return;
    }

    for (int y = -radius; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {
            if (x * x + y * y <= radius * radius) {
                int xPos = static_cast<int>(center.x) + x;
                int yPos = static_cast<int>(center.y) + y;
                image[yPos][xPos] = 0;
            }
        }
    }
}

void GraphDrawer::drawEdge(Point start, Point end, int radius) {
    if (start.x < 0 || start.x >= imageWidth || start.y < 0 || start.y >= imageHeight ||
        end.x < 0 || end.x >= imageWidth || end.y < 0 || end.y >= imageHeight) {
        std::cerr << "Error: Edge coordinates are out of image bounds." << std::endl;
        return;
    }

    double dx = end.x - start.x;
    double dy = end.y - start.y;

    double angle = atan2(dy, dx);

    double x1 = start.x + (radius * cos(angle));
    double y1 = start.y + (radius * sin(angle));
    double x2 = end.x - (radius * cos(angle));
    double y2 = end.y - (radius * sin(angle));

    drawLine(x1, y1, x2, y2);
}

void GraphDrawer::drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        image[y1][x1] = 64;

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


std::vector<std::vector<int>> GraphDrawer::createDigitMatrix(int digit) {
    switch (digit) {
    case 0:
        return { {1, 1, 1},
                {1, 0, 1},
                {1, 0, 1},
                {1, 0, 1},
                {1, 1, 1} };
    case 1:
        return { {0, 1, 0},
                {0, 1, 0},
                {0, 1, 0},
                {0, 1, 0},
                {0, 1, 0} };
    case 2:
        return { {1, 1, 1},
                {0, 0, 1},
                {1, 1, 1},
                {1, 0, 0},
                {1, 1, 1} };
    case 3:
        return { {1, 1, 1},
                {0, 0, 1},
                {1, 1, 1},
                {0, 0, 1},
                {1, 1, 1} };
    case 4:
        return { {1, 0, 1},
                {1, 0, 1},
                {1, 1, 1},
                {0, 0, 1},
                {0, 0, 1} };
    case 5:
        return { {1, 1, 1},
                {1, 0, 0},
                {1, 1, 1},
                {0, 0, 1},
                {1, 1, 1} };
    case 6:
        return { {1, 1, 1},
                {1, 0, 0},
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1} };
    case 7:
        return { {1, 1, 1},
                {0, 0, 1},
                {0, 0, 1},
                {0, 0, 1},
                {0, 0, 1} };
    case 8:
        return { {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1} };
    case 9:
        return { {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1},
                {0, 0, 1},
                {1, 1, 1} };
    default:
        return {};
    }
}

void GraphDrawer::drawText(Point position, const std::string& text) {
    int digitWidth = 3; 
    int digitHeight = 5; 

    Point currentPos = position;

    for (char ch : text) {
        int digit = ch - '0';
        auto digitMatrix = createDigitMatrix(digit);
        drawDigit(currentPos, digitMatrix);
        currentPos.x += digitWidth + 1; 
    }
}

void GraphDrawer::drawDigit(Point position, const std::vector<std::vector<int>>& digitMatrix) {
    for (size_t y = 0; y < digitMatrix.size(); ++y) {
        for (size_t x = 0; x < digitMatrix[y].size(); ++x) {
            int xPos = position.x + x;
            int yPos = position.y + y;
            if (xPos >= 0 && xPos < imageWidth && yPos >= 0 && yPos < imageHeight) {
                image[yPos][xPos] = digitMatrix[y][x] ? 0 : 255; 
            }
        }
    }
}

void GraphDrawer::saveImage(const char* filename, int width, int height, const std::vector<std::vector<uint8_t>>& image) {
    const int headersSize = 54;
    const int imageSize = width * height * 3;
    const int fileSize = headersSize + imageSize;

    std::ofstream file(filename, std::ios::out | std::ios::binary);

    uint8_t header[headersSize] = { 0 };
    header[0] = 'B';
    header[1] = 'M';
    *reinterpret_cast<int*>(&header[2]) = fileSize;
    *reinterpret_cast<int*>(&header[10]) = headersSize;
    *reinterpret_cast<int*>(&header[14]) = 40;
    *reinterpret_cast<int*>(&header[18]) = width;
    *reinterpret_cast<int*>(&header[22]) = height;
    *reinterpret_cast<int*>(&header[26]) = 1;
    *reinterpret_cast<int*>(&header[28]) = 24;

    file.write(reinterpret_cast<const char*>(header), headersSize);

    for (int i = height - 1; i >= 0; --i) {
        for (int j = 0; j < width; ++j) {
            BMPixel pixel;
            pixel.red = image[i][j];
            pixel.green = image[i][j];
            pixel.blue = image[i][j];
            file.write(reinterpret_cast<const char*>(&pixel), sizeof(BMPixel));
        }
    }

    file.close();
}
