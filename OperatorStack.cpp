#pragma once
#include "OperatorStack.hpp"

void OperatorStack::push_operator(char c, int scope)
{
    // Stack is empty
    if (head == nullptr)
    {
        head = new OperatorNode{c, scope, nullptr};
        tail = head;
        
    }
    else 
    {
        head = new OperatorNode{c, scope, head};
    }
    size++;
}

int OperatorStack::peek_operator_scope()
{
    if (is_empty())
    {
        return -1;
    }
    return head->operator_scope;

}

char OperatorStack::pop_operator()
{
    if (is_empty())
    {
        return '\0';
    }
    size--;
    OperatorNode* old_head = head;
    head = head->next;
    old_head->next = nullptr;
    return old_head->operator_character;
}

bool OperatorStack::is_empty()
{
    return size == 0;
}
