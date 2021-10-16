#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Fuction to check if the top of the stack matches the closing bracket
// Returns 1 if brackets match or else 0
int match(char a,char b)
{
	if(a == '(' && b == ')')
    {
        return 1;
    }
	else if(a == '{' && b == '}')
    { 
        return 1;
    }
	else if(a == '[' && b == ']')
    { 
        return 1;
    }
	return 0;
}

// Function to traverse through the expression and check if the brackets match
bool check_balance(string exp)
{
	stack<char> s; //Creating an object s from inbuilt stack 
	for(int i=0;i<exp.length();i++)
	{
        //If its opening bracket then push into stack
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
			s.push(exp[i]); 
        }
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
            // If the stack is empty or the top of the stack doesnt match the closing bracket then expression is unbalanced
			if(s.empty() || !match(s.top(),exp[i])) 
            {
				return false;
            }
			else
            {
				s.pop();
            }
		}
	}
    // If all the brackets match and the stack is empty then the expression has balanced parenthesis
    // Or else expression contains some brackets which dont have corresponding closing bracket
	return s.empty() == 1; 
}

int main()
{
	string s;
	cout<<"Enter expression:  "; 
	cin>>s;
	if(check_balance(s))
    {
		cout<<"Balanced expression"<<endl;
    }
	else
    {
		cout<<"Unbalanced expression"<<endl;
    }
}