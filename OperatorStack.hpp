#pragma once

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
        
        OperatorNode* _head;
        OperatorNode* _tail;
        int _size;

    public: 

        OperatorStack()
        {
            _head = nullptr;
            _tail = nullptr;
            _size = 0;
        }

        ~OperatorStack() 
        {
            _tail = nullptr;
            if (_head != nullptr)
            {  
                _head->~OperatorNode();
                delete _head;
            }
        }

        void push_operator(char c, int scope);
        int peek_operator_scope();
        char pop_operator();
        bool is_empty();

};