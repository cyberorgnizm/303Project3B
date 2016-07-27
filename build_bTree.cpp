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

morse_code::~morse_code()
{
	delete_tree();  //calls delete on tree
}

void morse_code::insert(char key, vector<char> code)
{
	insert(key, code, root); //calls private insert function starting at root
}

letter* morse_code::search(vector<char> code)
{
	return search(code, root);  //calls and returns result of private search function starting at root
}

void morse_code::delete_tree()
{
	delete_tree(root);  //calls private delete function starting at root
}

void morse_code::delete_tree(letter *leaf)
{
	if (leaf != NULL) //recursive delete function
	{
		delete_tree(leaf->left); //call delete function on left tree
		delete_tree(leaf->right);  //call delete function on right tree
		delete leaf;  //delete current node
	}
}

void morse_code::insert(char key, vector<char> code, struct letter *leaf)
{
	if (leaf == NULL)
	{
		leaf = new letter; //create new node with correct values
		leaf->key = key;
		leaf->code = code;
		leaf->left = NULL;
		leaf->right = NULL;
	}

	if (code < leaf->code || code == leaf->code) //traverse tree to the left
	{
		insert(key, code, leaf->left); //recursively traverse tree until open correct leaf is found
	}
	else
	{
		insert(key, code, leaf->right); //recursively traverse tree until open correct leaf is found
	}

}



letter* morse_code::search(vector<char> code, letter *leaf)
{
	if (leaf != NULL)  //if there is still tree to traverse
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
	if (other[0] == '.' && rhs[0] == '_') //if (dot) > (dash)
		return false; //(dot) is not > (dash)
	else if (other[0] == '_' && rhs[0] == '.')  //if (dash) > (dot)
		return true; //(dot) is > (dash)
	else //if the first character of both codes is the same
	{
		for (int i = 1; i < k; i++)  //compare the following characters
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

	if (other[0] == '_' && rhs[0] == '.') //if (dash) < (dot)
		return false; //that is incorrect
	else if (other[0] == '.' && rhs[0] == '_')  //(dot) < (dash)
		return true; //that is correct
	else //the first character of both codes is the same (dot) or (dash)
	{
		for (int i = 1; i < k; i++) //compare the next characters of both codes
		{
			if (other[i] == '_' && rhs[i] == '.')  //(dash) < (dot)
				return false;
			else if (other[i] == '.' && rhs[i] == '_')  //(dot) < (dash)
				return true;
		}
	}
	return false; //the two codes are equal or rhs is a shorter code
}


bool operator == (const vector<char>& other, const vector<char>& rhs)
{
	int k;  //we will only traverse the shorter code
	if (other.size() > rhs.size())
		k = rhs.size();
	else
		k = other.size();

	for (int i = 0; i < k; i++)  //compare each character in the code
	{
		if (other[i] > rhs[i] || other[i] < rhs[i])  //if they are not equal return false
			return false;
	}
	return true;  //compared entire code, they are equal
}

