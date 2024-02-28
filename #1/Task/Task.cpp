#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

using namespace std;


void tower(int disk, int one, int three, int two)
{

    if (disk != 0)
    {
        tower(disk - 1, one, two, three);
        cout << one << " -> " << three << endl;
        tower(disk - 1, two, three, one);
    }
}

void main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");

    int stolb_1 = 1, stolb_2 = 2, stolb_3 = 3; // столбы
    int disk = 0, counter = 0;
    cout << "Ханойская башня! Сейчас будут выводить перестановки в зависимости от количества дисков!\n" << endl;
    cout << "Введите количество дисков: ";
    cin >> disk;
    tower(disk, stolb_1, stolb_3, stolb_2);
}
