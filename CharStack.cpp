#pragma once 
#include "CharStack.hpp"

CharStack::CharStack()
{
    
    // defined in CharStack.hpp, DEFAULT_STR_SIZE = 10
    _max_size = DEFAULT_STR_SIZE;
    
    // char array allocated on the stack
    _string = new char[_max_size];
    _size = 0;
}

CharStack::~CharStack()
{
    // delete the array allocated to the heap.
   delete _string;
}

/// @brief doubles max size, allocates new array with new max size, deletes
/// old character array
void CharStack::resize()
{
    char* old_arr = _string;
    
    _max_size *= 2;
    
    
    _string = new char[_max_size];
    
    // copy old array into new array
    for (int i=0; i<_size; i++)
    {
        _string[i] = old_arr[i];
    }

    // the old array was allocated on the heap and is no longer needed
    // so we delete
    delete old_arr;
}

/// @brief Pushes c to the end of the current string of characters.
/// @param c a character value
void CharStack::pushc(char c)
{
    if (_size == _max_size) resize();
    
    
    _string[_size] = c;
    _size++;
}

/// @brief pops the top char from the stack
/// @return if CharStack is empty, returns '\0', otherwise returns the top
/// char on the stack
char CharStack::popc()
{
    if (is_empty())
    {
        return '\0';
    }
    char c = _string[_size - 1];
    _size--;
    return c;
}

/// @brief checks if the stack is empty
/// @return true when the stack is empty
bool CharStack::is_empty()
{
    return _size == 0;
}

/// @brief this method copies the current contents of the CharStack and 
/// returns a char pointer to the new copy. The returned character array is
/// in the order that elements were added to CharStack
/// @return a pointer to a character string.
const char* CharStack::get_str()
{
    if (_size == 0) return "";

    char* string = new char[_size];
    for (int i=0; i < _size; i++)
    {
        string[i] = _string[i];
    }
    string[_size] = '\0';
    return string;
}

/// @brief resets the size of the stack to 0, old information is overwritten
void CharStack::reset()
{
    _size = 0;
}

/// @brief the current size of CharStack
/// @return the integer size of CharStack
int CharStack::size()
{
    return _size;
}