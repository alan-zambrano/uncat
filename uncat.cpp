#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "tree.h"
#include "node.h"

Tree dict;
std::string catted;

void remws(std::string& word){
	for(int i = 0; i < word.length(); i++){
		if(word[i] == ' '){
			word.erase(i);
			i--;
		}
	}
}

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
	std::string fdict;

	std::cout << "Dictionary >> ";
	std::cin >> fdict;

	fword.open(fdict.c_str());

	if(!fword){
		std::cout << "unable to open file" << std::endl;
		return 1;
	}

	while(!fword.eof()){
		std::getline(fword, word, '\n');
		dict.addWord(word);
	}
	
	std::cout << "concatenated string >> ";
	std::cin >> catted;
	
	remws(catted);

	std::cout << recFindWord(0, "") << std::endl;
}
