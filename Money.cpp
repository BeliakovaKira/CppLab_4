#include "Money.h"
#include <iostream>
#include <limits>

void Money::normalize() {
    if (kopeks >= 100) {
        rubles += kopeks / 100;
        kopeks %= 100;
    } else if (kopeks < 0) {
        int totalKopeks = rubles * 100 + kopeks;
        if (totalKopeks < 0) totalKopeks = 0;
        rubles = totalKopeks / 100;
        kopeks = totalKopeks % 100;
    }
}

Money::Money() : rubles(0), kopeks(0) {}
Money::Money(unsigned int r, short int k) : rubles(r), kopeks(k) { normalize(); }
Money::Money(const Money& other) : rubles(other.rubles), kopeks(other.kopeks) {}

void Money::setRubles(unsigned int r) { rubles = r; }
void Money::setKopeks(short int k) { kopeks = k; normalize(); }

Money Money::addKopeks(unsigned int k) {
    kopeks += k;
    normalize();
    return *this;
}

Money& Money::operator++() {
    kopeks++;
    normalize();
    return *this;
}

Money& Money::operator--() {
    int total = rubles * 100 + kopeks;
    if (total > 0) {
        kopeks--;
        normalize();
    }
    return *this;
}

Money::operator unsigned int() const { return rubles; }
Money::operator double() const { return (double)kopeks / 100.0; }

Money Money::operator+(unsigned int k) const {
    return Money(rubles, kopeks + k);
}

Money Money::operator-(unsigned int k) const {
    int total = rubles * 100 + kopeks;
    int sub = k;
    if (sub > total) return Money(0, 0);
    return Money(0, total - sub);
}

std::ostream& operator<<(std::ostream& os, const Money& m) {
    os << m.rubles << " руб. " << m.kopeks << " коп.";
    return os;
}

unsigned int getSafeUintInput(const char* prompt) {
    unsigned int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        } else {
            std::cout << "Ошибка! Введите целое неотрицательное число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}