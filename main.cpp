#include<iostream>
#include<stdio.h>
#include "OperatorStack.cpp"

int main(int argc, char** argv)
{
    if (argc == 1) return 0;
    


    FILE* file;
    file = fopen(argv[1], "r");

    int c;
    if (file)
    {
        while((c = fgetc(file)) != EOF)
        {
            putchar(c);
        }
    }

    fclose(file);


}