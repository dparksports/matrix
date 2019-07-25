#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle{
public:
    void triangle(){
        cout<<"I am a triangle\n";
    }
};

class Isosceles : public Triangle{
public:
    void isosceles(){
        cout<<"I am an isosceles triangle\n";
    }
};

class Equilateral : public Isosceles{
public:
    void equilateral(){
        cout<<"I am an equilateral triangle\n";
    }
};

int multiinheristance(){

    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();

}

int main(int argc, const char *argv[]) {
    multiinheristance();

    return 0;
}
