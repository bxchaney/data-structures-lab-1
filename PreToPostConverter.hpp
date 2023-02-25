#pragma once
#include"OperatorStack.cpp"
#include"CharStack.cpp"

class FixConverter
{
    private:
        OperatorStack _op_stack;
        CharStack _input;
        CharStack _output;
        int _operands;
        bool _is_invalid;

    void flush_stack();

    public:    
        FixConverter()
        {
            _op_stack = OperatorStack();
            _input = CharStack();
            _output = CharStack();
            _operands = 0;
            _is_invalid = false;
        }

        ~FixConverter()
        {
           // _op_stack.~OperatorStack();
        }

        void next_character(char c);
        const char* get_output();
        void reset();

};