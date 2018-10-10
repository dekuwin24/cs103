103 Project 4:
Triangles + Pythagorean Triples

Due: Thursday November 20th @ 11:59pm

Synopsis

For this project, you are asked to implement part of a simple triangle class, and write a function that will search for right triangles1 with certain properties. It should be a simple project, and is mainly designed to give you a breather and to reinforce what we have covered. However, there are a few new things that we'll introduce:

Working with multiple files (separating the implementation from the interface).
Making your own datatypes via class constructs.
A bit about arrays in C++.
You can also look forward to learning more about:

Basic C++ data structures like <vector>.
Functions and arguments.
The technique of "exhaustive search" (a.k.a., "brute force").
Datatypes
Recommended Reading
Most of the new concepts you'll need are covered in chapter 9 of the book. You can also read Professor Li's Notes on structs (which are essentially the same as classes), and Professor Li's Notes on arrays.

Fig. 1 Illustration of the Pythagorean Theorem, stolen from Wikimedia
Fig. 1 Illustration of the Pythagorean Theorem, stolen from Wikimedia

Important Notes on Grading

As always,

Code that does not compile will receive a 0.
Files that are not properly named will receive a 0. (See the section below on "what to submit.")
I will try to make my test programs as flexible as possible, but please run the test script and make sure everything matches. This will save both of us a good bit of time and irritation :D
SUBMIT SOMETHING! Even if it doesn't pass all tests. I can't provide partial credit if I don't receive any code.
Details

Your job is very simple: just write the following four functions:

findRightTriangles
area
congruent
similar
Details follow:

vector<triangle> findRightTriangles(unsigned long l, unsigned long h)
This function searches for right triangles satisfying certain conditions:

All the side lengths must be integers
The triangles must be right triangles
The perimeter must be bounded above and below by input parameters; that is, l ≤ perimeter ≤ h.
The findRightTriangles function should return a vector of triangles which satisfy the above requirements (right, integer sides), such that the perimeter p satisfies l ≤ p ≤ h.

unsigned long triangle::area()
This function simply computes the area of the triangle. Note: that you can assume area will only be called for right triangles with integer sides. Note: this is a member function of the triangle class, which is why there is no input parameter.

bool congruent(...) and similar(...)
These last two return whether or not the two input triangles are congruent and similar, respectively. (In case you have forgotten what these terms mean, go look at wikipedia.)

Aside: const by reference parameters
Note the use of the const keyword in the last two functions. Testing for congruence or similarity probably should not result in the parameters being modified, so it seems like by-value is what we want. However, passing a structure by reference is more efficient than by value, and we wouldn't want to miss out on that. So what to do? The idea is to use a const by-reference parameter. In this way, we kind of "fake" a by-value call. The  const keyword ensures that the parameters won't be changed by the function (unless someone goes way out of their way). Exercise: When you are writing the last two functions, try to modify t1 or t2 somewhere in the function definition, and see what the compiler tells you.

You should also write something in trianglesMain.cpp for your own testing and debugging, but strictly speaking, this isn't necessary.

As was mentioned, there isn't a lot of work to do for this project. That doesn't mean you should procrastinate. Start early, and take some time to absorb the few new ideas we are introducing. In particular:

What to watch for
Classes: We'll be using a class to store triangle data. You have already had some experience with classes, e.g., string and set and vector. But now for the first time, you are seeing how to write your own. This will hopefully generate lots of questions.

Multiple files: the project is now separated into a header file, an implementation file, and a main program. The header file describes what the various parts of the program do, while the implementation describes how they do it. Again, this should be generating questions. Perhaps you are thinking "Why would anyone want to do this?" or "Isn't it just making things more complicated?" See if you can find answers.

Now would be an excellent time to go back and review the compiling on the command line tutorial. Also, go back and re-read page 48 of the book. Now that you have multiple files, this stuff should start to make a lot more sense. You have to separately compile triangles.cpp and the main program's file, and then link the results together into an executable. I have given you a makefile to do this (see below) but before you use it, do it by hand, with your book sitting next to you, open to page 48.

