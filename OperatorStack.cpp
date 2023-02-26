#pragma once
#include "OperatorStack.hpp"


/// @brief This destructor recursively deletes all nodes after this node
/// until it reaches a node with next being the null pointer
OperatorStack::OperatorNode::~OperatorNode()
{
    if (next != nullptr)
    {
        
        // Delete references from bottom of the stack to the top.
        // must manually delete all nodes allocated on the heap.
        next->~OperatorNode();
        delete next;
    }
}

OperatorStack::OperatorStack()
{
    // all fields initialized to 0 values
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

OperatorStack::~OperatorStack()
{
    
    // ensure the tail is not still referring to a node.
    _tail = nullptr;
    
    // if stack is non-empty, delete all nodes.
    // must manually delete all nodes allocated on the heap.
    if (_head != nullptr)
    {  
        _head->~OperatorNode();
        delete _head;
    }
}

/// @brief pushes a new OperatorStack::OperatorNode to the top of the stack
/// with c as its operator_character value and scope as its operator_scope
/// value.
/// @param c an operator. E.g. '+', '-', or '%'.
/// @param scope the scope of the operator c.
void OperatorStack::push_operator(char c, int scope)
{
    // Stack is empty
    if (_head == nullptr)
    {
        // head points to new node, new node's next is null
        // node is allocated on the heap
        _head = new OperatorNode{c, scope, nullptr};
        
        // tail points to same node as head
        _tail = _head;
        
    }
    else 
    {
        // stack is non-empty
        // head points to new node, new node points to the previous head.
        // node is allocated on the heap
        _head = new OperatorNode{c, scope, _head};
    }
    _size++;
}

/// @brief This method returns without removing the operator_scope value of
/// the OperatorStack::OperatorNode at the top of the stack.
/// @return the scope of the operator at the top of the stack. If the stack
/// is empty, returns -1.
int OperatorStack::peek_operator_scope()
{
    if (is_empty())
    {
        return -1;
    }
    return _head->operator_scope;
}

/// @brief this method removes the top element in OperatorStack and retruns
/// its operator_character value.
/// @return if OperatorStack is empty, returns '\0', otherwise removes the
/// top node and returns its stored operator.
char OperatorStack::pop_operator()
{
    if (is_empty())
    {
        return '\0';
    }

    _size--;
    
    // temporary pointer to node being removed
    OperatorNode* old_head = _head;
    
    _head = _head->next;
    
    old_head->next = nullptr;
    
    // if size is now 0, then the tail should be nullptr
    if (is_empty()) _tail = nullptr;
    
    return old_head->operator_character;
    // old_head is last reference to the node previously at the top of
    // OperatorStack. old_head is now out of scope and its destructor
    // is called.
}

/// @brief checks if OperatorStack is empty.
/// @return boolean indicating if OperatorStack is empty.
bool OperatorStack::is_empty()
{
    return _size == 0;
}