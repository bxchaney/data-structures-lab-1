#pragma once
#include"OperatorStack.cpp"
#include"CharStack.cpp"

class PreToPostConverter
{
    private:
        OperatorStack _op_stack;
        CharStack _output;
        int _operands;
        bool _is_invalid;


    public:    
        PreToPostConverter()
        {
            _op_stack = OperatorStack();
            _output = CharStack();
            _operands = 0;
            _is_invalid = false;
        }

        ~PreToPostConverter()
        {
            _op_stack.~OperatorStack();
            _output.~CharStack();
        }

        void next_character(char c);
        const char* get_output();

};