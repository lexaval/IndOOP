//
// Created by Alexey Valeyko on 11.12.2019.
//

#ifndef ALEXEYG_PARKLIST_H
#define ALEXEYG_PARKLIST_H

#include <iostream>
#include <string>
#include "Park.h"


using namespace std;


class ParkList {
friend ostream& operator<< (ostream& out, const ParkList& other);
private:
    int region;
    int count = 1;
public:
    ParkList(int r){
        this->region = r;
    }

    bool operator==(const ParkList& other) { //Перегрузка ==
        return this->region == other.region;
    }

    ParkList& operator++(int value) { //Перегрузка постфиксного инкремента (i++)
        ParkList x(*this);
        this->count += 1;
        return *this;
    }
};


#endif //ALEXEYG_PARKLIST_H
