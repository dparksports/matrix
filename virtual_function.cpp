#include <iostream>

using namespace std;

class Rectangle {
protected:
    int w,h;
public:
    virtual void display() {
        cout << w << " " << h << endl;
    }
};

class RectangleArea: public Rectangle {
public:
    void read_input() {
        cin >> w >> h;
    }

    void display() override {
        cout << w * h;
    }
};

int doRectangleArea()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */ << " " <<
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

}

int main(int argc, const char *argv[]) {
    doRectangleArea();

    return 0;
}
