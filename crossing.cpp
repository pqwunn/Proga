#include <iostream>
#include <cmath> // для std::abs
using namespace std;

// Структура для хранения координат точки
struct Point {
    double x;
    double y;
};

// Структура для хранения данных о круге
struct Circle {
    Point center; // центр круга
    double radius; // радиус круга
};

// Структура для хранения данных о квадрате
struct Square {
    Point topLeft; // левый верхний угол
    double side; // длина стороны
};

// Проверка точки на окружности
bool isPointOnCircle(const Point& p, const Circle& c, double epsilon = 1e-5) {
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    double distanceSquared = dx * dx + dy * dy;
    double radiusSquared = c.radius * c.radius;
    return std::abs(distanceSquared - radiusSquared) < epsilon;
}

// Проверка точки на контуре квадрата
bool isPointOnSquare(const Point& p, const Square& sq, double epsilon = 1e-5) {
    double rightX = sq.topLeft.x + sq.side;
    double bottomY = sq.topLeft.y - sq.side;
    
    bool onHorizontalEdge = 
        (std::abs(p.y - sq.topLeft.y) < epsilon || std::abs(p.y - bottomY) < epsilon) &&
        (p.x >= sq.topLeft.x - epsilon && p.x <= rightX + epsilon);
    
    bool onVerticalEdge = 
        (std::abs(p.x - sq.topLeft.x) < epsilon || std::abs(p.x - rightX) < epsilon) &&
        (p.y >= bottomY - epsilon && p.y <= sq.topLeft.y + epsilon);
    
    return onHorizontalEdge || onVerticalEdge;
}

// Пересечение двух кругов
bool circlesIntersect(const Circle& c1, const Circle& c2) {
    double dx = c1.center.x - c2.center.x;
    double dy = c1.center.y - c2.center.y;
    double distanceSquared = dx * dx + dy * dy;
    double radiiSumSquared = (c1.radius + c2.radius) * (c1.radius + c2.radius);
    return distanceSquared <= radiiSumSquared;
}

// Пересечение двух квадратов
bool squaresIntersect(const Square& s1, const Square& s2, double epsilon = 1e-5) {
    double s1_rightX = s1.topLeft.x + s1.side;
    double s1_bottomY = s1.topLeft.y - s1.side;
    double s2_rightX = s2.topLeft.x + s2.side;
    double s2_bottomY = s2.topLeft.y - s2.side;
    
    if (s1.topLeft.x > s2_rightX + epsilon || s2.topLeft.x > s1_rightX + epsilon)
        return false; // нет пересечения по оси X
    if (s1.topLeft.y < s2_bottomY - epsilon || s2.topLeft.y < s1_bottomY - epsilon)
        return false; // нет пересечения по оси Y
    
    return true;
}

// Пересечение круга и квадрата
bool circleAndSquareIntersect(const Circle& c, const Square& s, double epsilon = 1e-5) {
    if (isPointOnSquare(c.center, s, epsilon))
        return true;
    
    Point vertices[4] = {
        s.topLeft,
        {s.topLeft.x + s.side, s.topLeft.y},
        {s.topLeft.x + s.side, s.topLeft.y - s.side},
        {s.topLeft.x, s.topLeft.y - s.side}
    };
    
    for (size_t i = 0; i < 4; ++i) {
        if (isPointOnCircle(vertices[i], c, epsilon))
            return true;
    }
    
    return false;
}

int main() {
    Circle c1 = {{0, 0}, 5};
    Circle c2 = {{7, 0}, 3};
    Square s1 = {{2, 3}, 4};
    Square s2 = {{5, 5}, 3};
    
    cout << "Круги пересекаются: " << (circlesIntersect(c1, c2) ? "Да" : "Нет") << endl;
    cout << "Квадраты пересекаются: " << (squaresIntersect(s1, s2) ? "Да" : "Нет") << endl;
    cout << "Круг и квадрат пересекаются: " << (circleAndSquareIntersect(c1, s1) ? "Да" : "Нет") << endl;
    
    return 0;
}
