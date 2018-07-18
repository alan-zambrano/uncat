#include <iostream>
#include <string>
#include "tree.h"
#include "node.h"

Tree::Tree(){
	root = new Node();
}
/*
 *@word - string to be added to the tree by its individual characters.
 *
 *Iterate through the characters in @word and traverse the tree while creating
 *nodes for letters that haven't been added to that particular path yet.
 */
void Tree::addWord(std::string word){
	Node* nodeIter = root;
	for(std::string::iterator it = word.begin(); it != word.end(); ++it){
		nodeIter->addChild(*it, false);
		nodeIter = nodeIter->getChild(*it);
	}
	nodeIter->addChild('$', true);
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
