#include <iostream>
#include <fstream>
#include <string>
#include "tree.h"
#include "node.h"
#include <gtest/gtest.h>

#define DICTIONARY "wordstest.txt"

using testing::Test;

TEST(TreeTest, Caps){
	Tree dict;
	std::fstream fword;
	std::string word;

	fword.open(DICTIONARY);

	while(!fword.eof()){
		std::getline(fword, word, '\n');
		dict.addWord(word);
	}

	EXPECT_TRUE(dict.isWord("tHeSe"));
	EXPECT_TRUE(dict.isWord("Are"));
	EXPECT_TRUE(dict.isWord("soME"));
	EXPECT_TRUE(dict.isWord("eXamPLeS"));
	EXPECT_TRUE(dict.isWord("oF"));
	EXPECT_TRUE(dict.isWord("wOrds"));
}

TEST(TreeTest, FalsePos){
	Tree dict;
	std::fstream fword;
	std::string word;

	fword.open(DICTIONARY);

	while(!fword.eof()){
		std::getline(fword, word, '\n');
		dict.addWord(word);
	}

	EXPECT_FALSE(dict.isWord("lorem"));
	EXPECT_FALSE(dict.isWord("ipsum"));
	EXPECT_FALSE(dict.isWord("neque"));
	EXPECT_FALSE(dict.isWord("porro"));
}

TEST(TreeTest, WordSubsets){	
	Tree dict;
	std::fstream fword;
	std::string word;

	fword.open(DICTIONARY);

	while(!fword.eof()){
		std::getline(fword, word, '\n');
		dict.addWord(word);
	}

	EXPECT_FALSE(dict.isWord("theses"));
	EXPECT_FALSE(dict.isWord("ar"));
	EXPECT_FALSE(dict.isWord("som"));
	EXPECT_FALSE(dict.isWord("example"));
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
