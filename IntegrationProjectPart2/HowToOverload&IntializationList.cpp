/** @file HowToOverload&IntializationList.cpp
 *  @brief File showcases overloaded constructors & initialization list
 *
 *  This program utilizes overloaded constructors and a initialized list.
 *  Instead of implementing it directly into my QT notepad progam, im going to
 *  make it a text file that can be opened up in the notepad.
 *
 *  @author Nicholas Cotugno
 *  @bug No known bugs.
 */


#include<iostream>
using namespace std;

class Coordinates {
private:
    int x;
    int y;
public:
    Coordinates(int i = 0, int j = 0) { //Initialization list
        x = i;
        y = j;
    }
    int getX() const { 
        return x; 
    }
    int getY() const { 
        return y; 
    }

    void show() {
        cout << "x = " << getX() << ", ";
        cout << "y = " << getY() << endl;
    }
};

int main() {
    //Overloading constructors
    Coordinates p1(2, 4);
    Coordinates p2(5, 10); 
    Coordinates p3(6, 12); 

    p1.show();
    p2.show();
    p3.show();

    return 0;