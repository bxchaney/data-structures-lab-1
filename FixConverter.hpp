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
        bool _illegal_characters;

    void flush_stack();

    public:    
        FixConverter();

        void next_character(char c);
        bool has_illegal_characters();
        bool is_valid();
        const char* get_input();
        const char* get_output();
        int output_length();
        void reset();

};