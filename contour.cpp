#include <iostream>
#include <cmath>  // для std::abs
using namespace std;

// Структура для хранения координат точки
struct Point {
    double x;
    double y;
};

// Структура для хранения данных о круге
struct Circle {
    Point center;  // центр круга
    double radius;  // радиус круга
};

// Структура для хранения данных о квадрате
struct Square {
    Point topLeft;  // левый верхний угол
    double side;  // длина стороны
};

// Функция проверки нахождения точки на окружности
bool isPointOnCircle(const Point& p, const Circle& c, double epsilon = 1e-5) {
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    double distanceSquared = dx * dx + dy * dy;
    double radiusSquared = c.radius * c.radius;
    return std::abs(distanceSquared - radiusSquared) < epsilon;
}

// Функция проверки нахождения точки на контуре квадрата
bool isPointOnSquare(const Point& p, const Square& sq, double epsilon = 1e-5) {
    double rightX = sq.topLeft.x + sq.side;
    double bottomY = sq.topLeft.y - sq.side;
    
    // Проверка горизонтальных рёбер
    bool onHorizontalEdge = 
        (std::abs(p.y - sq.topLeft.y) < epsilon || std::abs(p.y - bottomY) < epsilon) &&
        (p.x >= sq.topLeft.x - epsilon && p.x <= rightX + epsilon);
    
    // Проверка вертикальных рёбер
    bool onVerticalEdge = 
        (std::abs(p.x - sq.topLeft.x) < epsilon || std::abs(p.x - rightX) < epsilon) &&
        (p.y >= bottomY - epsilon && p.y <= sq.topLeft.y + epsilon);
    
    return onHorizontalEdge || onVerticalEdge;
}

// Вспомогательные функции ввода/вывода
void readPoint(Point& p) {
    cout << "Введите координаты точки (x y): ";
    cin >> p.x >> p.y;
}

void readCircle(Circle& c) {
    cout << "Введите координаты центра круга (x y): ";
    cin >> c.center.x >> c.center.y;
    cout << "Введите радиус круга: ";
    cin >> c.radius;
}

void readSquare(Square& sq) {
    cout << "Введите координаты левого верхнего угла квадрата (x y): ";
    cin >> sq.topLeft.x >> sq.topLeft.y;
    cout << "Введите длину стороны квадрата: ";
    cin >> sq.side;
}

int main() {
    Point testPoint;
    Circle myCircle;
    Square mySquare;
    
    // Считываем данные
    readPoint(testPoint);
    readCircle(myCircle);
    readSquare(mySquare);
    
    // Проверяем принадлежность точки контурам фигур
    if (isPointOnCircle(testPoint, myCircle)) {
        cout << "Точка лежит на окружности круга\n";
    } else {
        cout << "Точка не лежит на окружности круга\n";
    }
    
    if (isPointOnSquare(testPoint, mySquare)) {
        cout << "Точка лежит на контуре квадрата\n";
    } else {
        cout << "Точка не лежит на контуре квадрата\n";
    }
    
    return 0;
}
