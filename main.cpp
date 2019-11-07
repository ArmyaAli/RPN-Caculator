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
int performOperation(char Operator, std::vector<int>& operands);
// checks if the character is +,-,/,*
bool isOperator(char c);
// check valid operator
bool isDigit(char c);
bool isNumeric(std::string& s); // isNumeric excluding operators
int main()
{
    std::vector<int> temp;
    int result = 0;
    // get our expression
    std::cout << "Enter your expression in RPN notation (eg. 23+34-*)" << std::endl;
    std::getline(std::cin, expression);

    while(!isNumeric(expression))
    {
        std::cout << "Please enter valid numbers thanks!" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, expression);
    }

    for(int i = 0; i < expression.length(); i++)
    {
        // first add to our stack till we hit an oeprator
        if(!isOperator(expression[i]))
            expressionStack.push(expression[i] - '0');
        else
        {
            while(!expressionStack.empty())
            {
                 temp.push_back(expressionStack.top());
                 expressionStack.pop();
            }
            result = performOperation(expression[i], temp);
            expressionStack.push(result);
            temp.erase(temp.begin(), temp.end()); // delete our temp array
            
        }
        
    }

    std::cout << result << std::endl;
    return 0;
}

int performOperation(char Operator, std::vector<int>& operands)
{
    int retVal = 0;

    switch(Operator)
    {
        case '+':
        for(int i = 0; i < operands.size(); i++)
            retVal += operands[i];
        break;
        case '-':
        retVal = operands[0];
        for(int i = 1; i < operands.size(); i++)
             retVal -= operands[i];
        break;
        case '*':
        retVal = 1;
        for(int i = 0; i < operands.size(); i++)
            retVal *= operands[i];
        break;
        case '/':
        retVal = 1;
        for(int i = 0; i < operands.size(); i++)    // integer division to do
            retVal /= operands[i];
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
