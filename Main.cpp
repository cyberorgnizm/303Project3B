//  303Project2A
//  John Buckley, Lucy Kull, Jeremy Culbreath
//
// Main.cpp

/* Replace the expression in quotation marks on line 18 to evaluate a different expression */

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>
#include "Evaluator.h"
#include "infix_validation.h"
using namespace std;

int main(){
	string expression = "!!!3+2";		// <--- Replace the expression in quotation marks - original "!!!3+2"

	cout << "Infix Expression Solver " << endl << endl			//program info
		 << "Expression: " << expression << endl << endl;		//prints expression prior to solving

	if (expression != ""){
		string temp = "";												//remove all spaces for efficiency
		for (int i = 0; expression[i]; i++) if (expression[i] != ' ') temp += expression[i];
		expression = temp;
	}

	if (infix_valid(expression) == 1){							//if not a valid expression, do not process
		cout << "Expression is not valid." << endl << endl;		//let user know not valid
	}

	else{
		Evaluator eval (expression);						
		int result = eval.Process(expression);				//evaluates expression
		cout << "Result: " << result << endl << endl;		//prints result
	} 

	system("Pause");		//pause to see program output
	return 0;
}