There are two main() functions: One of them is for you to do your own debugging (trianglesMain.cpp). The other (main.cpp) is to run a test script. I gave you a makefile to manage this. Here's a quick summary of how to use it:

$ make will compile and link trianglesMain.cpp to produce an executable called triangleTest. Currently,  trianglesMain.cpp is pretty empty. It is for you to write your own test code.
$ make main will compile and link main.cpp, the test script (see the testing section below) and produce an executable called triangles.
Note: Eclipse will complicate things a bit, because it makes its own makefiles. If you try to add all of this to an eclipse project and hit "build", it will probably (definitely) fail. You will need to take the following steps:

Add a new build configuration go to "project, manage configurations, new.." and copy the settings from debug. Call this new one "testing". It will be for the main.cpp test program I gave you.
Now go back to the workspace panel (on the left, that shows the files of your project) and right click the  main.cpp file. Select "resource configuration, exclude from build" and then select "Debug" (you will not be using this file for the debug target).
Now do the same thing as above for trianglesMain.cpp, but exclude it from "testing", and leave it in "debug".
You're all set now. The debug configuration will build  trianglesMain.cpp, and the testing configuration will build main.cpp. You can switch between the two via "project, build configurations, set active".
Other exercises
You should also try the following while you are programming.

Operators: If you have two triangle instances, you can compare them for equality as follows:

1
2
3
4
triangle t1(3,4,5);
triangle t2(5,4,3);

cout << (t1 == t2) << endl;
The above code would output 0 meaning that the two are not equal. However, using congruence might be a more sensible definition of equality. As it turns out, you can tell C++ to change its definition of equality if you want. This is done by defining  operator==(...) for triangles. Read more of chapter 9 regarding operators for details, and if you want, try to write such a function inside of trianglesMain.cpp.

Complexity: Look at your code for findRightTriangles. Think carefully about the sequence of steps it goes through to compute the answer. Supposing you call the function with the lower bound l=1, how much time does your algorithm take in terms of the other parameter h? I.e., can you find a polynomial expression T(h) that models how many statements must be executed in order to compute the answer? The expression doesn't have to be very precise -- see if you can just figure out the degree of the polynomial.

Testing
This program is a little more complicated to test than the ones before it, but I know you can handle it : ) To test, just compile  main.cpp, say with $ make main, and run the resulting  triangles executable. Check the output of that with the  soutput file that I have distributed. If you want, you can do this:

$ make main
$ gvimdiff -f <(./triangles) soutput
If there are no differences, rejoice. Otherwise, see if you can figure out what went wrong. For this, it might be helpful to not redirect the output to a file, and just run:

$ make main
$ ./triangles
This should show you what tests are running with your output right under it. You can then find what you should have had by examining the diff.

Hints
findRightTriangles: For this, there are formulas that will compute the integers you are after, but it might be easier to just use a brute-force approach. Construct a loop (perhaps nested loops) that runs over all the possibilities, and then filter out everything but the ones that match. I won't test the program on really large integers, so don't be too concerned over performance. Just get the right answers.
Everything else: area,congruent,similar: The formulas are easy for figuring these out, but there is one kind of sticky point: you have no guarantees about the ordering of the edges. The easiest thing to do is put them in order first, and then do the comparisons / computations. For this, you can use the sort() function from the algorithm library. Here's an example:
1
2
3
4
5
6
7
8
9
#include <algorithm>
using std::sort;
bool triangle::area() {
    // put the sides in an array:
    unsigned long sides[3] = {s1,s2,s3};
    // sort the array:
    sort(sides,sides+3);
    // at this point, sides[0] <= sides[1] <= sides[2]
}
Submission Procedure

Turn your assignment in here. A few important notes:

Save the receipt. You will need this to get your homework score back later from the hw download page.
Don't change the filename. Just edit and submit the file from the repository (in this case triangles.cpp). If you turn a file with a different name, it will not be graded.
Respect the deadline. Turning in homework past the deadline will be noticed, and may lead to a zero.
Although, the coolest triangles have historically been equilateral:
floyd triforce↩
