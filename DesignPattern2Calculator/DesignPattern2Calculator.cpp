#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Expression_Node.h"
#include "Expression_Tree_Builder.h"
#include "Expression_Tree_Evaluator.h"
#include "Client.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
*   Parses string into a string array.
*   @param: std::string             user input infix expression
*   @return: Array<std::string>      infix expression
*/
Array<string> parse(string infix) {

	// helper variables
    std::stringstream input_stream;
    string token;
    Queue<string> items;

    // tokenize string
    input_stream.clear();
    input_stream.str(infix);
    while(getline(input_stream, token, ' '))
        items.enqueue(token);

    // resultant infix array
    Array<string> arr_infix(items.size());

    // pop all queue items into infix array
    for (int i=0; i<arr_infix.size(); i++) {
        arr_infix[i] = items.dequeue();
    }

    // return infix expression
    return arr_infix;
}

/**
*   Determines if the input string can be converted into an integer.
*   @param: std::string             input string
*   @return: bool=true               input as int is a valid int
*   @return: bool=false              input as int is an invalid int
*/
bool is_integer(string str) {

	const char * chr_lst = str.c_str();

	char * ptr_to_last_ch;

	int rad = 10;

	long value = std::strtol(chr_lst, &ptr_to_last_ch, rad);

	// if the starting character is invalid (i.e. not a '+', '-', nor a digit)
	if (ptr_to_last_ch == chr_lst) {
		// invalid
		return false;
	}
	else if (*ptr_to_last_ch != '\0') {
		// invalid
		return false;
	}
	else {
		if ((int)value != value) {
			return false;
		}
		else {
			return true;
		}
	}
}

/**
*   Runs through the infix string array and makes sure it is valid.
*   @param: Array<std::string>      infix expression
*   @return: bool=true               input is valid
*   @return: bool=false              input is invalid
*/
bool is_valid(Array<string> & infix) {

	// # of opened parenthesis
	int opened = 0;

	// 0: nothing
	// 1: first-parenthesis
	// 2: second-parenthesis
	// 3: operator
	// 4: operand
	int lst_ch_type = 0;

	// while looping through infix array, check for the following:
	// - balanced parenthesis
	// - proper operand/operator/parenthesis placement
	for (int i = 0; i < infix.size(); i++) {

		// check for integer
		if (is_integer(infix[i])) {

			// invalid format if integer follows a
			// second-parenthesis or an operand
			if (lst_ch_type == 2 || lst_ch_type == 4)
				return false;

			lst_ch_type = 4;
		}
		else if (infix[i].size() == 1) {

			// check for operator or parenthesis
			switch (infix[i][0]) {

			case '(':

				// increment number of opened parenthesis
				opened++;

				// invalid format if first-parenthesis follows a
				// second-parenthesis or an operand
				if (lst_ch_type == 2 || lst_ch_type == 4)
					return false;

				// mark current item as first-parenthesis
				lst_ch_type = 1;

				// get out of the switch statement
				break;

			case ')':

				// decrement number of opened parenthesis
				opened--;

				// invalid format if second-parenthesis is the first
				// item or follows a first-parenthesis or an operator
				if (lst_ch_type == 0 || lst_ch_type == 1 || lst_ch_type == 3)
					return false;

				// mark current item as second-parenthesis
				lst_ch_type = 2;

				// get out of the switch statement
				break;

			case '+':
			case '-':
			case '*':
			case '/':
			case '%':

				// invalid format if any of the above operators is the
				// first item or follows a first-parenthesis or an operator
				if (lst_ch_type == 0 || lst_ch_type == 1 || lst_ch_type == 3)
					return false;

				// mark current item as operator
				lst_ch_type = 3;

				// get out of the switch statement
				break;

			default:

				// if none of the above characters was found, the
				// current item must be an invalid character
				return false;
			}

			// else it is a non-integer item of a size longer than 1
		}
		else {

			// invalid item
			return false;
		}
	}

	// if last item is "(" or some operator,
	// then we have an invalid expression
	if (lst_ch_type == 1 || lst_ch_type == 3)
		return false;

	// if opened is more than zero, we have too many "(",
	// if opened is less than zero, we have too many ")"
	if (opened != 0)
		return false;

	return true;
}

