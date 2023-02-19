#pragma once
#include "OperatorStack.hpp"

void OperatorStack::push_operator(char c, int scope)
{
    // Stack is empty
    if (_head == nullptr)
    {
        _head = new OperatorNode{c, scope, nullptr};
        _tail = _head;
        
    }
    else 
    {
        _head = new OperatorNode{c, scope, _head};
    }
    _size++;
}

int OperatorStack::peek_operator_scope()
{
    if (is_empty())
    {
        return -1;
    }
    return _head->operator_scope;
}

char OperatorStack::pop_operator()
{
    if (is_empty())
    {
        return '\0';
    }
    _size--;
    OperatorNode* old_head = _head;
    _head = _head->next;
    old_head->next = nullptr;
    return old_head->operator_character;
}

bool OperatorStack::is_empty()
{
    return _size == 0;
}