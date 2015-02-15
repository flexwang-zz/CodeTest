/*
 ﻿People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.
 Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?
 Input Specification:
 Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return '\n'. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].
 Output Specification:
 For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.
 Note that words are case insensitive.
 Sample Input:
 Can1: "Can a can can a can?  It can!"

 Sample Output:
 can 5
 */
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<sstream>

using namespace std;

class TreeNode {
public:
	string s;
	int noccurence;
	TreeNode *right, *left;

	TreeNode() :
			noccurence(0) {
	}
	TreeNode(string str) :
			s(str), noccurence(1), right(NULL), left(NULL) {
	}
};

class Tree {
public:
	TreeNode * head;
	int maxoccurence;
	string pattern;

	Tree() :
			head(NULL), maxoccurence(0), pattern("") {
	}

	void insert(string s) {
		_insert(s, head);
	}

	void _insert(string s, TreeNode* &node) {
		if (!node) {
			node = new TreeNode(s);
			if (node->noccurence > maxoccurence
					|| (node->noccurence == maxoccurence
							&& strcmp(node->s.c_str(), pattern.c_str()) < 0)) {
				maxoccurence = node->noccurence;
				pattern = node->s;
			}
			return;
		}

		int dif = strcmp(s.c_str(), node->s.c_str());
		if (dif < 0) {
			_insert(s, node->left);
		} else if (dif > 0) {
			_insert(s, node->right);
		} else {
			node->noccurence++;
			if (node->noccurence > maxoccurence
					|| (node->noccurence == maxoccurence
							&& strcmp(node->s.c_str(), pattern.c_str()) < 0)) {
				maxoccurence = node->noccurence;
				pattern = node->s;
			}
		}
	}
};

int main() {
	Tree tree;
	string input;

	getline(cin, input);

	int len = strlen(input.c_str());

	char word[1000];
	int index = 0;
	for (int i = 0; i <= len; i++) {
		char ch = input.c_str()[i];

		if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z'
				|| ch >= 'A' && ch <= 'Z') {
			word[index++] = (ch >= 'A' && ch <= 'Z') ? (ch + 'a' - 'A') : ch;
		} else {
			word[index] = '\0';
			if (index > 0) {
				tree.insert(string(word));
			}

			index = 0;
		}
	}

	cout << tree.pattern << " " << tree.maxoccurence;

//  system("pause");

	return 0;
}

