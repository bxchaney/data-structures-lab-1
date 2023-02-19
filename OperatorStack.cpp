#pragma once
#include "OperatorStack.hpp"

void OperatorStack::push_operator(char c, int scope)
{
    if (size == stack_max_size)
    {
        resize();
    }
    scope_stack[size] = OperatorScope{c, scope};
    size++;
}

int OperatorStack::peek_operator_scope()
{
    if (is_empty())
    {
        return -1;
    }
    return scope_stack[size - 1].operator_scope;

}

char OperatorStack::pop_operator()
{
    if (is_empty())
    {
        return '\0';
    }
    size--;
    return scope_stack[size].op;
}

bool OperatorStack::is_empty()
{
    return size == 0;
}

void OperatorStack::resize()
{
    OperatorScope* old_arr = scope_stack;
    stack_max_size *= 2;
    scope_stack = new OperatorScope[stack_max_size];
    for (int i=0; i < size; i++)
    {
        scope_stack[i] = old_arr[i];
    }
    delete old_arr;
}