#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>



void initialVector(std::vector<int> &dvector) { // инициализация вектора посредством стандартного потока ввода
    std::cout << "Количество элементов вектора: " << std::endl;
    int size; // размер вектора
    while (!(std::cin >> size) || (size > 10 || size < 1)){ // отработка исключения
        std::cout << "Неверно введен размер вектора!" << std::endl;
        std::cin.clear(); //очистка потока ввода
        fflush(stdin);
    }
    dvector.reserve(size);
    for (int i = 0; i < size; i++) {
        double value;// значение элемента вектора
        std::cout << "Введите " << (i + 1) << " элемент вектора(в диапазоне между -70 и 70): " << std::endl;
        while (!(std::cin >> value) || (value > 70 || value < -70)){
            std::cout << "Неверно введено значение вектора!" << std::endl;
            std::cin.clear();
            fflush(stdin);
        }
        dvector.push_back(value);// добавление элемента вектора
    }
    for (int i = 0; i < dvector.size(); i++) {// вывод вектора
        std::cout << std::setw(3) << dvector.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
}

void randomInitialVector(std::vector<int> &dvector) {// случайная инициализация вектора
    std::cout << "Количество элементов вектора: " << std::endl;
    int size;
    while (!(std::cin >> size) || (size > 10 || size < 1)){
        std::cout << "Неверно введен размер вектора!" << std::endl;
        std::cin.clear();
        fflush(stdin);
    }
    dvector.reserve(size);
    srand(time(NULL));//предотвращение генерации одинаковых случайных чисел
    for (int i = 0; i < size; i++) {

        double value = rand() % 140-70;// генератор в диапазоне от -13 до 13
        dvector.push_back(value);
    }
    for (int i = 0; i < dvector.size(); i++) {
        std::cout << std::setw(3) << dvector.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
}

void intialMatrix(int **matrix, int m, int n) {// инициализация матрицы
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 1000 - 500;// диапазон значений матрицы от -500 до 500
            std::cout << std::setw(4) <<matrix[i][j] << " ";
        }
        std::cout << "\n" << std::endl;
    }

}

void solution(int **matrix, std::vector<int> dvector, int n, int m) {
    int r;
    long long multiply = dvector.at(0);
    std::cout << "Введите r: " << std::endl;
    while (!(std::cin >> r) || (r > dvector.size() || r < 0)){
        std::cout << "Ошибка! Неверное r!" << std::endl;
        std::cin.clear();
        fflush(stdin);
    }
    for (int i = 1; i < r; i++) {// процедура нахождения результата умножения
        multiply *= dvector.at(i);
    }
    if (multiply < 0) {// если multiply < 0 ищем максимум матрицы, иначе выводим значение multiply
        int max = matrix[0][0];
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
    std::vector<int> dvector;
    char vopros = 'y';
    std::cout << "Денисов Даниил Алексеевич. Группа А-17-21."
                 "Лабораторня работа №1. Динамические массивы" << std::endl;
    while (vopros == 'y') {
        int a;
        std::cout
                << "1 - создать вектор вручную, 2 - создать вектор рандомно: ";//в диалоге выбираем способ инициализации вектора
        std::cin >> a;
        if (a == 1) {
            initialVector(dvector);
        } else if (a == 2) {
            randomInitialVector(dvector);
        } else {
            std::cout << "Ошибка!";
            exit(2);//отработка исключения -> выход с кодом ошибки 2
        }
        int m, n;
        std::cout << "Количество столбцов и строк в матрице: ";
        while (!(std::cin >> m >> n) || (m > 5 ||
                                         n > 5 || m < 1 || n < 1)) {
            std::cout << "Ошибка размеров матрицы!" << std::endl;
            std::cin.clear();
            fflush(stdin);
        }
        int **matrix = new int *[m];            // создаем матрицу, но не удаляем,
        intialMatrix(matrix, m, n);             // тк не имеет смысла:
        solution(matrix, dvector, n, m);        // матрица нужна нам до самой последней функции
        std::cout << "Хотите ли вы продолжить? "// после окончания программы все данные пропадут автоматически
                     "(y - yes; n - no)" << std::endl;// после окончания программы все данные пропадут автоматически
        while (!(std::cin >> vopros) || (vopros != 'y'
                && vopros != 'n')){
            std::cout << "Ошибка ответа! (y - yes; n - no)" << std::endl;
            std::cin.clear();
            fflush(stdin);
        }
        if (vopros == 'y') {
            dvector.clear();
        }
    }
    return 0;
}
