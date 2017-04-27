#include "Expression.hpp"
#include "StringUtil.hpp"

#include <stack>
#include <iostream>
using namespace std;

//! Set m_ptrRoot to nullptr
Expression::Expression() // done
{
    m_ptrRoot = nullptr;
}

//! If m_ptrRoot is not nullptr, then delete it.
Expression::~Expression() // done
{
    if ( m_ptrRoot != nullptr )
    {
        delete m_ptrRoot;
    }
}

//! Calls the Parse method to parse the given expression.
void Expression::SetPostfixExpression( const string& postfixExp ) // done
{
    ParsePostfixExpression( postfixExp );
}

//! Steps through the expression string and turns it into an expression tree.
/**
    For each character, determine if it is a space (skip it), an operator (+, -, *, /, or ^), or an operand (everything else).

    For an Operator:
    - Create a new ExpNode dynamic object and set its value to the current letter from the postfixExp.
    - The top-most item of the stack will become this node's RIGHT child
    - The 2nd-top-most item of the stack will become this node's LEFT child
    - (Afterward, the top and 2nd-top nodes will be removed from the stack)
    - Push the new node onto the stack.

    For an Operand:
    - Create a new ExpNode dynamic object and set its value to the current letter from the postfixExp.
    - Push the new node onto the stack.

    Once done parsing the string, set the m_ptrRoot to the top item of the stack.

    @param postfixExp <const string&>
    @return <void>
*/
void Expression::ParsePostfixExpression( const string& postfixExp )
{
    stack<ExpNode*> nodes;

    for ( unsigned int i = 0; i < postfixExp.size(); i++ )
    {
		if (postfixExp[i] == ' ')
		{
			continue;
		}
		else if (postfixExp[i] == '+' || postfixExp[i] == '-' || postfixExp[i] == '*' || postfixExp[i] == '/' || postfixExp[i] == '^')
		{
			ExpNode* sign = new ExpNode;
			*sign = postfixExp[i];
			sign->ptrRight = nodes.top();
			nodes.pop();
			sign->ptrLeft = nodes.top();
			nodes.pop();
			nodes.push(sign);
		}
		else
		{
			ExpNode* op = new ExpNode(postfixExp[i]);
			nodes.push(op);
		}
    }
	m_ptrRoot = nodes.top();
}

//! Return true if the given char is a math operator, false otherwise.
bool Expression::IsOperator( char value ) // done
{
    return ( value == '+' || value == '-'
        || value == '*' || value == '/' || value == '^' );
}


//! Returns the expression in postfix format
/**
    Return the result of the GetPostfix recursive method. Begin from the root node.
    @return <string>
*/
string Expression::GetPostfix()
{
    return GetPostfix(m_ptrRoot); // temp
}

//! Recursive function that will build the string for the given node and its left/right children in postfix order.
/**
    Terminating case: If the node is nullptr, then return an empty string.

    Recursing case: build a new string in postfix order, calling GetPostfix on left
        and right children to add their values and add the current node's value.

    @param node <ExpNode*>
    @return <string>
*/
string Expression::GetPostfix( ExpNode* node )
{
	if (node == nullptr)
	{
		return "";
	}

	return GetPostfix(node->ptrLeft) + GetPostfix(node->ptrRight) + node->value;
}

//! Returns the expression in infix format
/**
    Return the result of the GetInfix recursive method. Begin from the root node.
    @return <string>
*/
string Expression::GetInfix()
{
    return GetInfix(m_ptrRoot); // temp
}

//! Recursive function that will build the string for the given node and its left/right children in infix order.
/**
    Terminating case: If the node is nullptr, then return an empty string.

    Recursing case: build a new string in infix order, calling GetInfix on left
        and right children to add their values and add the current node's value.

    @param node <ExpNode*>
    @return <string>
*/
string Expression::GetInfix( ExpNode* node )
{
	if (node == nullptr)
	{
		return "";
	}
	return GetInfix(node->ptrLeft) + node->value + GetInfix(node->ptrRight);

}
