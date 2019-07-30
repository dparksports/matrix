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

class Person {

protected:
    string name;
    int age;
    int currentId;
public:

    Person() {
    }

    ~Person() {

    }

    virtual void getdata()=0;
    virtual void putdata()=0;
};

class Professor : public Person {
private:
    int publications;

public:
    static int count;

    Professor() {
        currentId = ++count;
    }

    void getdata() override {
        cin >> name >> age >> publications;
    }

    void putdata() override {
        cout << name << " " << age << " " << publications << " " << currentId;
        cout << endl;
    }
};

class Student : public Person{
private:
    vector<int> marks;
    static int count;

    int sum() {
        int sum = 0;
        for (int i = 0; i < marks.size(); ++i) {
            sum += marks[i];
        }
        return sum;
    }

public:
    Student() {
        marks = vector<int> (6,0);
        currentId = ++count;
    }

    void getdata() override {
        cin >> name >> age;

        for (int i = 0; i < marks.size(); ++i) {
            cin >> marks[i];
        }
    }

    void putdata() override {
        cout << name << " " << age << " " << sum() << " " << currentId;
        cout << endl;
    }
};

int Professor::count = 0;
int Student::count = 0;

int dovirtual() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        } else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

}

int main(int argc, const char *argv[]) {
    dovirtual();
    return 0;
}
