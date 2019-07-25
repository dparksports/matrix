//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }

};


Complex operator+(Complex lhs,        // passing lhs by value helps optimize chained a+b+c
                         const Complex& rhs) // otherwise, both parameters may be const references
{
    lhs.a += rhs.a; // reuse compound assignment
    lhs.b += rhs.b; // reuse compound assignment
    return lhs; // return the result by value (uses move constructor)
}

ostream& operator<<(ostream& os, const Complex& obj)
{
    os << obj.a << "+i" << obj.b;
    return os;
}

int overloadOperators()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}

int main(int argc, const char *argv[]) {
    overloadOperators();

    return 0;
}
