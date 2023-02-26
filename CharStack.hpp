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