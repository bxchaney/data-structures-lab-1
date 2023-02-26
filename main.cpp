#include<iostream>
#include<stdio.h>
#include"FixConverter.cpp"
#include"CharStack.cpp"


/// @brief This fucntion is used for string comparisons while parsing
/// command line inputs.
/// @param s a character pointer to an entry from argv
/// @param str a character array that s is being compared against
/// @return a boolean indicating where s and str represent equivalent
/// character arrays.
bool is_equal_str(char* s, const char* str)
{
    
    for (int i=0; ;i++)
    {
        // If one of s or str has terminated but the other has not,
        // return false.
        if ((!s[i] && str[i]) || (!str[i] && s[i]))
        {
            return false;
        } 
        // Otherwise, if one has terminated (meaning the other has also
        // terminated at the same index) return true.
        else if (!s[i]) 
        {
            return true;
        }
        // If the character arrays have different values at any indeces,
        // return false.
        if (s[i] != str[i]) return false;
    }
}

int main(int argc, char** argv)
{
    // Confirm there is an input and an output file
    if (argc < 3) 
    {
        std::cout << "Expecting at least 2 arguments, the first being the"
                     " input file and the second being the output file." 
                     << std::endl;
        return -1;
    }
    FILE* input;
    FILE* output;
    
    input = fopen(argv[1], "r");
    // Checking input file
    if (!input)
    {
        std::cout << "Could not open the input file, "
                     "please check its name" << std::endl;
        fclose(input);
        return -1;
    }
    output = fopen(argv[2], "w");
    // checking output file
    if (!output)
    {
        std::cout << "Could not open the output file." << std::endl;
        fclose(output);
        return -1;
    }
    
    int c;
    const char* str;
    const char* input_str;
    FixConverter converter {};
    fputs("Input -> Output\n", output);
    // -r flag indicates that the user is providing postfix expressions
    // to be converted to prefix.
    if (argc >= 4 && is_equal_str(argv[3],"-r"))
    {
        CharStack stack = CharStack();
        bool converter_empty;
        
        printf(
            "Converting postfix expressions in %s to prefix and saving"
            " results in %s\n", argv[1], argv[2]
        );
        while ((c = fgetc(input)) != EOF)
        {
            // ignoring register clears, spaces, tabs
            if (c == 13 || c == 9 || c == 31)
            {
                continue;
            }
            // if we reach a newline character, process and write chars
            if (c == 10)
            {
                // A reversed valid postfix expression is a valid prefix
                // expression. We can parse postfix expressions using the same
                // objects by reversing their inputs to make them postfix
                // expressions and then reversing the resulting postfix
                // to get the corresponding correct prefix expression.

                input_str = stack.get_str();
                while (!stack.is_empty()) 
                {
                    // reverse the postfix input and parse
                    converter.next_character(stack.popc());
                }
                converter_empty = converter.input_length() == 0;
                
                // check for illegal characters
                if (converter.has_illegal_characters())
                {
                    str = "This expression has illegal characters";
                }
                // confirm the expression was valid
                else if (!converter.is_valid())
                {
                    str = "This is not a valid postfix expression";
                }
                else 
                {
                    // reverse the output to get prefix expression!
                    str = converter.get_output_reversed();
                }

                // print to terminal
                printf(
                    "Input: %-20s Output: %-20s",
                    input_str,
                    str
                );
                // write to output file
                if (!converter_empty)
                {
                    fputs(input_str, output);
                    fputs(" -> ", output);
                    fputs(str, output);
                }
                fputc(13, output);
                fputc(c, output);
                converter.reset();
                stack.reset();
                putchar(13);
                putchar(c);
            }
            // otherwise, store next character in stack
            else
            {
                stack.pushc(c);
            }
        }
    }
    
    else 
    {
        printf(
            "Converting prefix expressions in %s to postfix and saving"
            " results in %s\n", argv[1], argv[2]);
        
        while((c = fgetc(input)) != EOF)
        {
            // Ignoring register clears, spaces, and tabs
            if (c == 13 || c == 9 || c == 32) {
                continue;
            }
            // Once we read a newline character, process and write results
            if (c == 10) { 
                input_str = converter.get_input();
                
                // check if illegal characters
                if (converter.has_illegal_characters())
                {
                    str = "This expression contains illegal characters";
                }
                // confirm the input was a valid expression
                else if (!converter.is_valid())
                {
                    str = "This is not a valid prefix expression";
                }
                // get the output
                else 
                {
                    str = converter.get_output();
                }

                // write to terminal
                printf(
                    "Input: %-20s Output: %-20s",
                    input_str,
                    str
                );
                // write to output file
                if (converter.input_length() > 0)
                {
                    fputs(input_str, output);
                    fputs(" -> ", output);
                    fputs(str, output);
                }
                fputc(13, output);
                fputc(c, output);
                converter.reset();
                putchar(13);
                putchar(c);
            } 
            // process next character
            else 
            {
                converter.next_character(c);
            }
        }
    }

    fclose(input);
    fclose(output);
}