/*
FixConverter uses OperatorStack and CharStack to process each character of
the prefix expression to postfix and most of the logic for processing each
expression is stored in this module, the main method being next_character.

To explain how this module parses each expression, consider the following
following cases.

1) +AB

To convert each prefix expression, we track the number of operands as well
as the scope of each operator where the scope of an operator is the number of
operators when we arrive at that operator.

In the case of +AB, we begin with no operands and read the '+' first. '+' is
pushed onto the OperatorStack along with its scope, which is 0 in this case.
We then check if the number of operands is equal to 2 greater than the scope
of the operator at the top of the stack. 2 + 0 != 0 so we continue. 

We then read 'A'. This is an operand so it is sent directly to output. We now
have 1 operand in the output. The scope of the top operator in OperatorStack
is still 0 and 2 + 0 != 1 so we do not pop OperatorStack and we continue
reading our expression. 

We read 'B'. This is an operand so it is sentdirectly to output. The number
of operators is now equal to 2 greater than the scope of the operator at the
top of OperatorStack so we pop that operator and write it to output. AB+ is 
a complete expression that evaluates to a single value, so AB+ is itself a
single operand. We decrement the number of operands from 2 to 1.

There are no more characters to read, OperatorStack is empty, and the total
number of operands is 1 so this was a successful parse.

2) +-AB*CD

In this case, similar to (1) when we read '+', and '-' first, there are no
operands so '+' then '-' are pushed to OperatorStack with scope = 0

We then read 'A' and write to output; number of operands is 1 -> A
We read 'B' and write to output; number of operands is 2 -> AB

The number of operands is equal to 2 greater than the scope of '-', the 
operator at the top of our stack. We pop '-' to output. AB- make a complete
expression so the number of operands is decremented from 2 to 1. We check if
the number of operands is equal to 2 greater than the scope of the operator
at the top of OperatorStack. '+' is now at the top of the stack and has scope
0 so we continue. -> AB-

We read '*'. This is an operator, so we push to OperatorStack with its scope,
which is 1 because there is currently 1 operand in output. 

We read 'C' and write to output; the number of operands is 2 -> AB-C
We read 'D' and write to output; the number of operands is 3 -> AB-CD

The number of operands is equal to 2 greater than the scope of the operator
at the top of the stack, so we pop '*' to output and reduce the number of 
operands from 3 to 2. Again, the number of operands is equal to 2 greater
than the scope of the top operator of the stack, '+', so we pop '+' to 
output. -> AB-CD*+


An expression is not a valid prefix expression if there are still operators
in OperatorStack , or if the number of operands is not 1 when we finish
reading an expression

FixConverter has the following public interface:

void next_character(char)

    Input: the next character being read from input

    Precondition: None

    Process: Determines if the input is an operator, operand, or illegal
    cahracter and appropriately handles it.

    Postcondition: None

    Output: None

bool has_illegal_characters()

    Input: None

    Precondition: We have pushed all characters for this expression to
    FixConverter.

    Process: Checks if there are any illegal characters in the input

    Postcondition:

    Ouput: Boolean value indicating whether there are any illegal characters

bool is_valid()

    Input: None

    Precondition: We have pushed all characters for this expression to
    FixConverter.

    Process: Confirms that the OperatorStack is empty and the number of
    operands is at most 1

    Postcondition: None

    Output: Boolean value indicating whether the expression was valid.

const char* get_input()

    Input: None

    Precondition: None

    Process: Gets the string of characters processed in the order they were
    pushed

    Postcondition: None

    Output: a character array of the input values

const char* get_output()

    Input: None

    Precondition: The inputs resulted in a valid string with no illegal
    characters

    Process: Gets the string of characters written to output in the order
    they were pushed

    Postcondition: None

    Output: The output expression.

const char* get_output_reversed()

    Input: None

    Precondition: The inputs resulted in a valid string with no illegal
    characters

    Process: Pops the CharStack used to store the output and stores the 
    values in reverse order in a new string

    Postcondition: the CharStack used as output is now empty.

    Output: the parsed output string reversed

int output_length()

    Input: None

    Precondition: None

    Process: gets the number of items in the output string

    Postcondition: None

    Output: the number of characters in the output string

void reset()

    Input: None

    Precondition: None

    Process: resets the FixConverter to default state

    PostCondition: The object is set to default

    Output: None
*/

#pragma once
#include"OperatorStack.cpp"
#include"CharStack.cpp"

class FixConverter
{
    private:
        OperatorStack _op_stack;
        CharStack _input;
        CharStack _output;
        int _operands;
        bool _illegal_characters;

    void flush_stack();

    public:    
        FixConverter();

        void next_character(char c);
        bool has_illegal_characters();
        bool is_valid();
        const char* get_input();
        const char* get_output();
        const char* get_output_reversed();
        int output_length();
        void reset();

};