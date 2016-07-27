//
//  CS303
//  Project 3B
//
//  Lucile Kull, John Buckley, Jeremy Culbreath
//
//	main.cpp

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "build_bTree.h"
#include "morse.h"
using namespace std;

int main()
{
    morse_code tree;
    string encodedMessage; //Holds morse code encoded message
	string originalMessage; //Holds original message to be encoded or after decoding
	
    //Generates/populates map using english character as a key and the equivilent morse code as value
    //Stores in variable morseMap
    map <char,string> morseMap = populateMap();
    
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
	cout << "Please enter a morse code message ( . and - only, separate letters with spaces ) to decode into plain text:\n--->  ";

	//Get message to be decoded from morse code, store in variable encodedMessage
	string temp; getline(cin, temp);	//clears cin buffer
	getline(cin, encodedMessage);

	//Pass message to decode message, store decoded message in variable originalMessage
	originalMessage = decodeMessage(tree, encodedMessage);

	//Print morse code encoded message
	cout << "The message decoded with morse code is " + originalMessage << endl;
    
    system("pause");
    return 0;
}
