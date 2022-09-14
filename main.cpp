#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>



void initialVector(std::vector<int> &dvector) { // ������������� ������� ����������� ������������ ������ �����
    std::cout << "���������� ��������� �������: " << std::endl;
    int size; // ������ �������
    while (!(std::cin >> size) || (size > 10 || size < 1)){ // ��������� ����������
        std::cout << "������� ������ ������ �������!" << std::endl;
        std::cin.clear(); //������� ������ �����
        fflush(stdin);
    }
    dvector.reserve(size);
    for (int i = 0; i < size; i++) {
        double value;// �������� �������� �������
        std::cout << "������� " << (i + 1) << " ������� �������(� ��������� ����� -70 � 70): " << std::endl;
        while (!(std::cin >> value) || (value > 70 || value < -70)){
            std::cout << "������� ������� �������� �������!" << std::endl;
            std::cin.clear();
            fflush(stdin);
        }
        dvector.push_back(value);// ���������� �������� �������
    }
    for (int i = 0; i < dvector.size(); i++) {// ����� �������
        std::cout << std::setw(3) << dvector.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
}

void randomInitialVector(std::vector<int> &dvector) {// ��������� ������������� �������
    std::cout << "���������� ��������� �������: " << std::endl;
    int size;
    while (!(std::cin >> size) || (size > 10 || size < 1)){
        std::cout << "������� ������ ������ �������!" << std::endl;
        std::cin.clear();
        fflush(stdin);
    }
    dvector.reserve(size);
    srand(time(NULL));//�������������� ��������� ���������� ��������� �����
    for (int i = 0; i < size; i++) {

        double value = rand() % 140-70;// ��������� � ��������� �� -13 �� 13
        dvector.push_back(value);
    }
    for (int i = 0; i < dvector.size(); i++) {
        std::cout << std::setw(3) << dvector.at(i) << " ";
    }
    std::cout << "\n" << std::endl;
}

void intialMatrix(int **matrix, int m, int n) {// ������������� �������
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 1000 - 500;// �������� �������� ������� �� -500 �� 500
            std::cout << std::setw(4) <<matrix[i][j] << " ";
        }
        std::cout << "\n" << std::endl;
    }

}

void solution(int **matrix, std::vector<int> dvector, int n, int m) {
    int r;
    long long multiply = dvector.at(0);
    std::cout << "������� r: " << std::endl;
    while (!(std::cin >> r) || (r > dvector.size() || r < 0)){
        std::cout << "������! �������� r!" << std::endl;
        std::cin.clear();
        fflush(stdin);
    }
    for (int i = 1; i < r; i++) {// ��������� ���������� ���������� ���������
        multiply *= dvector.at(i);
    }
    if (multiply < 0) {// ���� multiply < 0 ���� �������� �������, ����� ������� �������� multiply
        int max = matrix[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }
        }
        std::cout << "���������� ������� �������: " << max << std::endl;
    } else {
        std::cout << "��������� ������������: " << multiply << std::endl;
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<int> dvector;
    char vopros = 'y';
    std::cout << "������� ������ ����������. ������ �-17-21."
                 "����������� ������ �1. ������������ �������" << std::endl;
    while (vopros == 'y') {
        int a;
        std::cout
                << "1 - ������� ������ �������, 2 - ������� ������ ��������: ";//� ������� �������� ������ ������������� �������
        std::cin >> a;
        if (a == 1) {
            initialVector(dvector);
        } else if (a == 2) {
            randomInitialVector(dvector);
        } else {
            std::cout << "������!";
            exit(2);//��������� ���������� -> ����� � ����� ������ 2
        }
        int m, n;
        std::cout << "���������� �������� � ����� � �������: ";
        while (!(std::cin >> m >> n) || (m > 5 ||
                                         n > 5 || m < 1 || n < 1)) {
            std::cout << "������ �������� �������!" << std::endl;
            std::cin.clear();
            fflush(stdin);
        }
        int **matrix = new int *[m];            // ������� �������, �� �� �������,
        intialMatrix(matrix, m, n);             // �� �� ����� ������:
        solution(matrix, dvector, n, m);        // ������� ����� ��� �� ����� ��������� �������
        std::cout << "������ �� �� ����������? "// ����� ��������� ��������� ��� ������ �������� �������������
                     "(y - yes; n - no)" << std::endl;// ����� ��������� ��������� ��� ������ �������� �������������
        while (!(std::cin >> vopros) || (vopros != 'y'
                && vopros != 'n')){
            std::cout << "������ ������! (y - yes; n - no)" << std::endl;
            std::cin.clear();
            fflush(stdin);
        }
        if (vopros == 'y') {
            dvector.clear();
        }
    }
    return 0;
}
