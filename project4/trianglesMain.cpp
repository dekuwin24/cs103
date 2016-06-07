#include "triangles.h"
#include <iostream>
using namespace std;

int main() {
	triangle tr1 (3, 4, 5);
	triangle tr2 (6, 8, 10);
	triangle tr3 (4, 3, 5);

	cout << congruent (tr1, tr3) << endl;
	cout << similar (tr1, tr3) << endl;
	cout << congruent (tr1, tr2) << endl;
	cout << similar (tr1, tr2) << endl;


	int lower, upper;
	cout << "Enter lower limit: ";
	cin >> lower;
	cout << "Enter upper limit: ";
	cin >> upper;

	vector<triangle>repository = findRightTriangles (lower, upper);

	triangle p1 = repository[0];
	triangle p2 = repository[1];

	cout << "length of triangle p1 is " << p1.s1 << '\t' << p1.s2 << '\t' << p1.s3 << endl;
	cout << "length of triangle p2 is " << p2.s1 << '\t' << p2.s2 << '\t' << p2.s3 << endl;
}
