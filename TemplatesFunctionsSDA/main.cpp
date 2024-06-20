#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <windows.h>   

using namespace std;

// ������ ������� ��� ���������� ���������� ������� ���������� �������
template <typename T>
void fillMatrix(T** matrix, int size)
{
    srand(static_cast<unsigned>(time(0))); // ������������� ���������� ��������� �����

    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            matrix[i][j] = static_cast<T>(rand() % 100); // ���������� ���������� ���������� �� 0 �� 99
            ++j;
        }
        ++i;
    }
}

// ������ ������� ��� ������ ���������� ������� �� �����
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

// ������ ������� ��� ����������� ������������� � ������������ �������� �� ������� ���������
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
    cout << "������� ������ �������: ";
    cin >> size;

    // ������������ ��������� ������ ��� ���������� �������
    int** matrix = new int* [size];
    int i = 0;
    while (i < size)
    {
        matrix[i] = new int[size];
        ++i;
    }

    // ���������� ������� ���������� ����������
    fillMatrix(matrix, size);

    // ����� ������� �� �����
    cout << "�������:" << endl;
    printMatrix(matrix, size);

    // ���������� ������������� � ������������ ��������� �� ������� ���������
    int min, max;
    findMinMaxDiagonal(matrix, size, min, max);
    cout << "����������� ������� �� ������� ���������: " << min << endl;
    cout << "������������ ������� �� ������� ���������: " << max << endl;

    // ������� ������
    i = 0;
    while (i < size)
    {
        delete[] matrix[i];
        ++i;
    }
    delete[] matrix;

    return 0;
}