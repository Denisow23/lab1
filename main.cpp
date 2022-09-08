#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>

void initialVector(std::vector<double> &dvector) {
    std::cout << "Количество элементов вектора: " << std::endl;
    int size;
    while (!(std::cin >> size) || (size > 500 || size < 1)){
        std::cout << "Неверно введен размер вектора!" << std::endl;
        std::cin.clear();
        fflush(stdin);
    }
    dvector.reserve(size);
    for (int i = 0; i < size; i++) {
        double value;
        std::cout << "Введите " << (i + 1) << " элемент вектора(в диапазоне между -10000 и 10000): " << std::endl;
        while (!(std::cin >> value) || (value > 10000 || value < -10000)){
            std::cout << "Неверно введено значение вектора!" << std::endl;
            std::cin.clear();
            fflush(stdin);
        }
        dvector.push_back(value);
    }
    for (int i = 0; i < dvector.size(); i++) {
        std::cout << dvector.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
}

void randomInitialVector(std::vector<double> &dvector) {
    std::cout << "Количество элементов вектора: " << std::endl;
    int size;
    while (!(std::cin >> size) || (size > 500 || size < 1)){
        std::cout << "Неверно введен размер вектора!" << std::endl;
        std::cin.clear();
        fflush(stdin);
    }
    dvector.reserve(size);
    for (int i = 0; i < size; i++) {
        double value = rand() % 20000 - 10000;
        dvector.push_back(value);
    }
    for (int i = 0; i < dvector.size(); i++) {
        std::cout << dvector.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
}

void intialMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 1000 - 500;
            std::cout << std::setw(4) <<matrix[i][j] << " ";
        }
        std::cout << "\n" << std::endl;
    }

}

void solution(int **matrix, std::vector<double> dvector, int n, int m) {
    int r;
    double multiply = dvector.at(0);
    std::cout << "Введите r: " << std::endl;
    while (!(std::cin >> r) || (r > dvector.size() || r < 0)){
        std::cout << "Ошибка! Неверное r!" << std::endl;
        std::cin.clear();
        fflush(stdin);
    }
    for (int i = 1; i < r; i++) {
        multiply *= dvector.at(i);
    }
    if (multiply < 0) {
        int max = matrix[1][1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }
        }
        std::cout << "наибольший элемент матрицы: " << max << std::endl;
    } else {
        std::cout << "Результат произведения: " << multiply << std::endl;
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<double> dvector;
    int a;
    std::cout << "1 - создать вектор вручную, 2 - создать вектор рандомно: ";
    std::cin >> a;
    if (a == 1) {
        initialVector(dvector);
    } else if (a == 2) {
        randomInitialVector(dvector);
    } else {
        std::cout << "Ошибка!";
        exit(2);
    }
    int m, n;
    std::cout << "Количество столбцов и строк в матрице: ";
    while (!(std::cin >> m >> n) || (m > 20 ||
             n > 20 ||m < 1 || n < 1)){
        std::cout << "Ошибка размеров матрицы!" << std::endl;
        std::cin.clear();
        fflush(stdin);
    }
    //std::cout << std::endl;
    int **matrix = new int *[m];
    intialMatrix(matrix, m, n);
    solution(matrix, dvector, n, m);

    return 0;
}
