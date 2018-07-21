#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "tree.h"
#include "node.h"

#define DICTIONARY "wordstest.txt"

Tree dict;
std::string catted;
std::stack<int> spaces;

int recFindWord(int i){
	Node* iter = dict.root;
	iter = iter->getChild(catted[i]);

	for(; i < catted.length(); ++i, iter = iter->getChild(catted[i])){
		if(iter == NULL){
			return 0;
		}
		if(iter->isWord()){
			if(i == catted.length()-1){
				return 1;
			}
			else if(recFindWord(i+1)){
				spaces.push(i+1);
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	std::fstream fword;
	std::string word;

	fword.open(DICTIONARY);

	while(!fword.eof()){
		std::getline(fword, word, '\n');
		dict.addWord(word);
	}
	
	catted = "thesearethesea";
	//TODO: remove whitespace from catted

	recFindWord(0);

	for(int i = 0; i < catted.length(); i++){
		if(!spaces.empty() && i == spaces.top()){
			std::cout << " ";
			spaces.pop();
		}
		std::cout << catted[i];
	}
	std::cout << std::endl;
}
