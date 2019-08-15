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

class D:A,B,C {
    int val;
public:
    D()
    {
        val = 1;
    }

    bool isDivisible(const int& value, const int& factor) {
        float result = value % factor;
        return (result == 0);
    }

    void update_val(int new_val) {
        int factor2 = 0;
        int factor3 = 0;
        int factor5 = 0;

        int remained = new_val;
        bool usedFactor5 = true;
        bool usedFactor3 = true;
        bool usedFactor2 = true;

        while (usedFactor5 || usedFactor3 || usedFactor2) {
             usedFactor5 = false;
             usedFactor3 = false;
             usedFactor2 = false;

            if (isDivisible(remained, 5)) {
                remained /= 5;
                factor5++;
                usedFactor5 = true;

                C::func(factor5);
            }

            if (isDivisible(remained, 3)) {
                remained /= 3;
                factor3++;
                usedFactor3 = true;

                B::func(factor3);
            }

            if (isDivisible(remained, 2)) {
                remained /= 2;
                factor2++;
                usedFactor2 = true;

                A::func(factor2);
            }
        }

        val = remained;
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
