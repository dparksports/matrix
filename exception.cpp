//
//  main.cpp
//  transpose
//
//  Created by Dan Park on 6/19/19.
//  Copyright © 2019 Dan Park. All rights reserved.
//

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cassert>

#include <exception>

#include <algorithm>

using namespace std;



class BadLengthException: public exception {
private:
    string exceptionString;

public:
    BadLengthException(int n) {
        exceptionString = to_string(n);
    }

    virtual const char* what() const throw()
    {
//        string temp;
//        temp.append(to_string(length));
//        exceptionString.append(temp);
        return exceptionString.c_str();
    }
};

bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if(n < 5) {
        throw BadLengthException(n);
    }
    for(int i = 0; i < n-1; i++) {
        if(username[i] == 'w' && username[i+1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int throwException() {
    int T; cin >> T;
    while(T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if(isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';

            cout << endl;
        }
    }
    cout << endl;
    return 0;
}



int main(int argc, const char *argv[]) {

        throwException();



    return 0;
}
