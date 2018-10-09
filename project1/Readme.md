Skip to content Search or jump to… Pull requests Issues Marketplace Explore @dekuwin24 Sign out 1 0 0 ipalongengi/cs103 Code Issues 0 Pull requests 0 Projects 0 Wiki Insights cs103/project1/readme.html 1cfdfba on Jun 6, 2016 @ipalongengi ipalongengi dump all projects to the repo, still need to be fixed Executable File 197 lines (193 sloc) 7.49 KB
103 Project 1

Due: Thursday, September 18th @ 11:59pm

Synopsis

This project is very simple modification of the standard "hello world" program, which gathers user input to construct the response. The main point is for you to spend a little time getting comfortable with the tools, making sure you know how to do the basics of compiling and linking, and starting to get you a tiny bit familiar with C++.

Important Notes on Grading

Code that does not compile will receive a 0.
Files that are not properly named will receive a 0. (See the section below on the submission procedure.)
Details

Your assignment is just to modify the simple "hello world" program so that it collects some information from the user, and then echoes a more personal greeting, modeled after a famous line from The Princess Bride. Here's what a transcript of your program should look like:

Enter your name:
Inigo
Enter a relative:
father
Hello.  My name is Inigo. You killed my father. Prepare to die.
Your program asks for the name, and relative, stores the responses, and prints the greeting line at the end. That's it. Pretty easy, right? Hopefully so. Note: if you want to collect names / relatives with whitespace, e.g., "Inigo Montoya", or "great grandmother's second cousin", then you'll want to use  getline(cin,stringname) rather than cin >> stringname, but it is not required to do so.

You may want to start with a template that looks something like this:

1
2
3
4
5
6
7
8
9
10
#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

int main()
{

}
Make sure you know what each of the lines does (more or less). The <string> library provides you with the string class, surprisingly enough. Use a variable of this type to store the user's name. Recall that the <iostream> library provides you a way to access standard input and output.

It might be a good idea to follow along with the tutorial on building from the command line as you're doing this assignment.

Submission Procedure

Turn your assignment in here. A few important notes:

Save the receipt. You will need this to get your homework score back later! The easiest thing to do is just save the page (Ctrl-S in firefox).
Don't change the filename. Just edit and submit the file from the repository (in this case hello.cpp). If you turn a file with a different name, it will not be graded.
Respect the deadline. Turning in homework past the deadline will be noticed, and may lead to a zero.
For Next Time...

Since your reading this, you have managed to clone the repository:

$ git clone https://molina_ccny@bitbucket.org/molina_ccny/csc103-projects.git
Congratulations :D However, in the future, don't run clone again. This is only for the first time. To get the future project skeletons, you only need to run:

$ git commit -a -m "message goes here..."
$ git pull --no-edit
The first command is to commit your changes (which you should have been doing all along, of course...). The second will bring in the new stuff for the next project. Note that you have to do this from inside the csc103-projects/ directory. Note also that if you leave out the --no-edit you can enter something other than the default merge message; however in our scenarios, this is not typically useful.

© 2018 GitHub, Inc. Terms Privacy Security Status Help Contact GitHub Pricing API Training Blog About Press h to open a hovercard with more details.
