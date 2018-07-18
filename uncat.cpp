#include <iostream>
#include <fstream>
#include <istream>
#include <stdlib.h>
#include <string>
#include "tree.h"
#include "node.h"

#define DICTIONARY "wordstest.txt"

int main(){
	Tree dict;
	std::fstream fword;
	std::string word;

	fword.open(DICTIONARY);

	while(!fword.eof()){
		std::getline(fword, word, '\n');
		dict.addWord(word);
	}

	if(dict.isWord("Are")){
		std::cout << "is in the dictionary" << std::endl;
	}
}
