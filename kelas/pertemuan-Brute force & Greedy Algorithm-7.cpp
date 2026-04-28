#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

struct Point {
    double x;
    double y;
};

double hitungJarak(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

void cariPasanganTerdekat(const std::vector<Point>& points) {
    int n = points.size();
    if (n < 2) {
        std::cout << "Minimal harus ada 2 titik." << std::endl;
        return;
    }

    double minJarak = std::numeric_limits<double>::max();
    Point pA{};
    Point pB{};

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double jarak = hitungJarak(points[i], points[j]);
            if (jarak < minJarak) {
                minJarak = jarak;
                pA = points[i];
                pB = points[j];
            }
        }
    }

    std::cout << "Pasangan titik terdekat ditemukan:" << std::endl;
    std::cout << "Titik 1: (" << pA.x << ", " << pA.y << ")" << std::endl;
    std::cout << "Titik 2: (" << pB.x << ", " << pB.y << ")" << std::endl;
    std::cout << "Jarak : " << minJarak << std::endl;
}

int main() {
    std::vector<Point> points = {
        {2, 3},
        {12, 30},
        {40, 50},
        {5, 1},
        {12, 10},
        {3, 4}
    };

    std::cout << "Menghitung pasangan titik terdekat." << std::endl << std::endl;
    cariPasanganTerdekat(points);

    return 0;
}