#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
private:
    unsigned int rubles;
    short int kopeks;

    void normalize();

public:
    Money(); 
    Money(unsigned int r, short int k);
    Money(const Money& other);

    void setRubles(unsigned int r);
    void setKopeks(short int k);
    unsigned int getRubles() const { return rubles; }
    short int getKopeks() const { return kopeks; }

    Money addKopeks(unsigned int k);

    Money& operator++();
    Money& operator--();
    
    explicit operator unsigned int() const;
    operator double() const;

    Money operator+(unsigned int k) const;
    Money operator-(unsigned int k) const;

    friend std::ostream& operator<<(std::ostream& os, const Money& m);
};

unsigned int getSafeUintInput(const char* prompt);

#endif