/*
The OpeatorStack is a linked list implementation of a stack where each node
stores an operator as a char and the scope of that operator as an integer.
The scope of the operator is the number of operands at that point in the 
expression, so later on, the operator is popped from the stack when the
number of operands is 2 greater than the scope of the top operator.

This module supports the following interface:

void push_operator(char, int)
    
    input: a char of one of the supported operators, an int >= 0 representing
        the scope of that operator.
    
    precondition: None
    
    process: Creates new instance of OperatorStack::OperatorNode with the 
            provided char and int as its values. Pushes this node to the top
            of the stack.
    
    postcondition: None
    
    output: None

int peek_operator_scope()

    input: None

    precondition: the stack is non-empty. If the stack is empty, returns -1,
    an impossible value for an operator's scope.

    process: returns without removing the operator_scope field of the 
    OperatorStack::OperatorNode at the top of the stack.

    postconditon: None

    Ouput: the integer value of the operator_scope field of the 
    OperatorStack::OperatorNode at the top of the stack. -1 if the stack is
    empty.

char pop_operator()

    input: None

    precondition: the stack is non-empty. If the stack is empty, returns 
    '\0', the null character.

    process: removes the top node from the stack and returns the char value
    held in that node's operator_character field.

    postcondition: None

    output: the operator_character value held by the
    OperatorStack::OperatorNode that was previously at the top of the stack.

bool is_empty()

    input: None

    precondition: None

    process: checks if the stack is empty.

    postcondition: None

    output: a boolean value indicating whether the stack is empty.


*/

#pragma once

class OperatorStack
{

    private:

        struct OperatorNode
        {
            char operator_character;
            int operator_scope;
            OperatorNode* next;

            ~OperatorNode();
        };
        
        OperatorNode* _head;
        OperatorNode* _tail;
        int _size;

    public: 

        OperatorStack();
        ~OperatorStack();

        void push_operator(char c, int scope);
        int peek_operator_scope();
        char pop_operator();
        bool is_empty();

};