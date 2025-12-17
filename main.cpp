#include <iostream>
#include "Money.h"
using namespace std;

int main() {

    cout << "--- Создание объекта Money ---\n";
    unsigned int r = getSafeUintInput("Введите рубли: ");
    unsigned int k = getSafeUintInput("Введите копейки: ");
    
    Money m1(r, (short int)k);
    cout << "Создан объект: " << m1 << "\n\n";

    unsigned int extraKop = getSafeUintInput("Добавьте копейки: ");
    m1.addKopeks(extraKop);
    cout << "Результат: " << m1 << "\n\n";

    cout << "Добавление 1 копейки (++): ";
    ++m1;
    cout << m1 << "\n";

    cout << "Вычитаение 1 копейки (--): ";
    --m1;
    cout << m1 << "\n\n";

    unsigned int justRubles = (unsigned int)m1;
    double kopeksInRub = m1;
    cout << "Явное приведение к uint (только рубли): " << justRubles << "\n";
    cout << "Неявное приведение к double (только копейки): " << kopeksInRub << "\n\n";

    unsigned int plusKop = getSafeUintInput("Введите копейки для добавления (бинарный +): ");
    Money m2 = m1 + plusKop;
    cout << m1 << " - " << plusKop << " = " << m2 << "\n";

    unsigned int minusKop = getSafeUintInput("Введите копейки для вычитания (бинарный -): ");
    Money m3 = m1 - minusKop;
    cout << m1 << " - " << minusKop << " = " << m3 << "\n";

    return 0;
}