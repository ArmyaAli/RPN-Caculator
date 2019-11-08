#include <iostream>
#include <string>
#include <Stack>
#include <vector>

// this will be an RPN or reverse polish notation calculator project created for my own learning
// Author: Ali Umar
// Eventually I want to add a GUI interface which I will most likely create using SFML library, or SDL2 library for graphics. 

// experssion ex: 23--134*
std::string expression;
std::stack<char> expressionStack;

// performs the selected operation depending on the operator {+, -, *, /}
int performOperation(char Operator, int operand_A, int operand_B);
// checks if the character is +,-,/,*
bool isOperator(char c);
// check valid operator
bool isDigit(char c);
bool isNumeric(std::string& s); // isNumeric excluding operators
int main()
{
    int result = 0;
	int operand_A, operand_B;
    // get our expression
    std::cout << "Enter your expression in RPN notation (eg. 23+34-*)" << std::endl;
    std::getline(std::cin, expression);

    while(!isNumeric(expression))
    {
        std::cout << "Please enter valid numbers thanks!" << std::endl;
        std::getline(std::cin, expression);
    }

    for(int i = 0; i < expression.length(); i++)
    {
		if (isOperator(expression[i])) {
			operand_A = expressionStack.top();
			expressionStack.pop();
			operand_B = expressionStack.top();
			expressionStack.pop();
			result = performOperation(expression[i], (int) operand_A - '0', (int) operand_B - '0');
			expressionStack.push(result);
			
		}
		else if(!isOperator(expression[i]))
		{
			expressionStack.push(expression[i]);
		}
        
    }
	result = expressionStack.top();
	expressionStack.pop();

    std::cout << result << std::endl;
	std::cin.get();
    return 0;
}


int performOperation(char Operator, int A, int B)
{
	int retVal = 0;

	switch (Operator)
	{
	case '+':
		retVal = A + B;
		break;
	case '-':
		retVal = A - B;
		break;
	case '*':
		retVal = A * B;
		break;
	case '/':
		retVal = A / B;
		break;
	}

	return retVal;
}
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '/' || c == '*';
}


bool isDigit(char c)
{
    return c >= '0'  && c <= '9';
}

bool isNumeric(std::string& s)
{
    bool retFlag = true;

    for(int i = 0; i < s.length(); i++)
    {   
        if(!isDigit(s[i]) && !isOperator(s[i])) // not an operator or not a digit 
            retFlag = false;
    }

    return retFlag;
}
