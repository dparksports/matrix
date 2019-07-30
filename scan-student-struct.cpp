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


struct StudentStruct {
    string first_name;
    string last_name;
    int age = 0;
    int standard = 0;

    StudentStruct() {
    }
};

int scanStudentStruct() {
    StudentStruct st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    cout << endl;
}



int main(int argc, const char *argv[]) {

    scanStudentStruct();


    return 0;
}
