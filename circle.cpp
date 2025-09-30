#include <iostream>
using namespace std;

// Структура для хранения координат точки
struct Point {
    double x;
    double y;
};

// Структура для хранения данных о круге
struct Circle {
    Point center;  // центр круга (объект типа Point)
    double radius; // радиус круга
};

// Функция считывания данных о круге
void readCircle(Circle& c) {
    cout << "Введите координаты центра (x y): ";
    cin >> c.center.x >> c.center.y;
    cout << "Введите радиус круга: ";
    cin >> c.radius;
}

// Функция вывода информации о круге
void printCircle(const Circle& c) {
    cout << "Центр круга: (" << c.center.x << ", " << c.center.y << ")\n";
    cout << "Радиус круга: " << c.radius << "\n";
}

// Функция вычисления длины окружности
double circleLength(const Circle& c) {
    const double PI = 3.14159265358979323846;
    return 2 * PI * c.radius;
}

// Функция вычисления площади круга
double circleArea(const Circle& c) {
    const double PI = 3.14159265358979323846;
    return PI * c.radius * c.radius;
}

int main() {
    Circle myCircle;
    
    readCircle(myCircle);  // считываем данные
    printCircle(myCircle); // выводим информацию
    
    cout << "Длина окружности: " << circleLength(myCircle) << "\n";
    cout << "Площадь круга: " << circleArea(myCircle) << "\n";
    
    return 0;
}
