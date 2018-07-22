#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "tree.h"
#include "node.h"

#define DICTIONARY "test.txt"

Tree dict;
std::string catted;

int recFindWord(int i, std::string word){
	Node* iter = dict.root;
	iter = iter->getChild(catted[i]);
	bool ret = 0;

	for(; i < catted.length(); ++i, iter = iter->getChild(catted[i])){
		if(iter == NULL){
			return 0;
		}
		word += iter->value;
		if(iter->isWord()){
			if(i == catted.length()-1){
				std::cout << word << std::endl;
				return 1;
			}
			recFindWord(i+1, word + " ");
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
	
	catted = "someare";
	//TODO: remove whitespace from catted

	std::cout << recFindWord(0, "") << std::endl;
	/*
	while(!spaces.empty()){
		for(int i = 0; i < catted.length(); i++){
			if(!spaces.empty() && i == spaces.top()){
				std::cout << " ";
				spaces.pop();
			}
			std::cout << catted[i];
		}
		std::cout << std::endl;
	}
	*/
}
