#include <iostream>
using namespace std;

// Структура для хранения координат точки
struct Point {
    double x;
    double y;
};

// Структура для хранения данных о квадрате
struct Square {
    Point topLeft;  // левый верхний угол
    double side;   // длина стороны
};

// Функция считывания данных о квадрате
void readSquare(Square& sq) {
    cout << "Введите координаты левого верхнего угла (x y): ";
    cin >> sq.topLeft.x >> sq.topLeft.y;
    cout << "Введите длину стороны квадрата: ";
    cin >> sq.side;
}

// Функция вывода информации о квадрате
void printSquare(const Square& sq) {
    cout << "Левый верхний угол: (" << sq.topLeft.x << ", " << sq.topLeft.y << ")\n";
    cout << "Длина стороны: " << sq.side << "\n";
}

// Функция периметра
double calculatePerimeter(const Square& sq) {
    return 4 * sq.side;
}

// Функция площади
double calculateArea(const Square& sq) {
    return sq.side * sq.side;
}

int main() {
    Square mySquare;
    
    readSquare(mySquare);  // считывание
    printSquare(mySquare); // вывод
    
    cout << "Периметр квадрата: " << calculatePerimeter(mySquare) << "\n";
    cout << "Площадь квадрата: " << calculateArea(mySquare) << "\n";
    
    return 0;
}
