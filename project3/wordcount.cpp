/*
 * CSc103 Project 3: wordcount++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * Yassine Wardei, SEEK PAL Tutor
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: ~ 10 Hrs.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <set>
using std::set;

// write this function to help you out with the computation.
unsigned long countWords (const string& s, set <string>& wc);
unsigned long countLine (const string& s, set <string>& lc);

int main(){
	string input;
	unsigned long wc, lc, char_count;
	wc = lc = char_count = 0;
	set <string> word_count;	// unique words go here
	set <string> line_count;	// unique lines go here

	while (getline(cin, input)){
		input += ' ';	//adds a space to the end of each line for the lost newline char
		char_count += input.length();
		wc += countWords (input, word_count);
		lc += countLine (input, line_count);
	}

	cout
	<< lc << '\t'
	<< wc << '\t'
	<< char_count << '\t'
	<< line_count.size() << '\t'
	<< word_count.size() << endl;
}

unsigned long countWords (const string& s, set <string>& wc){
	unsigned long counter = 0;
	string temp= "";
	for (int i = 0; i < s.length(); i++){
		/*the if-statement checks for any extreneous space, tab, and newline char
		encountering any of these chars will cause the filling of temp var to stops
		and its insertion into the set*/
		if ((s[i] != ' ') && (s[i] != '\t') && (s[i] != '\n')){
			temp += s[i];
		}
		else{
			// the if-statement checks for an empty line
			if (temp.length() != 0){
				wc.insert(temp);
				temp = "";
				counter++;
			}
		}
	}
	return counter;
}

unsigned long countLine (const string&s, set <string>& lc){
	int line_count = 0;
	lc.insert(s);
	line_count++;
	return line_count;
}
