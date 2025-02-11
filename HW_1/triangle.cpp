#include <iostream>
#include <cmath>

// Функция для вычисления расстояния между двумя точками
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    // Ввод координат вершин треугольника
    double x1, y1, x2, y2, x3, y3;
    std::cout << "Введите координаты первой точки через пробел: ";
    std::cin >> x1 >> y1;
    std::cout << "Введите координаты второй точки через пробел: ";
    std::cin >> x2 >> y2;
    std::cout << "Введите координаты третьей точки через пробел: ";
    std::cin >> x3 >> y3;

    // Вычисление длин сторон треугольника
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    // Вычисление полупериметра
    double p = (a + b + c) / 2;

    // Вычисление площади по формуле Герона
    double S = sqrt(p * (p - a) * (p - b) * (p - c));

    // Вычисление периметра
    double P = a + b + c;

    // Вывод результатов
    std::cout << "Площадь треугольника: " << S << std::endl;
    std::cout << "Периметр треугольника: " << P << std::endl;

    return 0;
}