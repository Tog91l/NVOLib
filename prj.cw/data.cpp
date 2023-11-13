#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <filesystem>

struct Arc {
    double azim, inclin;
};

struct Vector {
    double x, y;
};

struct Point {
    double x, y;
};

double randomRange(double min, double max) {
    return min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX) / (max - min));
}

void generateData(const std::string& dataType, const std::string& containerType, int numData, const std::string& folderPath) {
    if (!std::filesystem::exists(folderPath)) {
        std::filesystem::create_directory(folderPath);
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    if (dataType == "arcs") {
        if (containerType == "vector") {
            std::vector<Arc> dataVector;
            for (int i = 0; i < numData; ++i) {
                double azim = randomRange(0.0, 2.0 * std::acos(-1.0));
                double inclin = randomRange(0.0, std::asin(-1.0));
                dataVector.emplace_back(Arc{azim, inclin});
            }

            std::ofstream arcsVectorFile(folderPath + "/arcsVector.txt");
            for (const auto& arc : dataVector) {
                arcsVectorFile << "(" << arc.azim << ", " << arc.inclin << ")" << std::endl;
            }
            arcsVectorFile.close();
        } else if (containerType == "list") {
            std::list<Arc> dataList;
            for (int i = 0; i < numData; ++i) {
                double azim = randomRange(0.0, 2.0 * std::acos(-1.0));
                double inclin = randomRange(0.0, std::asin(-1.0));
                dataList.emplace_back(Arc{azim, inclin});
            }

            std::ofstream arcsListFile(folderPath + "/arcsList.txt");
            for (const auto& arc : dataList) {
                arcsListFile << "(" << arc.azim << ", " << arc.inclin << ")" << std::endl;
            }
            arcsListFile.close();
        } else if (containerType == "deque") {
            std::deque<Arc> dataDeque;
            for (int i = 0; i < numData; ++i) {
                double azim = randomRange(0.0, 2.0 * std::acos(-1.0));
                double inclin = randomRange(0.0, std::asin(-1.0));
                dataDeque.emplace_back(Arc{azim, inclin});
            }

            std::ofstream arcsDequeFile(folderPath + "/arcsDeque.txt");
            for (const auto& arc : dataDeque) {
                arcsDequeFile << "(" << arc.azim << ", " << arc.inclin << ")" << std::endl;
            }
            arcsDequeFile.close();
        }
    } else if (dataType == "vectors") {
        if (containerType == "vector") {
            std::vector<Vector> dataVector;
            for (int i = 0; i < numData; ++i) {
                double x = randomRange(0.0, 1.0);
                double y = randomRange(0.0, 1.0);
                dataVector.emplace_back(Vector{x, y});
            }

            std::ofstream vectorsVectorFile(folderPath + "/vectorsVector.txt");
            for (const auto& vec : dataVector) {
                vectorsVectorFile << "(" << vec.x << " " << vec.y << ")" << std::endl;
            }
            vectorsVectorFile.close();
        } else if (containerType == "list") {
            std::list<Vector> dataList;
            for (int i = 0; i < numData; ++i) {
                double x = randomRange(0.0, 1.0);
                double y = randomRange(0.0, 1.0);
                dataList.emplace_back(Vector{x, y});
            }

            std::ofstream vectorsListFile(folderPath + "/vectorsList.txt");
            for (const auto& vec : dataList) {
                vectorsListFile << "(" << vec.x << " " << vec.y << ")" << std::endl;
            }
            vectorsListFile.close();
        } else if (containerType == "deque") {
            std::deque<Vector> dataDeque;
            for (int i = 0; i < numData; ++i) {
                double x = randomRange(0.0, 1.0);
                double y = randomRange(0.0, 1.0);
                dataDeque.emplace_back(Vector{x, y});
            }

            std::ofstream vectorsDequeFile(folderPath + "/vectorsDeque.txt");
            for (const auto& vec : dataDeque) {
                vectorsDequeFile << "(" << vec.x << " " << vec.y << ")" << std::endl;
            }
            vectorsDequeFile.close();
        }
    } else if (dataType == "points") {
        if (containerType == "vector") {
            std::vector<Point> dataVector;
            for (int i = 0; i < numData; ++i) {
                double x = randomRange(0.0, 1.0);
                double y = randomRange(0.0, 1.0);
                dataVector.emplace_back(Point{x, y});
            }

            std::ofstream pointsVectorFile(folderPath + "/pointsVector.txt");
            for (const auto& point : dataVector) {
                pointsVectorFile << "(" << point.x << " " << point.y << ")" << std::endl;
            }
            pointsVectorFile.close();
        } else if (containerType == "list") {
            std::list<Point> dataList;
            for (int i = 0; i < numData; ++i) {
                double x = randomRange(0.0, 1.0);
                double y = randomRange(0.0, 1.0);
                dataList.emplace_back(Point{x, y});
            }

            std::ofstream pointsListFile(folderPath + "/pointsList.txt");
            for (const auto& point : dataList) {
                pointsListFile << "(" << point.x << " " << point.y << ")" << std::endl;
            }
            pointsListFile.close();
        } else if (containerType == "deque") {
            std::deque<Point> dataDeque;
            for (int i = 0; i < numData; ++i) {
                double x = randomRange(0.0, 1.0);
                double y = randomRange(0.0, 1.0);
                dataDeque.emplace_back(Point{x, y});
            }

            std::ofstream pointsDequeFile(folderPath + "/pointsDeque.txt");
            for (const auto& point : dataDeque) {
                pointsDequeFile << "(" << point.x << " " << point.y << ")" << std::endl;
            }
            pointsDequeFile.close();
        }
    }
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    std::string dataType;
    std::string containerType;
    int numData;

    std::cout << "Введите тип данных (arcs, vectors, points): ";
    std::cin >> dataType;

    std::cout << "Введите тип контейнера (vector, list, deque): ";
    std::cin >> containerType;

    std::cout << "Введите количество данных: ";
    std::cin >> numData;

    std::string folderPath = "data";

    generateData(dataType, containerType, numData, folderPath);
    std::cout << "Данные успешно сгенерированы и сохранены в папку data." << std::endl;

    return 0;
}

