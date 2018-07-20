#include <iostream>
#include <fstream>
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
	
	std::string catted("someare");

	for(std::string::iterator it = catted.begin(); it != catted.end(); ++it){
		
	}
}
