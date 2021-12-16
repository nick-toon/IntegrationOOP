/** @file Encapsulation.cpp
 *  @brief File showcases encapsulation
 *
 *  Encapsualtion is used in this program to get a twitch streamers
 *  salary based on how many subscribers they have.
 *
 *  @author Nicholas Cotugno
 *  @bug No known bugs.
 */
#include <iostream>
using namespace std;

class TwitchStreamer {
private: //LO6. Use object-oriented encapsulation mechanisms such as interfaces and private members.
    // Private attribute
    int salary;

public:
    void setSalary(int s) {
        salary = s*5;
    }
    int getSalary() {
        return salary;
    }
};

int main() {
    TwitchStreamer myObj;
    string name;
    int subs;
    cout << "Twitch Streamer:" << endl;
    cin >> name;
    cout << "How many subscribers?" << endl;
    cin >> subs;
    myObj.setSalary(subs);
    cout << name << " makes $" << myObj.getSalary() << " a month off their subscribers" << endl;
    return 0;
}