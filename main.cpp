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
#include <map>
#include "build_bTree.h"
using namespace std;

void build_tree(string file, morse_code& tree);
map <char, string> populateMap(); //Populate map for english char and morse code eqivilent
string encodeMessage(map <char, string> map, string message); //Encode message using morse code

int main()
{
    
    morse_code tree;
    string encodedMessage; //Holds morse code encoded message
    string originalMessage; //Holds original message to be encoded
    
    //Generates/populates map using english character as a key and the equivilent morse code as value
    //Stores in variable morseMap
    map <char,string> morseMap = populateMap();
    
    string file_name = "morse.txt";
    cout << "What is the file you would like to read from?\n--->  ";
    cin >> file_name;
    build_tree(file_name, tree);
    
    cout << "Please enter a message to encode using morse code:\n--->  ";
    
    //Get message to be encoded in morse code, store in variable originalMessage
    cin >> originalMessage;
    
    //Pass message to encode message, store morse code encoded message in variable encodedMessage
    encodedMessage = encodeMessage(morseMap, originalMessage);
    
    //Print morse code encoded message
    cout << "The original message coded with morse code is " + encodedMessage << endl;
    
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

//Generates/populates map using english character as a key and the equivilent morse code as value
map <char, string> populateMap(){
    //Returned map with lower and uppercase chars and equivilent morse code values
    map <char, string> morseMap;
    
    //Lowercase
    morseMap.insert(make_pair('a', ".-"));
    morseMap.insert(make_pair('b', "-..."));
    morseMap.insert(make_pair('c', "-.-."));
    morseMap.insert(make_pair('d', "-.."));
    morseMap.insert(make_pair('e', "."));
    morseMap.insert(make_pair('f', "..-."));
    morseMap.insert(make_pair('g', "--."));
    morseMap.insert(make_pair('h', "...."));
    morseMap.insert(make_pair('i', ".."));
    morseMap.insert(make_pair('j', ".---"));
    morseMap.insert(make_pair('k', "-.-"));
    morseMap.insert(make_pair('l', ".-.."));
    morseMap.insert(make_pair('m', "--"));
    morseMap.insert(make_pair('n', "-."));
    morseMap.insert(make_pair('o', "---"));
    morseMap.insert(make_pair('p', ".--."));
    morseMap.insert(make_pair('q', "--.-"));
    morseMap.insert(make_pair('r', ".-."));
    morseMap.insert(make_pair('s', "..."));
    morseMap.insert(make_pair('t', "-"));
    morseMap.insert(make_pair('u', "..-"));
    morseMap.insert(make_pair('v', "...-"));
    morseMap.insert(make_pair('w', ".--"));
    morseMap.insert(make_pair('x', "-..-"));
    morseMap.insert(make_pair('y', "-.--"));
    morseMap.insert(make_pair('z', "--.."));
    
    //Uppercase
    morseMap.insert(make_pair('A', ".-"));
    morseMap.insert(make_pair('B', "-..."));
    morseMap.insert(make_pair('C', "-.-."));
    morseMap.insert(make_pair('D', "-.."));
    morseMap.insert(make_pair('E', "."));
    morseMap.insert(make_pair('F', "..-."));
    morseMap.insert(make_pair('G', "--."));
    morseMap.insert(make_pair('H', "...."));
    morseMap.insert(make_pair('I', ".."));
    morseMap.insert(make_pair('J', ".---"));
    morseMap.insert(make_pair('K', "-.-"));
    morseMap.insert(make_pair('L', ".-.."));
    morseMap.insert(make_pair('M', "--"));
    morseMap.insert(make_pair('N', "-."));
    morseMap.insert(make_pair('O', "---"));
    morseMap.insert(make_pair('P', ".--."));
    morseMap.insert(make_pair('Q', "--.-"));
    morseMap.insert(make_pair('R', ".-."));
    morseMap.insert(make_pair('S', "..."));
    morseMap.insert(make_pair('T', "-"));
    morseMap.insert(make_pair('U', "..-"));
    morseMap.insert(make_pair('V', "...-"));
    morseMap.insert(make_pair('W', ".--"));
    morseMap.insert(make_pair('X', "-..-"));
    morseMap.insert(make_pair('Y', "-.--"));
    morseMap.insert(make_pair('Z', "--.."));
    
    return morseMap;
}

//Encode message in morse code
string encodeMessage(map <char, string> map, string message){
    
    string tempString; //Holds return string with morse code
    char tempChar; //Holds char to be encoded
    
    //For loop to transverse original message and encode chars
    for (unsigned i=0; i<message.length(); ++i)
    {
        tempChar = message.at(i); //Get char
        
        //Look up morse code value using char and add that value and a space to returned string
        tempString += map.find(tempChar)->second + " ";
    }
    
    return tempString;
}