#pragma once
#include"PreToPostConverter.hpp"

void PreToPostConverter::next_character(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '^')
    {
        _op_stack.push_operator(c, _operands);
        return;
    }
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
    {
        _output.pushc(c);
        _operands++;
    }
    else
    {
        _is_invalid = true;
        return;
    }

    while (_operands == (_op_stack.peek_operator_scope() + 2))
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

    if (!_op_stack.is_empty() || _operands != 1)
    {
        return "This expression does not have the correct number of operators"
               "or operands.";
    }

    return _output.get_str();
}