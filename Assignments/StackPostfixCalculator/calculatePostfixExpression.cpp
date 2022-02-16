/*************************************************************
 * Name: Chris Caldwell
 * Date Submitted: 2/15/22
 * Assignment Name: Stack-based Postfix Expression Calculator
 ************************************************************/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

//helper prototype
bool isNum(const string &str);

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length){
    int opLeft, opRight;
    stack<int> postFix;

    if(length == 0) return 0;   //empty expression

    for(int i = 0; i < length; i++){
        if(isNum(expression[i])){
            postFix.push(stoi(expression[i]));
        } else {
            if(postFix.size() < 2) return 0;    //too few operands

            opRight = postFix.top();
            postFix.pop();
            opLeft = postFix.top();
            postFix.pop();

            //determine operator and execute
            switch((char) expression[i][0]){
                case '+':
                    postFix.push(opLeft + opRight); break;
                case '-':
                    postFix.push(opLeft - opRight); break;
                case '*':
                    postFix.push(opLeft * opRight); break;
                case '/':
                    postFix.push(opLeft / opRight); break;
                case '%':
                    postFix.push(opLeft % opRight); break;
                default:
                    cout<<"Something went wrong.";
            }
        }
    }

    if(postFix.size() > 1) return 0;  //indicates there were too few operators

    return postFix.top();
}

//Check that string is a num (operand)
bool isNum(const string &str){
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}