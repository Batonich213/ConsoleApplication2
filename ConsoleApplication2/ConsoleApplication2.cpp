#include<iostream>
#include<time.h>

/*Создайте двухмерный массив. Заполните его случайными числами и покажите на экран. Пользователь выбирает количество
сдвигов и положение (влево, вправо, вверх, вниз). Выполнить сдвиг массива и показать на экран полученный результат.
Сдвиг циклический.
                 Например, если мы имеем следующий массив
                  1 2 0 4 5 3
                  4 5 3 9 0 1
                  и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
                  5 3 1 2 0 4
                  0 1 4 5 3 9
*/

using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RU");
    const int row = 4, col = 4;

    int mas[row][col], mas2[row][col];
    int course, shift;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mas[i][j] = rand() % 20;
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n\tНаправление сдвига\n"
        << "1. Вправо\n"
        << "2. Влево\n"
        << "3. Вверх\n"
        << "4. Вниз\n\n"
        << "Выберите действие: ";
    cin >> course;

    cout << "Выберите количество сдвигов: ";
    cin >> shift;

    if (course == 1)
    {
        if (shift > col)

        {
            shift %= col;
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (col - shift + j > col - 1)
                {
                    mas2[i][j] = mas[i][j - shift];
                    cout << mas2[i][j] << "\t";
                }

                else
                {
                    mas2[i][j] = mas[i][col - shift + j];
                    cout << mas2[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }


    else if (course == 2)
    {
        // cout << "Выберите количество сдвигов: ";
        // cin >> shift;

        if (shift > col) {
            shift %= col;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (shift + j - col < 0) {
                    mas2[i][j] = mas[i][j + shift];
                    cout << mas2[i][j] << "\t";
                }
                else {
                    mas2[i][j] = mas[i][shift + j - col];
                    cout << mas2[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }
    else if (course == 3)
    {
        // cout << "Выберите количество сдвигов: ";
        // cin >> shift;
        if (shift > row)
        {
            shift %= row;
        }
        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row; i++)
            {
                if (shift + i - row < 0)
                {
                    mas2[i][j] = mas[i + shift][j];
                }
                else
                {
                    mas2[i][j] = mas[shift + i - row][j];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mas2[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else if (course == 4) {
        //  cout << "Выберите количество сдвигов: ";
        // cin >> shift;
        if (shift > row)
        {
            shift %= row;
        }
        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row; i++)
            {
                if (row - shift + i > row - 1)
                {
                    mas2[i][j] = mas[i - shift][j];
                }
                else
                {
                    mas2[i][j] = mas[row - shift + i][j];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mas2[i][j] << "\t";
            }
            cout << endl;
        }
    }

}