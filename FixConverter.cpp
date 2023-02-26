#pragma once
#include"FixConverter.hpp"

FixConverter::FixConverter()
{
    _op_stack = OperatorStack();
    _input = CharStack();
    _output = CharStack();
    _operands = 0;
    _illegal_characters = false;
}

/// @brief empties the contents of op_stack
void FixConverter::flush_stack()
{
    while (!_op_stack.is_empty())
    {
        _op_stack.pop_operator();
    }
}

/// @brief this method is called to parse each character of the input
/// expression. It determines if a character is an operator, operand, or
/// illegal and handles it accordingly
/// @param c the next character from the input expression
void FixConverter::next_character(char c)
{
    // always push c to input
    _input.pushc(c);
    
    // When c is an operator
    // We support +, -, *, /, and $, as well as ^ as an alternative for
    // exponentiation and % for modulus.
    if (
        c == '+' 
        || c == '-' 
        || c == '*' 
        || c == '/' 
        || c == '$' 
        || c == '^'
        || c == '%'
       )
    {
        // Push operators to the OperatorStack with their scope
        _op_stack.push_operator(c, _operands);
        return;
    }
    
    // When c is an operand
    // valid operands are lowercase letters, uppercase letters, or numbers
    // 0-9
    if (
        ('0' <= c && c <= '9') 
        || ('A' <= c && c <= 'Z') 
        || ('a' <= c && c <= 'z')
       )
    {
        // Operands written directly to output
        _output.pushc(c);
        _operands++;
    }
    
    // If neither an operand nor an operator, is invalid
    else
    {
        // If any illegal character is encountered, set this flag to true
        _illegal_characters = true;
        return;
    }

    // While the number of operands is equal to 2 greater than the scope of
    // the operator at the top of OperatorStack, pop the operator to output
    while (
            ( _operands == (_op_stack.peek_operator_scope() + 2) )
            
            // peek operator scope returns -1 when the stack is empty.
            // this condition is necessary to handle the case where a single
            // operand has been written to output and there are no operators
            // on the stack. This is possible if the input is an invalid 
            // prefix expression that does not lead with an operator, or if
            // the expression is just a single operand, which is a valid
            // expression.
            && !_op_stack.is_empty()
        )
    {
        _output.pushc(_op_stack.pop_operator());
        _operands--;
    }
}

/// @brief checks if the expression has illegal characters
/// @return boolean indicating if the expression has illegal characters
bool FixConverter::has_illegal_characters()
{
    return _illegal_characters;
}

/// @brief checks if the expression is a valid prefix expression
/// @return a boolean indicating whether the input is a valid prefix
/// expression
bool FixConverter::is_valid()
{
    // An expression is valid if the operator stack is empty at the end of
    // processing and the number of operands is 1. We also have to the edge
    // of processing empty lines of whitespace. Empty lines are not invalid
    // so we return true in this case.

    return (_op_stack.is_empty() && _operands <= 1);
}

/// @brief returns the input string
/// @return the input characters in the order they were provided
const char* FixConverter::get_input()
{
    return _input.get_str();
}

/// @brief 
/// @return the output string
const char* FixConverter::get_output()
{
    
    if (_operands == 0) return "";

    return _output.get_str();
}

/// @brief empties the output stack and returns its contents in the reverse
/// order
/// @return the output reversed
const char* FixConverter::get_output_reversed()
{
    if (_output.is_empty()) return "";
    
    char* str = new char[_output.size()];
    int i = 0;
    
    // pop output and store each char in new array
    while (!_output.is_empty())
    {
        str[i] = _output.popc();
        i++;
    }
    return str;
}

int FixConverter::output_length()
{
    return _output.size();
}

/// @brief resets the FixConverter to default state
void FixConverter::reset()
{
    _input.reset();
    _output.reset();
    flush_stack();
    _operands = 0;
    _illegal_characters = false;
}