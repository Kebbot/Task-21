#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <iomanip>
#define M 8
using namespace std;
int massX[8] = { 1,2,2,1,-1,-2,-2,-1 };
int massY[8] = { 2,1,-1,-2,-2,-1,1,2 };

void print(int mass[][M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << setw(3) << mass[i][j];
        }
        cout << endl;
    }
}

void horse(int mass[][M], int num, int i0, int j0)
{
    static long long count = 0;
    count++;
    mass[i0][j0] = num++;
    /* print(mass);
     system("pause");*/
    for (int i = 0; i < 8; i++)
    {
        int inew = i0 + massY[i];
        int jnew = j0 + massX[i];

        if (num > M * M)
        {
            print(mass);
            cout << "Количество итераций -> " << count << endl;
            exit(0);
        }
        if (inew<0 || inew>M - 1 || jnew<0 || jnew>M - 1 || mass[inew][jnew] != 0)
            continue;
        horse(mass, num, inew, jnew);
        mass[inew][jnew] = 0;
    }
}




int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");

    int arr[M][M] = {};
    int x = 0, y = 0;
    cout << "Ход Конем! Щас будем ходить... Если программа встала, раскоментируйте комментарии в коде или смените начальную позицию\n" << endl;
    cout << "Введите данные по оси Х (от 0 до 7) -> ";
    cin >> x;
    cout << "Введите данные по оси Y (от 0 до 7) -> ";
    cin >> y;
    horse(arr, 1, y, x);


    return 0;
}
