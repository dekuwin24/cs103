103 Project 3: Wordcount++

Due: Monday, October 27th @ 11:59pm

Synopsis

In this project, you'll re-implement the famous unix utility wc ("word count"), and make some minor enhancements as well. You can find some details on the original wc here. What you'll learn from doing this:

More about basic C++ data structures like <string> and  <set>.
Functions and arguments.
A bit more about the unix shell.
Important Notes on Grading

As always,

Code that does not compile will receive a 0.
Files that are not properly named will receive a 0. (See the section below on "what to submit.")
Details

Again, we'll try to adhere to the unix philosophy: your program will read standard input, write standard output, and won't print much of anything that isn't necessary. Your program should more or less imitate wc, by printing out the number of lines, words, and characters. Additionally, it should print the number of unique lines, and the number of unique words. There are a few things that wc does which we will not worry about, however. In particular:

You don't need to process arguments (like filenames); you can assume that all the input comes from standard input.
You don't need to format the output exactly the same way as wc: you can just separate each piece of the output by a tab \t character, or a few spaces (but don't print anything that isn't whitespace between the output fields).
Here is some sample output from the program:

$ echo -e "hello there\nthis is a test" | ./wordcount
        2       6       27       2       6
The format of the output is

#lines  #words  #characters  #unique lines  #unique words
with each separated by whitespace (I used tabs). The first three numbers of the output here is essentially identical to that of wc. Note: The -e argument to echo enables the use of escape sequences, so that we can type a newline into the string with \n. Alternatively, you can use here documents, which let you specify an "end of input" marker, and then type multiple lines of text until you enter the end of input marker on a single line. Let's try that with something a little more interesting:

$ ./wordcount <<EOF
> this is another example
> this example has multiple lines
> not all lines are unique
> not all lines are unique
> EOF
        4       19      106     3       11
The shell will let you type as many lines as you want until you type a line with just EOF, which it interprets as the end of the input. Perhaps even easier still, is to just type a file once, and use that for input. Assuming that we have a file called testfile containing the text above, this can be done as follows:

$ ./wordcount < testfile
        4       19      106     3       11
The < operator in bash will take a file and then feed its contents to the program as standard input.

Testing Your Code

I've made it easy to test your code. Just build your program, and then run ./test.sh. It will tell you what went wrong, if anything. Note: this is not the ultimate verdict on whether or not your code works, but it does some reasonable tests. You can find the input files for the tests in the testdata/ directory.

Remarks

Punctuation: you can assume that the input doesn't contain any punctuation like ".,?" etc. Your program might consider "this" to be a different word than "this." and that is okay. I won't test that. You can change it if you want to.

Case-sensitivity: I will test your program with all lower-case input, so you don't have to worry about case. Natural solutions to the problem will probably give a case-sensitive solution, so that "this" is not the same as "This". Again, you can change this if you want, but it won't matter to me.

Hints

General approach
A good way to do this is to read one line at time from input into a string, say using getline(), and then break down each string to compute the words. As you are breaking the string into words, you can store them in a set container, which will automatically toss-out the duplicates. To break down the strings, I would recommend writing a function like this:

1
unsigned long countWords(const string& s, set<string>& wl);
The first parameter is to hold a line from the input, and the second parameter is used as output (note the & for call by reference) to store the distinct words. I in fact left the above function prototype in the skeleton. You might want to use it. Also, you will again have to deal with reading an arbitrary amount of information from cin. I would use a loop something like this:

1
2
3
while(getline(cin,line)) {
    // process a line.
}
The loop will end when the input ends. How easy is that? :D

Diagrammatic Approach to countWords
The following diagram might be helpful when thinking of how to process a line.

Fig. 1: State Diagram
Fig. 1: State Diagram

Start in the node on the left hand side, and start reading characters, one by one. As you read a character, you will move along the arrows as prescribed by the diagram. Notice that what you want to do upon reading a character depends on what character you were reading previously -- that is, it depends on which one of the nodes you are in! Then all that remains is to add the right actions for each case. E.g., if you were just reading non-whitespace, and then read whitespace, you know you hit a word boundary, so increment the word count, and save that word to your set of unique words. I realize the diagram doesn't look much like C++, but it is actually easy to convert. Just use an integer (or even boolean in this case) for which node you are in, and update it according to the diagram as you read characters.

Small errors in counting
At first, your character count may be off from that of wc by a little bit, probably because you forgot to count the newlines as characters.
If your word count is off as well, make sure you are not forgetting the last word in each line.
See the above remarks about punctuation...
Useful std::string and std::set functions
The following string functions might be useful:

The length() function
The += operator
And you will want to familiarize yourself with the set functions too. One note on the set class: at first, it may be a little less than obvious as to how to see what's inside it. If you want to print the contents of the set (for debugging), use a loop like this:

1
2
3
4
5
6
set<string> words;
// put stuff into words variable...
// then print contents:
for (set<string>::iterator i = words.begin(); i!=words.end(); i++) {
    cout << *i << endl;
}
The mysterious part is the iterator business. It is an abstraction of an integer index into an array in some sense. We'll get to that later; don't worry about it for now.

Makefiles
I again gave you a simplistic makefile for your convenience. Using the tutorials (here and here), try to reverse engineer it if you have time.

Submission Procedure

Turn your assignment in here. A few important notes:

Save the receipt. You will need this to get your homework score back later from the hw download page.
Don't change the filename. Just edit and submit the file from the repository (in this case wordcount.cpp). If you turn a file with a different name, it will not be graded.
Respect the deadline. Turning in homework past the deadline will be noticed, and may lead to a zero.
