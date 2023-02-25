#include<iostream>
#include<stdio.h>
#include"PreToPostConverter.cpp"
#include"CharStack.cpp"

int main(int argc, char** argv)
{
    if (argc < 3) 
    {
        std::cout << "Expecting at least 2 arguments, the first being the"
                     " input file and the second being the output file." 
                     << std::endl;
        return -1;
    }
    FILE* input;
    // FILE* output;
    
    input = fopen(argv[1], "r");
    if (!input)
    {
        std::cout << "Could not open the input file, "
                     "please check its name" << std::endl;
        fclose(input);
        return -1;
    }
    // output = fopen(argv[2], "w");

    // if (!output)
    // {
    //     std::cout << "Could not open the output file." << std::endl;
    //     fclose(output);
    //     return -1;
    // }
    
    int c;
    CharStack echoed_input = CharStack();
    PreToPostConverter postfix = PreToPostConverter();
    while((c = fgetc(input)) != EOF)
    {
        
        if (c == 13 || c == 9 || c == 32) {
            continue;
        }
        if (c == 10) { //|| c == 13) {
            printf(
                "%s -> %s",
                echoed_input.get_str(),
                postfix.get_output()
            );
            echoed_input.reset();
            postfix.reset();
            putchar(13);
            putchar(c);
        } else {
            echoed_input.pushc(c);
            postfix.next_character(c);
        }
    }
    

    fclose(input);

        


}