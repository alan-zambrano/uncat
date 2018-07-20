#include <string>
#include "node.h"

#ifndef TREE_H
#define TREE_H

class Tree{
	public:
		Tree();
		void iterReset();
		void percolate(char c);
		void percolateTo(std::string word);
		void addWord(std::string word);
		bool isWord(std::string word);
		
		Node* root;
		Node* iter;
};

#endif
