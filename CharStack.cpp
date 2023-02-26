#pragma once 
#include "CharStack.hpp"

CharStack::CharStack()
{
    _max_size = DEFAULT_STR_SIZE;
    _string = new char[_max_size];
    _size = 0;
}

/// @brief 
void CharStack::resize()
{
    char* old_arr = _string;
    _max_size *= 2;
    _string = new char[_max_size];
    for (int i=0; i<_size; i++)
    {
        _string[i] = old_arr[i];
    }

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

bool CharStack::is_empty()
{
    return _size == 0;
}

/// @brief this method copies the current contents of the CharStack and returns
/// a char pointer to the new copy.
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

void CharStack::reset()
{
    _size = 0;
}

int CharStack::size()
{
    return _size;
}