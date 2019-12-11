//
// Created by Alexey Valeyko on 04.12.2019.
//

#ifndef ALEXEY_PARK_H
#define ALEXEY_PARK_H
#include <string>
#include <iostream>
#include "ParkList.h"

using namespace std;

class Park{
    friend istream& operator>>(istream& in, Park& other);
    friend ostream& operator<< (ostream& out, const Park& other);
private:
    string firstName, lastName;
    string number;
    int region;
    int route;
public:
    Park(){     //Конструктор
        firstName = "NULL";
        lastName = "NULL";
        region = 0;
        route = 0;
        number = "NULL";
    }

    Park(string ln, string fn, string num, int reg, int rt){    //Конструктор с параметрами
        firstName = fn;
        lastName = ln;
        number = num;
        region = reg;
        route = rt;
    }

    Park(const Park& other){    //Конструктор копирования
        this-> firstName = other.firstName;
        this-> lastName = other.lastName;
        this-> number = other.number;
        this-> region = other.region;
        this-> route = other.route;
    }

    Park& operator=(const Park& other) {    //Оператор копирования
        this-> firstName = other.firstName;
        this-> lastName = other.lastName;
        this-> number = other.number;
        this-> region = other.region;
        this-> route = other.route;
        return *this;
    }
//Перегрузки сравнительных операторов
    bool operator >(const Park& other) {
        return this->route > other.route;
    }

    bool operator <(const Park& other) {
        return this->route < other.route;
    }

    bool operator >=(const Park& other) {
        return this->route >= other.route;
    }

    bool operator <=(const Park& other) {
        return this->route <= other.route;
    }

    int getReg(){
        return region;
    }
    ~Park() { //Деструктор

    }
}  ;


#endif //ALEXEYG_PARK_H
