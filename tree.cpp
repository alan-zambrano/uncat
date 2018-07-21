#include <iostream>
#include <string>
#include <ctype.h>
#include "tree.h"
#include "node.h"

Tree::Tree(){
	root = new Node(-1);
}

/*
 *@word - string to be added to the tree by its individual characters.
 *
 *Iterate through the characters in @word and traverse the tree while creating
 *nodes for letters that haven't been added to that particular path yet.
 *
 *return: -1 if the string contains any invalid characters, 0 on success.
 */
int Tree::addWord(std::string word){
	Node* nodeIter = root;
	for(int i = 0; i < word.length(); i++){
		if(!isupper(word[i]) &&
		!islower(word[i]) &&
		word[i] != '$' &&
		word[i] != '.'){
			return -1;
		}
	}
	for(std::string::iterator it = word.begin(); it != word.end(); ++it){
		if(nodeIter->addChild(*it, false) == -1){
			std::cout << "invalid character in " << *it << std::endl;
		}
		nodeIter = nodeIter->getChild(*it);
	}
	nodeIter->addChild('$', true);
	return 0;
}

bool Tree::isWord(std::string word){
	Node* nodeIter = root;
	for(std::string::iterator it = word.begin(); it != word.end(); ++it){
		nodeIter = nodeIter->getChild(*it);
		if(nodeIter == NULL){
			return false;
		}
	}
	if(nodeIter->getChild('$')){
		return true;
	}
}
