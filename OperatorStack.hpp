#pragma once

class OperatorStack
{

    private:

        struct OperatorNode
        {
            char operator_character;
            int operator_scope;
            OperatorNode* next;

            ~OperatorNode();
        };
        
        OperatorNode* _head;
        OperatorNode* _tail;
        int _size;

    public: 

        OperatorStack();
        ~OperatorStack();

        void push_operator(char c, int scope);
        int peek_operator_scope();
        char pop_operator();
        bool is_empty();

};