#pragma once
#include"PreToPostConverter.hpp"

void PreToPostConverter::flush_stack()
{
    while (!_op_stack.is_empty())
    {
        _op_stack.pop_operator();
    }
}

void PreToPostConverter::next_character(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '^')
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
        _is_invalid = true;
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

const char* PreToPostConverter::get_output()
{
    if (_is_invalid)
    {
        return "This expression contains illegal characters.";
    }
    if (_operands == 0) return "";

    if (!_op_stack.is_empty() || _operands != 1)
    {
        return "This is not a valid prefix expression.";
    }

    return _output.get_str();
}

void PreToPostConverter::reset()
{
    _output.reset();
    flush_stack();
    _operands = 0;
    _is_invalid = false;
}