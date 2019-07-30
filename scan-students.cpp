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


class Student {
    const int count = 5;
    vector<int> scores;
//    vector<int> second2;
    string first;
    string last;
    int age = 0;
    int stan = 0;

public:
//    Student() {
//        vector<int> temp (count, 0);
//        second2 = temp;
//    }

    int get_age() {
        return age;
    }

    int get_standard() {
        return stan;
    }

    string get_first_name() {
        return first;
    }

    string get_last_name() {
        return last;
    }

    string to_string() {
        string value;
        value.append(std::to_string(age) + ",");
        value.append(first + ",");

        value.append(last + ",");
        value.append(std::to_string(stan));
        return value;
    }

    void set_age(int value) {
        age = value;
    }

    void set_standard(int value) {
        stan = value;
    }

    void set_first_name(string value) {
        first = value;
    }

    void set_last_name(string value) {
        last = value;
    }

    void input() {
        int score;
        for (int i=0; i < count; i++) {
            cin >> score;
            scores.push_back(score);
        }
    }

    int calculateTotalScore() {
        int sum = 0;
        for (int i=0; i < count; i++) {
            sum += scores[i];
        }
        return sum;
    }
};

void scanName() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    cout << endl;
}

int scanStudents() {

    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    cout << count;

}


int main(int argc, const char *argv[]) {

    scanName();
    scanStudents();
    return 0;
}
