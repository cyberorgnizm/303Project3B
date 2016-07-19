//
//  build_bTree.hpp
//  proj3I_WILL_DIE
//
//  Created by Lucicle on 7/19/16.
//  Copyright © 2016 Lucicle. All rights reserved.
//

#ifndef build_bTree_h
#define build_bTree_h

#include <vector>
using namespace std;

struct letter
{
    char key;
    vector<char> code;
    struct letter *left;
    struct letter *right;
};

class morse_code
{
public:
    morse_code();
    ~morse_code();
    
    void build_tree(string file, morse_code& tree);
    void insert(char key, vector<char> code);
    letter* search(vector<char> code);
    void delete_tree();
    
private:
    void delete_tree(letter *leaf);
    void insert(char key, vector<char> code, struct letter *leaf);
    letter* search(vector<char> code, letter *leaf);
    friend bool operator > (const vector<char>& other, const vector<char>& rhs);
    friend bool operator < (const vector<char>& other, const vector<char>& rhs);
    friend bool operator == (const vector<char>& other, const vector<char>& rhs);
    
    letter *root;
};

#endif /* build_bTree_hpp */
