/*
 * CSc103 Project 4: Triangles
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * Yassine Wardei - PAL SEEK Center
 * Qasim Ashraf, Sultan Alreyashi, Ayaz Shah - Classmates
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 10 hours
 */

#include "triangles.h" // import the prototypes for our triangle class.
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <cmath>
using std::pow;
using std::sqrt;

// note the "triangle::" part.  We need to specify the function's
// FULL name to avoid confusion.  Else, the compiler will think we
// are just defining a new function called "perimeter"

unsigned long triangle::perimeter() {
	return s1+s2+s3;
}

unsigned long triangle::area() {
	//assuming that it is a right triangle
	unsigned long triangle [3]= {s1, s2, s3};

	//put them in ascending order
	sort (triangle, triangle+3);

	unsigned long area = (triangle[0] * triangle [1]) /  2;

	return area;
}

void triangle::print() {
	cout << "[" << s1 << "," << s2 << "," << s3 << "]";
}

bool congruent(triangle t1, triangle t2) {
	//puts triangle t1 into an array and sorts these elements in ascending order
	unsigned long tr1 [3] = {t1.s1, t1.s2, t1.s3};
	sort (tr1, tr1+3);

	//puts triangle t2 into an array and sorts these elements in ascending order
	unsigned long tr2 [3] = {t2.s1, t2.s2, t2.s3};
	sort (tr2, tr2+3);

	// returns true IFF every side of triangle t1 is equal to t2 (congruent)
	return ((tr1[0] == tr2[0]) && (tr1[1] == tr2[1]) && (tr1[2] == tr2[2]));
}

bool similar(triangle t1, triangle t2) {
	//puts triangle t1 into an array and sorts these elements in ascending order
	unsigned long tr1 [3] = {t1.s1,t1.s2,t1.s3};
	sort (tr1, tr1+3);

	//puts triangle t2 into an array and sorts these elements in ascending order
	unsigned long tr2 [3] = {t2.s1,t2.s2,t2.s3};
	sort (tr2, tr2+3);

	//after being sorted, ratios are taken according to their sorting order (shortest, short, longest)
	double ratio1 = double(tr1[0]) / tr2[0];
	double ratio2 = double(tr1[1]) / tr2[1];
	double ratio3 = double(tr1[2]) / tr2[2];

	// returns true IFF the ratio of both triangles are the same
	return ((ratio1 == ratio2) && (ratio2 == ratio3));
}

vector<triangle> findRightTriangles(unsigned long l, unsigned long h) {
	//Finds right triangles between prescribed perimeters
	vector<triangle>retval;
	unsigned long a, b, c;
	for (a = 3; a < h; a++){
		for (b = a+1; b < h; b++){
			for (c = b+1; c < h; c++){
				if ((a+b+c >= l) && (a+b+c <= h) && (pow(c,2) == pow(a,2) + pow(b,2))){
					triangle temp (a, b, c);
					retval.push_back(temp);
				}
			}
		}
	}
	return retval;
}
