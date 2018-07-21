#ifndef NODE_H
#define NODE_H

class Node{
	public:
		Node();
		Node(char val);
		Node(char val, Node* par);
		int addChild(char val, bool isEnd);
		Node* getChild(char val);
		bool isWord();

		char value;
		Node* parent;
		//array of pointers of the current node's children
		//0-25: letters 'a'-'z'
		//26: special char '.'
		//27: end of word delimiter '$'
		Node* children[28];
};

#endif
