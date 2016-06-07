/*
 * CSc103 Project 5: Syntax highlighting, part one.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * Yassine Wardei - SEEK PAL Center
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: ~9-10 Hrs.
 */

#include "fsm.h"
using namespace cppfsm;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// make sure this function returns the old state.  See the header
// file for details.
int cppfsm::updateState(int& state, char c) {
	int old_state = state;	// save the old state in a new variable
	switch (state){
		case start:
		if (INSET (c, ident_st)){
			state = scanid;
		}
		else if (INSET (c, num)){
			state = scannum;
		}
		else if (INSET (c, iddelim)){
			state = start;
		}
		else if (c == '/'){
			state = readfs;
		}
		else if (c == '"'){
			state = strlit;
		}
		break;

		case scanid:
		if (INSET (c, ident)){
			state = scanid;
		}
		else if (INSET (c, iddelim)){
			state = start;
		}
		else if (c == '/'){
			state = readfs;
		}
		else if (c == '"'){
			state = strlit;
		}
		break;

		case comment:
		state = comment;
		break;

		case strlit:
		if (c == '"'){
			state = start;
		}
		else if (c == '\\'){
			state = readesc;
		}
		else{
			state = strlit;
		}
		break;

		case readfs:
		if (INSET (c, ident_st)){
			state = scanid;
		}
		else if (INSET (c, num)){
			state = scannum;
		}
		else if (c == '"'){
			state = strlit;
		}
		else if (c == '/'){
			state = comment;
		}
		break;

		case readesc:
		if (INSET (c, escseq)){
			state = strlit;
		}
		else{
			state = error;
		}
		break;

		case scannum:
		if (INSET (c, iddelim)){
			state = start;
		}
		else if (INSET (c, num)){
			state = scannum;
		}
		else if (c == '/'){
			state = readfs;
		}
		else {
			state = error;
		}
		break;
	}
	return old_state;
}
