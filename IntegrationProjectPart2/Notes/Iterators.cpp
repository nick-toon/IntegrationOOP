/** @file Iterators.cpp
 *  @brief File showcases the use of iterators
 *
 *  L07 Define & Use Iterators: An iterator is an object that points to a element 
 *  in a range of elements (like an array). They iterate through the 
 *  elements of that range using a set of operators. 
 *  The increment (++) and dereference (*) operators need to be used.
 *
 *  @author Nicholas Cotugno
 *  @bug No known bugs.
 */

#include <iostream>
#include <iterator> //mechanism for 'iterating' through stuff
#include <vector>
using namespace std;

int main() {
	std::vector<string> nfl_AFC_teams = {
		"Bills", "Dolphins","Patriots","Jets","Texans","Colts", "Jaguars","Titans", 
		"Ravens","Bengals", "Browns","Steelers", "Broncos","Chiefs", "Raiders","Chargers"};

	std::vector<string> nfl_NFC_teams = {
		"Cowboys", "Giants","Eagles","Redskins","Falcons","Panthers", "Saints","Buccaneers",
		"Bears","Lions", "Packers","Vikings", "Cardinals","Rams", "49ers","Seahawks" };

	cout << "NFL teams by conference" << endl;

	cout << "\nAFC:" << endl;
	for (vector<string>::iterator a = nfl_AFC_teams.begin(); a != nfl_AFC_teams.end(); a++) //iterates through vector
		cout << *a << endl; //dereference iterator

	cout << "\nNFC:" << endl;
	for (vector<string>::iterator b = nfl_NFC_teams.begin(); b != nfl_NFC_teams.end(); b++) //iterates through vector
		cout << *b << endl; //dereference iterator

	return 0;
}