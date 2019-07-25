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

    virtual void description() = 0;
};

class Isosceles : public Triangle{
public:
    void isosceles(){
        cout<<"I am an isosceles triangle\n";
    }
    void description(){
        cout<<"In an isosceles triangle two sides are equal\n";
    }
};

int doinheristance() {
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();

}

int main(int argc, const char *argv[]) {
    doinheristance();

    return 0;
}
