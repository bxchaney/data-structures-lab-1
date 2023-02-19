#pragma once
#include"OperatorStack.cpp"
#include"CharStack.cpp"

class PreToPostConverter
{
    private:
        OperatorStack op_stack;
        CharStack output;
        int operands;


    public:    
        PreToPostConverter()
        {
            op_stack = OperatorStack();
            output = CharStack();
            operands = 0;
        }

        void next_character(char c);
        char* get_output();

};