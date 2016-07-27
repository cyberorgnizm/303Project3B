//
//  build_bTree.cpp
//
//  Created by Lucicle on 7/19/16.
//  Copyright © 2016 Lucicle. All rights reserved.
//

#include "build_bTree.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;


morse_code::morse_code()
{
	root = new letter;
	root->key = ' ';
	root->code.push_back(0);
	root->left = NULL;
	root->right = NULL;
}


void morse_code::insert(char key, vector<char> code)
{
	insert(key, code, root); //calls private insert function starting at root
}

letter* morse_code::search(vector<char> code)
{
	return search(code, root);  //calls and returns result of private search function starting at root
}


void morse_code::insert(char key, vector<char> code, struct letter *leaf)
{
	letter* t = new letter;  //build a new node with the data given
	t->key = key;
	t->code = code;
	t->left = t->right = NULL;

	if (leaf->left == NULL && leaf->right == NULL) //if this is the first node (do not enter at root)
	{
		leaf->left = t;
		return;
	}
	while (leaf) //while we haven't inserted yet
	{
		if (code < leaf->code) //go left
		{
			if (leaf->left == NULL) //if you can insert
			{
				leaf->left = t; //do insert!
				break;
			}
			else //if you cant insert, move down the tree
				leaf = leaf->left;
		}

		else //go right
		{
			if (leaf->right == NULL) //if you can insert
			{
			leaf->right = t; //do insert!
			break;
			}
			else
				leaf = leaf->right; //if you cant insert, move down the tree
		}
	}
}



letter* morse_code::search(vector<char> code, letter *leaf)
{
	if (leaf)  //if there is still tree to traverse
	{
		if (code == leaf->code)  //found correct node
			return leaf;
		else if (code < leaf->code)
			return search(code, leaf->left); //recursively traverse left tree until node is found
		else
			return search(code, leaf->right); //recursively traverse right tree until node is found
	}
	else
		return NULL;  //node was not found
}

bool operator >(const vector<char>& other, const vector<char>& rhs)
{
	int k; //we will only traverse the shorter code
	if (other.size() > rhs.size())
		k = rhs.size();
	else
		k = other.size();

	//(dot) is less than (dash)
	{
		for (int i = 0; i < k; i++)  //compare the following characters
		{
			if (other[i] == '.' && rhs[i] == '_')  //if (dot) > (dash)
				return false;  //we know it is not
			else if (other[i] == '_' && rhs[i] == '.')  //if (dash) > (dot)
				return true;  //we know it is
		}
	}
	return false;  //the two codes are equal or rhs is a shorter code
}

bool operator < (const vector<char>& other, const vector<char>& rhs)
{
	//(dot) is less than (dash)
	int k;  //we will only traverse the shorter code
	if (other.size() > rhs.size())
		k = rhs.size();
	else
		k = other.size();

		for (int i = 0; i < k; i++) //compare the next characters of both codes
		{
			if (other[i] == '_' && rhs[i] == '.')  //(dash) < (dot)
				return false;
			else if (other[i] == '.' && rhs[i] == '_')  //(dot) < (dash)
				return true;
		}
	return false; //the two codes are equal or rhs is a shorter code
}


bool operator == (const vector<char>& other, const vector<char>& rhs)
{
	if (other.size() != rhs.size()) //they arent the same size they cant be equal
		return false;

	for (int i = 0; i < other.size(); i++)  //compare each character in the code
	{
		if (other[i] > rhs[i] || other[i] < rhs[i])  //if they are not equal return false
			return false;
	}
	return true;  //compared entire code, they are equal
}

