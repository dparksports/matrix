#include<iostream>

using namespace std;

class A
{
public:
    A(){
        callA = 0;
    }
private:
    int callA;
    void inc(){
        callA++;
    }

protected:

    void func(int & a)
    {
        a = a * 2;
        inc();
    }

public:
    int getA(){
        return callA;
    }
};

class B
{
public:
    B(){
        callB = 0;
    }
private:
    int callB;
    void inc(){
        callB++;
    }
protected:
    void func(int & a)
    {
        a = a * 3;
        inc();
    }
public:
    int getB(){
        return callB;
    }
};

class C
{
public:
    C(){
        callC = 0;
    }
private:
    int callC;
    void inc(){
        callC++;
    }
protected:
    void func(int & a)
    {
        a = a * 5;
        inc();
    }
public:
    int getC(){
        return callC;
    }
};

class D: public A, public B, public C {
    int val;
public:
    D() {
        val = 1;
    }

    void update_val(int new_val) {
        bool usedFactor2;
        bool usedFactor3;
        bool usedFactor5;

        usedFactor2 = true;
        usedFactor3 = true;
        usedFactor5 = true;

        while (usedFactor2 || usedFactor3 || usedFactor5) {
            usedFactor2 = false;
            usedFactor3 = false;
            usedFactor5 = false;

            if (new_val % 2 == 0) {
                new_val /= 2;
                A::func(val);

                usedFactor2 = true;
            }

            if (new_val % 3 == 0) {
                new_val /= 3;
                B::func(val);

                usedFactor3 = true;
            }

            if (new_val % 5 == 0) {
                new_val /= 5;
                C::func(val);

                usedFactor5 = true;
            }
        }
    }

    //For Checking Purpose
    void check(int); //Do not delete this line.
};

void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl;
    cout << "A's func called " << getA() << " times " << endl;
    cout << "B's func called " << getB() << " times" << endl;
    cout << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
