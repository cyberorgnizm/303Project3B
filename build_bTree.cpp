//
//  build_bTree.cpp
//  proj3I_WILL_DIE
//
//  Created by Lucicle on 7/19/16.
//  Copyright © 2016 Lucicle. All rights reserved.
//

#include "build_bTree.h"
#include <vector>
using namespace std;


morse_code::morse_code()
{
    root = NULL;
}

morse_code::~morse_code()
{
    delete_tree();
}

void morse_code::insert(char key, vector<char> code)
{
    insert(key, code, root);
}

/*letter* morse_code::search(char key)
{
    return search(key, root);
}
*/

letter* morse_code::search(vector<char> code)
{
    return search(code, root);
}

void morse_code::delete_tree()
{
    delete_tree(root);
}

void morse_code::delete_tree(letter *leaf)
{
    if (leaf != NULL)
    {
        delete_tree(leaf->left);
        delete_tree(leaf->right);
        delete leaf;
    }
}

void morse_code::insert(char key, vector<char> code, struct letter *leaf)
{
    if(key < leaf->key)
    {
        if(leaf->left != NULL)
            insert(key, code, leaf->left);
        else
        {
            leaf->left = new letter;
            leaf->left->key = key;
            leaf->left->code = code;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (key >= leaf->key)
    {
        if(leaf->right != NULL)
            insert(key, code, leaf->right);
        else
        {
            leaf->right = new letter;
            leaf->right->key = key;
            leaf->right->code = code;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

/*letter* morse_code::search(char key, letter *leaf)
{
    if(leaf != NULL)
    {
        if(key == leaf->key)
            return leaf;
        else if(key < leaf->key)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else
        return NULL;
}
*/

letter* morse_code::search(vector<char> code, letter *leaf)
{
    if(leaf != NULL)
    {
        if(code == leaf->code)
            return leaf;
        else if(code < leaf->code)
            return search(code, leaf->left);
        else
            return search(code, leaf->right);
    }
    else
        return NULL;
}

bool operator > (const vector<char>& other, const vector<char>& rhs)
{
    if(other[0] == '.' && rhs[0] == '_')
        return false;
    else if (other[0] == '_' && rhs[0] == '.')
        return true;
    else
    {
        for (int i = 1; i < other.size(); i++)
        {
            if(other[i] == '.' && rhs[i] == '_')
                return false;
            else if (other[i] == '_' && rhs[i] == '.')
                return true;
        }
    }
    return false;
}

bool operator < (const vector<char>& other, const vector<char>& rhs)
{
    if(other[0] == '_' && rhs[0] == '.')
        return false;
    else if (other[0] == '.' && rhs[0] == '_')
        return true;
    else
    {
        for (int i = 1; i < other.size(); i++)
        {
            if(other[i] == '_' && rhs[i] == '.')
                return false;
            else if (other[i] == '.' && rhs[i] == '_')
                return true;
        }
    }
    return false;
}


bool operator == (const vector<char>& other, const vector<char>& rhs)
{
    int k;
    if (other.size() > rhs.size())
        k = rhs.size();
    else
        k = other.size();
        
    for (int i = 0; i < k; i++)
    {
        if(other[i] > rhs[i] || other[i] < rhs[i])
            return false;
    }
    return true;
}