/**
*   Returns operator priority to use for order-of-operations
*   @param: std::string             some operator in string format
*   @return: int                     priority level
*/
int op_priority(std::string op) {

	if (op == "%" || op == "/" || op == "*")
		return 2;
	else if (op == "-" || op == "+")
		return 1;
	else
		return 0;
}

/**
*   Creates and returns a new postfix string array from the input infix string array.
*   @param: Array<std::string>      infix expression
*   @return: Queue<std::string>     postfix expression
*/
Queue<string> infix_to_postfix(Array<string> & infix) {

    // easier to push into than Array
    Queue<string> postfix_queue;

    // used to help convert infix to postfix
    Stack<string> postfix_stack;

    // go through infix item-by-item
    for (int i=0; i<infix.size(); i++) {

        // CASE 1 - open parenthesis
        if (infix[i] == "(")

            // place next item on the stack
            postfix_stack.push(infix[i]);

        // CASE 2 - close parenthesis
        else if (infix[i] == ")") {

            // pop stack until we reach the start of this parenthesis
            while (postfix_stack.top() != "(") {

                // transfer top item into queue
                postfix_queue.enqueue(postfix_stack.top());
                postfix_stack.pop();
            }

            // don't forget to pop that open parenthesis!
            postfix_stack.pop();
        }

        // CASE 3 - operators
        else if (infix[i] == "+" || infix[i] == "-" || infix[i] == "*" ||
                infix[i] == "/" || infix[i] == "%") {

            // if stack is empty
            if (postfix_stack.is_empty()) {

                // push onto stack
                postfix_stack.push(infix[i]);

            // if stack contains operators or parenthesis
            } else {

                // note: higher priority means more important
                // pop until priority of stack top is less than current item
                // or if stack becomes empty
                while (!postfix_stack.is_empty() &&
                        op_priority(postfix_stack.top()) >= op_priority(infix[i])) {

                    // pop the top into the queue
                    postfix_queue.enqueue(postfix_stack.top());
                    postfix_stack.pop();
                }

                // push current item onto stack
                postfix_stack.push(infix[i]);
            }
        }

        // CASE 4 - numbers
        else
            // output number into queue
            postfix_queue.enqueue(infix[i]);
    }

    // empty the rest of the stack into the queue
    while (!postfix_stack.is_empty()){

        // pop the top into the queue
        postfix_queue.enqueue(postfix_stack.top());
        postfix_stack.pop();
    }

    // return postfix expression
    return postfix_queue;
}

int main(int argc, char * argv[]) {

	// user input expression
	string exp;

	// builder for infix_to_postfix
    Expression_Tree_Builder builder;

    // evaluator for expression tree
    Expression_Tree_Evaluator evaluator;

	// menu - obtain user input expressions
	cout << "\nWelcome to the Design Pattern Calculator!" << endl;
	cout << "Instructions:" << endl;
	cout << "\t- Type \"QUIT(quit)\" to end your input." << endl;
	cout << "\t- Separate each operator/operand with a space." << endl;
	while (true) {
		cout << "\nPlease enter a mathematical expression: ";

		// user input string
		std::getline(cin, exp);
		if (exp == "QUIT" || exp == "quit")
			break;

		// parse expression into an Array
		Array<string> infix = parse(exp);

		// enqueue valid expression, exception if invalid
		if (is_valid(infix)) {
			// get postfix
			Queue<string> postfix = infix_to_postfix(infix);

			// check for math errors
			try {

				// edge case: single number input
				if (postfix.size() == 1) {
					cout << "Result: " << postfix.dequeue() << endl;
					continue;
				}
				else {
					// build and get expression tree from postfix queue
        			builder.build_expression(postfix);
        			Expression_Node * tree = builder.get_expression();

					int result = evaluator.evaluate(tree);
					// print result
					cout << "The result is: " << result << endl;
				}

			}
			catch (std::overflow_error e) {

				// print exception error and notify
				cout << e.what() << endl;
				cout << "(a result was ignored...)" << endl;
			}
		}
		else
			cout << "Invalid expression format: It was ignored." << endl;
	}

	// wait then quit
	cout << "\nThank you for using Calculator!" << endl;
	cin.ignore();
}