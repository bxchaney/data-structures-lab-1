#pragma once
#define DEFAULT_STACK_SIZE 10


class OperatorStack
{

    private: 

        struct OperatorScope
        {
            char op;
            int operator_scope;
        };

        
        OperatorScope* scope_stack;
        int size;
        int stack_max_size;

        void resize();

    public: 

        OperatorStack()
        {
            size = 0;
            stack_max_size = DEFAULT_STACK_SIZE;
            scope_stack = new OperatorScope[DEFAULT_STACK_SIZE];
        }

        ~OperatorStack() 
        {
            delete scope_stack;
        }

        void push_operator(char c, int scope);
        int peek_operator_scope();
        char pop_operator();
        bool is_empty();

};