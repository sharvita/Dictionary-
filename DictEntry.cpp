
//Sharvita Paithankar 
#include <list>
#include <vector>
#include "DictEntry.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
/*
Precondition: none 
Postconditon:none 
Description:constructor 
*/
DictEntry:: DictEntry() {
	//intentionally left blank 
}
/*
Precondition: takens in an empty doubly linked list as a paramenter to put words into 
Postconditon: fills list with words from file 
Description: uses infile to take in words from a file to put into the list
*/
void Dictionary::inputFile(list<DictEntry>& words) {

	string temp;
	ifstream infile;
	infile.open("dictionary.txt");

	if (infile.fail()) {
		cout << "Something went wrong while reading the file." << endl;
	}
	else {
		while (!infile.eof()) {
			getline(infile, temp);

			DictEntry* node = new DictEntry(); //creates a new node
			node->setWord(temp); 

			words.push_back(*node); //creates another node 
		}
		words.sort(); //sorts the list after it is filled
		infile.close();
		cout << "The file read successfully." << endl;
	}
}
/*
Precondition: takens in a doubly linked list as a paramenter
Postconditon: prints 
Description: prints list using iterator 
*/
void Dictionary :: printList(list<DictEntry> &words) {

	list<DictEntry>::iterator it; //creates the iterator
	cout << "The dictionary contains: " << endl;
	for (it = words.begin(); it != words.end(); it++) {//it used to go through the list 
		cout << it->getWord() << endl; // a pounter needs to be used 
	}

}
/*
Precondition: takens in a doubly linked list as a paramenter
Postconditon: prints how many comparisons it made 
Description: goes through the list using an iterator, takes in word from the 
file and searches for them from the beginning of the list 
*/
void Dictionary:: searchForward(list<DictEntry> &words) {

	list<DictEntry>::iterator it; //creates the iterator
	string searchWord;
	int count = 0; //ounts the comparisons 
	ifstream infile;
	infile.open("findwords.txt");
	words.sort();
	if (infile.fail()) { //if file is not read 
		cout << "Cannot read file." << endl;
	}

	else {
		while (!infile.eof()) {
			getline(infile, searchWord);

			for (it = words.begin(); it != words.end(); it++) { //uses and itertor 
				count++;
				if (searchWord == it->getWord()) { //if the word is found 
					cout << "Number of comparisons made: " << count << endl;
				}
			}
		}
		infile.close();
	}
}
/*
Precondition: takens in a doubly linked list as a paramenter
Postconditon: prints number of comparisons made 
Description: goes through the list using an iterator, takes in word from the 
file and searches for them from the end of the list 
*/
void Dictionary :: searchBackward(list<DictEntry> &words) { //searches the list from the tail to the head using a reverse iterator

	list<DictEntry>::reverse_iterator r_it; //creates a reverse iterator
	string searchWord;
	words.sort();
	ifstream infile;
	infile.open("findwords.txt");
	int count = 0; //will be used to display the number of comparisons

	if (infile.fail()) {
		cout << "Failed to read the file." << endl;
	}

	else {
		while (!infile.eof()) {
			getline(infile, searchWord); //takes in the word

			for (r_it = words.rbegin(); r_it != words.rend(); r_it++) { //iterates through the list 
				count++;
				if (searchWord == r_it->getWord()) {//if the word we are looking for is in the list display the following
					cout << "Number of comparisons: " << count << endl;
				}
			}
		}
		infile.close();
	}
}
/*
Precondition: takes in a doubly linked list 
Postconditon: prints out the list 
Description: prints out the list into a file backwards 
*/
void Dictionary:: outputFile(list<DictEntry> &words) {

	words.sort();
	list<DictEntry>::reverse_iterator r_it; //iterating from back 
	ofstream outfile;
	outfile.open("revsorted.txt");

	for (r_it = words.rbegin(); r_it != words.rend(); r_it++) {//iterating from back 
		outfile << r_it->getWord() << endl;
	}
	outfile.close(); //closes file 
}
