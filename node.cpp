#include <iostream>
#include "node.h"
#include <ctype.h> //isalpha(), isupper()
#include <cstdlib> //malloc

Node::Node(){
	value = -1;
	for(int i = 0; i < 28; i++){
		children[i] = NULL;
	}
}
Node::Node(char val){
	value = val;
	for(int i = 0; i < 28; i++){
		children[i] = NULL;
	}
}
Node::Node(char val, Node* par){
	value = val;
	parent = par;
	for(int i = 0; i < 28; i++){
		children[i] = NULL;
	}
}
/*
 *@val - character to be stored in the current node's child.
 *@isEnd - used to check if '$' is at the end of the word. It is not allowed
 *to be added as a child otherwise.
 *
 *Initializes a Node object and inserts it into @children. Node objects store
 *their character value @val in lowercase by default. If there is already
 *something in @children[location], will do nothing and return 0
 *
 *returns: -1 for invalid @val and 0 on success.
 */
int Node::addChild(char val, bool isEnd){
	if(val == '$' && isEnd){
		if(children[27] == NULL){
			children[27] = new Node(val, this);
		}	
	}
	if(val == '.'){
		if(children[26] == NULL){
			children[26] = new Node(val, this);
		}
	}
	else if(isupper(val)){
		if(children[val-65] == NULL){
			children[val-65] = new Node(tolower(val), this);
		}
	}
	else if(islower(val)){
		if(children[val-97] == NULL){
			children[val-97] = new Node(val, this);
		}
	}
	else{
		return -1;
	}
	return 0;
}
/*
 *@val - character id of the child we're looking for.
 *
 *returns: a pointer to the child whose @value matches @val. NULL if it does
 *not exist.
 */
Node* Node::getChild(char val){
	if(val == '$')
		return children[27];
	else if(val == '.')
		return children[26];
	else if(isupper(val))
		return children[val-65];
	else if(islower(val))
		return children[val-97];
}
