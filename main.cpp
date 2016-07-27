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
string decodeMessage(morse_code tree, string message); //Decode message from morse code into plain text


int main()
{
<<<<<<< HEAD
    
    morse_code tree;
    string encodedMessage; //Holds morse code encoded message
    string originalMessage; //Holds original message to be encoded or after decoding
    
    
    //Generates/populates map using english character as a key and the equivilent morse code as value
    //Stores in variable morseMap
    map <char, string> morseMap = populateMap();
    
    string file_name = "morse.txt";
    cout << "What is the file you would like to read from?\n--->  ";
    cin >> file_name;
    build_tree(file_name, tree);
    
    
    /* This encodes a message from plain text to morse code */
    cout << "Please enter a message to encode using morse code:\n--->  ";
    
    //Get message to be encoded in morse code, store in variable originalMessage
    cin >> originalMessage;
    
    //Pass message to encode message, store morse code encoded message in variable encodedMessage
    encodedMessage = encodeMessage(morseMap, originalMessage);
    
    //Print morse code encoded message
    cout << "The original message coded with morse code is " + encodedMessage << endl;
    
    
    /* This decodes a message from morse code to plain text */
    cout << "Please enter a morse code message ( . and _ only, separate letters with spaces ) to decode into plain text:\n--->  ";
    
    //Get message to be decoded from morse code, store in variable encodedMessage
    string temp; getline(cin, temp);	//clears cin buffer
    getline(cin, encodedMessage);
    
    //Pass message to decode message, store decoded message in variable originalMessage
    originalMessage = decodeMessage(tree, encodedMessage);
    
    //Print morse code encoded message
    cout << "The message decoded with morse code is " + originalMessage << endl;
    
    system("pause");
    return 0;
=======

	morse_code tree;
	string encodedMessage; //Holds morse code encoded message
	string originalMessage; //Holds original message to be encoded or after decoding


	//Generates/populates map using english character as a key and the equivilent morse code as value
	//Stores in variable morseMap
	map <char, string> morseMap = populateMap();

	string file_name = "morse.txt";
	cout << "What is the file you would like to read from?\n--->  ";
	cin >> file_name;
	build_tree(file_name, tree);


	/* This encodes a message from plain text to morse code */
	cout << "Please enter a message to encode using morse code:\n--->  ";

	//Get message to be encoded in morse code, store in variable originalMessage
	cin >> originalMessage;

	//Pass message to encode message, store morse code encoded message in variable encodedMessage
	encodedMessage = encodeMessage(morseMap, originalMessage);

	//Print morse code encoded message
	cout << "The original message coded with morse code is " + encodedMessage << endl;


	/* This decodes a message from morse code to plain text */
	cout << "Please enter a morse code message ( . and _ only, separate letters with spaces ) to decode into plain text:\n--->  ";

	//Get message to be decoded from morse code, store in variable encodedMessage
	string temp; getline(cin, temp);	//clears cin buffer
	getline(cin, encodedMessage);
	
	//Pass message to decode message, store decoded message in variable originalMessage
	originalMessage = decodeMessage(tree, encodedMessage);

	//Print morse code encoded message
	cout << "The message decoded with morse code is " + originalMessage << endl;

	system("pause");
	return 0;
>>>>>>> origin/master
}


void build_tree(string file, morse_code& tree)  //builds tree given input file and tree root
{
<<<<<<< HEAD
    cout << "...building tree..." << endl;  //output to let the user know their input worked
    ifstream fin(file); //file where the tree is kept
    string whole_line;  //variable for each line of the file
    char key_hold;  //the character that corresponds with each code
    vector<char> code_hold;  //the code that corresponds which each character
    while (!fin.eof())  //read whole file
    {
        getline(fin, whole_line);  //read in whole line of file
        key_hold = whole_line[0];  //parse line into character and code
        for (int i = 1; i < whole_line.size(); i++)
            code_hold.push_back(whole_line[i]);
        tree.insert(key_hold, code_hold);  //put code/character combo into tree in order
        code_hold.clear();
    }
=======
	cout << "...building tree..." << endl;  //output to let the user know their input worked
	ifstream fin(file); //file where the tree is kept
	string whole_line;  //variable for each line of the file
	char key_hold;  //the character that corresponds with each code
	vector<char> code_hold;  //the code that corresponds which each character
	while (!fin.eof())  //read whole file
	{
		getline(fin, whole_line);  //read in whole line of file
		key_hold = whole_line[0];  //parse line into character and code
		for (int i = 1; i < whole_line.size(); i++)
			code_hold.push_back(whole_line[i]);
		tree.insert(key_hold, code_hold);  //put code/character combo into tree in order
		code_hold.clear();
	}
>>>>>>> origin/master
}

//Generates/populates map using english character as a key and the equivilent morse code as value
map <char, string> populateMap(){
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master
}

//Encode message in morse code
string encodeMessage(map <char, string> map, string message){
<<<<<<< HEAD
    
    string tempString; //Holds return string with morse code
    char tempChar; //Holds char to be encoded
    
    //For loop to transverse original message and encode chars
    for (unsigned i = 0; i<message.length(); ++i)
    {
        tempChar = message.at(i); //Get char
        
        //Look up morse code value using char and add that value and a space to returned string
        tempString += map.find(tempChar)->second + " ";
    }
    
    return tempString;
=======

	string tempString; //Holds return string with morse code
	char tempChar; //Holds char to be encoded

	//For loop to transverse original message and encode chars
	for (unsigned i = 0; i<message.length(); ++i)
	{
		tempChar = message.at(i); //Get char

		//Look up morse code value using char and add that value and a space to returned string
		tempString += map.find(tempChar)->second + " ";
	}

	return tempString;
>>>>>>> origin/master
}


//Decode message from morse code into plain text
string decodeMessage(morse_code tree, string encoded) {
<<<<<<< HEAD
    vector <char> decodeThis;	//holds letter of morse code to decode
    string message; //holds return string with plain text
    char decoded;	//holds decoded letter
    
    //goes through encoded message, adds characters to letter to be decoded, decodes letter and adds to message
    for (int i = 0; i < encoded.size() + 1; i++) {		//goes through entire message
        if ((encoded[i] == ' ') || (i == encoded.size())) {	// if this character is a space or the last character
            
            decoded = tree.search(decodeThis)->key; //decode letter
            decodeThis.clear();		// then clear the letter
            message += decoded;//add decoded letter to the decoded message
            
            if (encoded[i] == ' ') i++;					//go to next character if it is a space
            
        }
        decodeThis.push_back(encoded[i]);	//adds character to morse code letter
        
    }
    return message;
}
=======
	vector <char> decodeThis;	//holds letter of morse code to decode
	string message; //holds return string with plain text
	char decoded;	//holds decoded letter

	//goes through encoded message, adds characters to letter to be decoded, decodes letter and adds to message
	for (int i = 0; i < encoded.size() + 1; i++) {		//goes through entire message
		if ((encoded[i] == ' ') || (i == encoded.size())) {	// if this character is a space or the last character

			decoded = tree.search(decodeThis)->key; //decode letter
			decodeThis.clear();		// then clear the letter
			message += decoded;//add decoded letter to the decoded message

			if (encoded[i] == ' ') i++;					//go to next character if it is a space

		}
		decodeThis.push_back(encoded[i]);	//adds character to morse code letter

	}
	return message;
}
>>>>>>> origin/master
