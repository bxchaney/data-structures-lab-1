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

void FixConverter::flush_stack()
{
    while (!_op_stack.is_empty())
    {
        _op_stack.pop_operator();
    }
}

void FixConverter::next_character(char c)
{
    _input.pushc(c);
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
        _op_stack.push_operator(c, _operands);
        return;
    }
    if (
        ('0' <= c && c <= '9') 
        || ('A' <= c && c <= 'Z') 
        || ('a' <= c && c <= 'z')
       )
    {
        _output.pushc(c);
        _operands++;
    }
    else
    {
        _illegal_characters = true;
        return;
    }

    while (
            ( _operands == (_op_stack.peek_operator_scope() + 2) )
            && !_op_stack.is_empty()
        )
    {
        _output.pushc(_op_stack.pop_operator());
        _operands--;
    }
}

bool FixConverter::has_illegal_characters()
{
    return _illegal_characters;
}

bool FixConverter::is_valid()
{
    // An expression is valid if the operator stack is empty at the end of
    // processing and the number of operands is 1. We also have to the edge
    // of processing empty lines of whitespace. Empty lines are not invalid
    // so we return true in this case.

    return (_op_stack.is_empty() && _operands <= 1);
}

const char* FixConverter::get_input()
{
    return _input.get_str();
}

const char* FixConverter::get_output()
{
    
    if (_operands == 0) return "";

    return _output.get_str();
}

int FixConverter::output_length()
{
    return _output.size();
}

void FixConverter::reset()
{
    _input.reset();
    _output.reset();
    flush_stack();
    _operands = 0;
    _illegal_characters = false;
}