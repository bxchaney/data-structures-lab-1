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
        CharStack()
        {
            _max_size = DEFAULT_STR_SIZE;
            _string = new char[_max_size];
            _size = 0;
        }

        ~CharStack()
        {
            delete _string;
        }

        void pushc(char c);
        char* get_str();
};