#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <windows.h>   

using namespace std;

// Шаблон функции для заполнения квадратной матрицы случайными данными
template <typename T>
void fillMatrix(T** matrix, int size)
{
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            matrix[i][j] = static_cast<T>(rand() % 100); // Заполнение случайными значениями от 0 до 99
            ++j;
        }
        ++i;
    }
}

// Шаблон функции для вывода квадратной матрицы на экран
template <typename T>
void printMatrix(T** matrix, int size)
{
    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            cout << matrix[i][j] << " ";
            ++j;
        }
        cout << endl;
        ++i;
    }
}

// Шаблон функции для определения максимального и минимального элемента на главной диагонали
template <typename T>
void findMinMaxDiagonal(T** matrix, int size, T& min, T& max)
{
    min = matrix[0][0];
    max = matrix[0][0];

    int i = 1;
    while (i < size)
    {
        if (matrix[i][i] < min)
        {
            min = matrix[i][i];
        }
        if (matrix[i][i] > max)
        {
            max = matrix[i][i];
        }
        ++i;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "Введите размер матрицы: ";
    cin >> size;

    // Динамическое выделение памяти для квадратной матрицы
    int** matrix = new int* [size];
    int i = 0;
    while (i < size)
    {
        matrix[i] = new int[size];
        ++i;
    }

    // Заполнение матрицы случайными значениями
    fillMatrix(matrix, size);

    // Вывод матрицы на экран
    cout << "Матрица:" << endl;
    printMatrix(matrix, size);

    // Нахождение максимального и минимального элементов на главной диагонали
    int min, max;
    findMinMaxDiagonal(matrix, size, min, max);
    cout << "Минимальный элемент на главной диагонали: " << min << endl;
    cout << "Максимальный элемент на главной диагонали: " << max << endl;

    // Очистка памяти
    i = 0;
    while (i < size)
    {
        delete[] matrix[i];
        ++i;
    }
    delete[] matrix;

    return 0;
}