#include <iostream>
#include <Windows.h>
#include <stdlib.h>

char* signal;

void signalDisplay() {
    int signalLine = 15;
    signal = new char[signalLine + 1];

    for (int i = 0; i < signalLine; i++) {
        signal[i] = '*';
    }

    signal[signalLine] = '|';

    for (int i = 0; i < signalLine; i++) {
        std::cout << " ";

        if (i == signalLine - 1) {
            std::cout << signal[15];
            break;
        }
    }

    std::cout << "\b";

    for (int i = 0; i < signalLine; i++) {
        std::cout << "\b \b";
    }

    for (int i = 0; i < signalLine; i++) {
        Sleep(100);
        std::cout << "*";
    }

    for (int i = 0; i < signalLine; i++) {
        Sleep(100);
        std::cout << "\b \b";
    }

    delete[] signal;
}

int main()
{
	setlocale(LC_ALL, "ru");

    float timing = 0;
    float result = 0;

    while (true) {
        int i = 0;
        i++;

        std::cout << "Ваше расстояние: " << result << " метров";

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Введите время возврата сигнала: ";
        std::cin >> timing;

        result = (timing * 343) / 2;

        std::cout << "Датчик->";
        signalDisplay();
        system("cls");
    }
}