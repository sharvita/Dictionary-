//Sharvita Paithanakr 
#include <sstream>
#include <fstream>
#include "DictEntry.h"
//calls on functions 
int main() {
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Dictionary"<<endl;//for the heading which gives it better looks
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;

	list<DictEntry> words;
	Dictionary object;

	object.inputFile(words);
	object.printList(words);

	object.searchForward(words);
	object.searchBackward(words);

	object.outputFile(words);


	//system("pause");
	return 0;
	//system("pause");
}
