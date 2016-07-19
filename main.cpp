//
//  main.cpp
//  proj3I_WILL_DIE
//
//  Created by Lucicle on 7/19/16.
//  Copyright © 2016 Lucicle. All rights reserved.
//
#include <string>
#include <iostream>
#include <fstream>
#include "build_bTree.h"
using namespace std;

void build_tree(string file, morse_code& tree);

int main()
{
    morse_code tree;
    string file_name = "morse.txt";
    cout << "What is the file you would like to read from?\n--->  ";
    cin >> file_name;
    build_tree(file_name, tree);
    system("pause");
    return 0;
}


void build_tree(string file, morse_code& tree)
{
    cout << "...building tree..."<<endl;
    ifstream fin(file);
    string whole_line;
    char key_hold;
    vector<char> code_hold;
    while (!fin.eof())
    {
        getline(fin, whole_line);
        key_hold = whole_line[0];
        for (int i = 1; i < whole_line.size(); i++)
            code_hold.push_back(whole_line[i]);
        tree.insert(key_hold, code_hold);
    }
}