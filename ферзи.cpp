#include <iostream>
#include <cmath>
using namespace std;

// Функция для проверки, является ли позиция безопасной для установки ферзя
bool isSafe(int* board, int row, int col, int n) {
    for (int prevRow = 0; prevRow < row; ++prevRow)
    {
        int prevCol = board[prevRow];
        // Проверка, что ферзь не атакует другого ферзя по вертикали или диагонали
        if (prevCol == col || abs(prevCol - col) == abs(prevRow - row)) 
        {
            return false;
        }
    }
    return true;
}

// Рекурсивная функция для решения задачи и вывода всех решений
void solveNQueensUtil(int* board, int row, int n, int& solutionCount) 
{
    if (row == n) 
    {
        // Все ферзи размещены успешно, выводим решение
        cout << "Решение #" << ++solutionCount << ":" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
            {
                if (board[i] == j) 
                {
                    cout << "Q ";
                }
                else 
                {
                    cout << "* ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return; // Возвращаемся, чтобы искать следующее решение
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            // Помещаем ферзя на текущую позицию
            board[row] = col;

            // Рекурсивно пробуем разместить ферзя в следующей строке
            solveNQueensUtil(board, row + 1, n, solutionCount);

            // Если размещение ферзя не привело к решению, откатываемся
            board[row] = -1;  // Помечаем позицию как незанятую
        }
    }
    // Если для текущей строки ни одно размещение не ведет к решению, просто выходим.
}

// Функция для решения задачи
void solveNQueens(int n) {
    int* board = new int[n];
    for (int i = 0; i < n; ++i) {
        board[i] = -1; // Инициализация доски
    }
    int solutionCount = 0;
    solveNQueensUtil(board, 0, n, solutionCount);
    cout << "Всего найдено " << solutionCount << " решений." << endl;
    delete[] board; // Освобождаем память
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n = 8; // Размер доски
    solveNQueens(n);
    return 0;
}