#include <iostream>
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

// Функция проверки вхождения точки в круг
bool isPointInsideCircle(const Point& p, const Circle& c) {
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    double distanceSquared = dx * dx + dy * dy;
    return distanceSquared < c.radius * c.radius;
}

// Функция проверки вхождения точки в квадрат
bool isPointInsideSquare(const Point& p, const Square& sq) {
    double rightX = sq.topLeft.x + sq.side;
    double bottomY = sq.topLeft.y - sq.side;
    return (p.x > sq.topLeft.x && p.x < rightX &&
            p.y > bottomY && p.y < sq.topLeft.y);
}

// Функции считывания и вывода
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

void printPoint(const Point& p) {
    cout << "Точка: (" << p.x << ", " << p.y << ")\n";
}

void printCircle(const Circle& c) {
    cout << "Круг: центр (" << c.center.x << ", " << c.center.y << "), радиус " << c.radius << "\n";
}

void printSquare(const Square& sq) {
    cout << "Квадрат: левый верхний угол (" << sq.topLeft.x << ", " << sq.topLeft.y << "), сторона " << sq.side << "\n";
}

int main() {
    Point testPoint;
    Circle myCircle;
    Square mySquare;

    // Считываем данные
    readPoint(testPoint);
    readCircle(myCircle);
    readSquare(mySquare);

    // Выводим данные
    printPoint(testPoint);
    printCircle(myCircle);
    printSquare(mySquare);

    // Проверяем вхождение точки
    if (isPointInsideCircle(testPoint, myCircle)) {
        cout << "Точка находится внутри круга\n";
    } else {
        cout << "Точка не находится внутри круга\n";
    }

    if (isPointInsideSquare(testPoint, mySquare)) {
        cout << "Точка находится внутри квадрата\n";
    } else {
        cout << "Точка не находится внутри квадрата\n";
    }

    return 0;
}
