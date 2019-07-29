#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T>
class AddElements {
    T sum;
public:
    AddElements(T arg) {
        sum = arg;
    }

    T add(T arg) {
        sum += arg;
        return sum;
    }
};


template <>
class AddElements <string>{
    string appended;
public:
    AddElements(string arg) {
        appended = arg;
    }

    string concatenate(string arg) {
        appended.append(arg);
        return appended;
    }
};


int doTemplate () {
    int n,i;
    cin >> n;
    for(i=0;i<n;i++) {
        string type;
        cin >> type;
        if(type=="float") {
            double element1,element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat (element1);
            cout << myfloat.add(element2) << endl;
        }
        else if(type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint (element1);
            cout << myint.add(element2) << endl;
        }
        else if(type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring (element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    cout << endl;
}

int main(int argc, const char *argv[]) {
    doTemplate();

    return 0;
}
