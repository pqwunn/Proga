#include <iostream>
using namespace std;

// Объявление структуры Point
struct Point {
    double x;  // координата по оси X
    double y;  // координата по оси Y
};

// Функция для считывания координат точки
void readPoint(Point& p) {
    cout << "Введите координату X: ";
    cin >> p.x;
    cout << "Введите координату Y: ";
    cin >> p.y;
}

// Функция для вывода координат точки
void printPoint(const Point& p) {
    cout << "Координаты точки: (" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    // Создаем объект структуры
    Point myPoint;
    
    // Считываем координаты
    readPoint(myPoint);
    
    // Выводим координаты
    printPoint(myPoint);
    
    return 0;
}
