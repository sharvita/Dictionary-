#ifndef DICTENTRY_
#define DICTENTRY_

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

typedef std::string wordType;


class DictEntry
{
private:

    wordType word;
    wordType definition;
	list<wordType> words;
    
public:

	DictEntry();
    wordType getWord(){return word;}
    void setWord(wordType _word){word = _word;}
    wordType getDef(){return definition;}
    void setDef(wordType _def){definition = _def;}
    bool operator < (const DictEntry &entry) const
	{
        return (word < entry.word);
	}

};
class Dictionary {
public :
	void inputFile(list<DictEntry>&);
	void outputFile(list<DictEntry> &);
	void searchForward(list<DictEntry> &);
	void searchBackward(list<DictEntry> &);
	void printList(list<DictEntry> &);
};
#endif
