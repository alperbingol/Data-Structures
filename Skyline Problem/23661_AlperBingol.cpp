#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "MPQ.h"
#include <algorithm>


using namespace std;

struct A { // created a struct in order to keep track the vector with 3 different parameters 

	int xcoor;  // x coordinates
	int yheight; // heights of buildings
	string sore; // s or e , means start or end of buildings

	A(int x, int y, string s) { // used this to ease the visualization

		xcoor = x;
		yheight = y;
		sore = s;
	}
};

bool sortXcoor(const A a, const A b) {  // sorted firstly based on x coordinates

	if (a.xcoor == b.xcoor) { // if xs are equal look start and end

		if (a.sore == b.sore) { // if they are same look heights

			if (a.sore == "s") {
				return (a.yheight > b.yheight);  // if s, bigger height comes first
			}

			else {
				return (a.yheight < b.yheight); // else smaller height comes first
			}

		}

		else {
			return (a.sore > b.sore);
		}
	}
	else
	{
		return(a.xcoor < b.xcoor);
	}

}


int main() {

	ifstream input;

	vector<A> vec1; // two vectors to distunguish starts and ends 
	vector<A> vec2;

	input.open("input.txt"); // reads from txt file
	int numBuilding, xleft, xright, height;

	input >> numBuilding;

	while (input >> xleft >> height >> xright) {

		A start = A(xleft, height, "s");
		vec1.push_back(start);
		A end = A(xright, height, "e");
		vec2.push_back(end);
	}

	for (int i = 0; i<vec2.size(); i++) {

		vec1.push_back(vec2[i]); // merge two vectors to build heap easily 
	}

	std::sort(vec1.begin(), vec1.end(), sortXcoor); // sort function

	PriorityQueue pq;

	pq.insert(0); // initially 0 is given to heap

	if (vec1[0].xcoor != 0)  // if there is no building on the first  zero x coordinate
		cout << "0" << " " << "0" << endl;

	for (int i = 0; i<vec1.size(); i++) { // loop until vector finishes 

		if (vec1[i].sore == "s") { // if this is a start point of a building then should insert a height to heap 
			int a = pq.GetMax();
			pq.insert(vec1[i].yheight);

			if (a != pq.GetMax()) // and control if the max height is changed or not
				cout << vec1[i].xcoor << " " << pq.GetMax() << endl; // if changed then cout the output
		}

		else {
			int b = pq.GetMax();
			pq.remove(vec1[i].yheight); // remove the next height 
			int c = pq.GetMax();

			if (b != c) // if max height has changed then cout the changed height 
				cout << vec1[i].xcoor << " " << pq.GetMax() << endl;
		}
	}

	return 0;
}