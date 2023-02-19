#pragma once
#define DEFAULT_STACK_SIZE 10


class OperatorStack
{

    private:

        struct OperatorNode
        {
            char operator_character;
            int operator_scope;
            OperatorNode* next;

            ~OperatorNode() 
            {
                if (next != nullptr)
                {
                    next->~OperatorNode();
                    delete next;
                }
            }
        };
        
        OperatorNode* head;
        OperatorNode* tail;
        int size;

    public: 

        OperatorStack()
        {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~OperatorStack() 
        {
            tail = nullptr;
            if (head != nullptr) head->~OperatorNode();
        }

        void push_operator(char c, int scope);
        int peek_operator_scope();
        char pop_operator();
        bool is_empty();

};