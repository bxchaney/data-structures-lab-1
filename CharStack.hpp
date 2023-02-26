/*
CharStack is a dynamic array based implementation of a stack. The default 
size of the underlying array is defined by DEFAULT_STR_SIZE = 10. This object
is used internally by FixConverter to build new strings. It is also used to
reverse strings to allow the added feture of conveting postfix expressions to
prefix.

This module supports the following interface:

void pushc(char)

    Input: a char value

    Precondition: there is space in the internal array for another entry. If
    not, resizes internal array. Adds the input to the end of the list of
    inputs.

    Process: Places char at next index of internal array.

    Postcondition: None

    Output: None

char popc()

    Input: None

    Precondition: CharStack is non-empty. If CharStack is empty, returns '\0'

    Process: Returns value at top of stack, shifts next index down.

    Postcondition: Size of CharStack is decremented by 1 if it was non-empty
    when this method was called.

    Output: The character at the top of the stack.

bool is_empty()

    Input: None

    Precondtion: None

    Process: Checks if CharStack is empty.

    Postcondition: None

    Output: A boolean indicating whether CharStack is empty.

const char* get_str()

    Input: None

    Precondition: None

    Process: If CharStack is empty, returns empty string. Otherwise, returns
    a copy of CharStack's contents in the same order they were added.

    Postcondition: None

    Output: Copy of CharStack's contents with characters ordered FIFO

void reset()

    Input: None

    Precondition: None

    Process: Sets next entry for CharStack to be the first entry of the
    underlying array.

    Postcondition: None

    Output: None

int size()

    Input: None

    Precondition: None

    Process: Returns size value.

    Postcondition: None

    Ouput: The number of elements in the stack.
*/

#pragma once
#define DEFAULT_STR_SIZE 10

class CharStack
{
    private:
        char* _string;
        int _size;
        int _max_size;

        void resize();

    public:
        CharStack();

        void pushc(char c);
        char popc();
        bool is_empty();
        const char* get_str();
        void reset();
        int size();
};