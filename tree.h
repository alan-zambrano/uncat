#include <string>
#include "node.h"

#ifndef TREE_H
#define TREE_H

class Tree{
	public:
		Tree();
		int addWord(std::string word);
		bool isWord(std::string word);
		
		Node* root;
};

#endif
