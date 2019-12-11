#include <iostream>
#include <string>
#include <fstream>
#include "Park.h"
#include "ParkList.h"
#include <list>
#include <iterator>

using namespace std;

template <class T>
T findMax(T* a, int N) {
    T max;
    for (int i = 0; i < N; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

template<class T>
T findMin(T* a, int N) {
    T min = a[0];
    for (int i = 0; i < N; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

template<class T>
void sort(T* a, int n) {
    T x;
    int key = 0;
    for (int i = 0; i < n - 1; i++) {
        key = i + 1;
        x = a[key];
        for (int j = i + 1; j > 0; j--){
            if (x < a[j-1]){
                a[j] = a[j-1];
                key = j-1;
            }
        }
        a[key] = x;
    }
}

ostream& operator<< (ostream& out, const Park& other) {
    out << other.lastName << " ";
    out << setw(13) << other.firstName << " ";
    out << setw(10) << other.number << '|' << other.region;
    out << setw(5) << other.route << endl;
    return out;
}

istream& operator>>(istream& in, Park& other) {
    in >> other.lastName >> other.firstName >> other.number >> other.region >> other.route;
    return in;
}

ostream& operator<< (ostream& out, const ParkList& other) {
    out << setw(5) << other.region << endl;
    return out;
}


int main() {
    ifstream in;
    ofstream out1;
    ofstream out2;
    in.open("/Users/alex/Documents/Progs/AlexeyG/input.txt");
    out1.open("/Users/alex/Documents/Progs/AlexeyG/output.txt");
    out2.open("/Users/alex/Documents/Progs/AlexeyG/output1.txt");
    if (!in) {
        cerr << "File does not exist";
        exit(0);
    }

    int n;
    in >> n;
    Park* buses = new Park[n];


    out1 << setw(5) << "Surname" << setw(15) << "Firstname" << setw(15) << "Number"<< setw(10) << "Route" << endl;

    for(int i = 0; i < n; i++)
    {
        in >> buses[i];
    }
    sort(buses, n);

    out2 << findMax(buses, n) << endl << findMin(buses, n) << endl << endl;

    for(int i = 0; i < n; i++)
    {
        out1 << buses[i];
    }
    delete [] buses;
}


