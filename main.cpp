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
    if (!input)
    {
        std::cout << "Could not open the input file, "
                     "please check its name" << std::endl;
        fclose(input);
        return -1;
    }
    output = fopen(argv[2], "w");

    if (!output)
    {
        std::cout << "Could not open the output file." << std::endl;
        fclose(output);
        return -1;
    }
    
    int c;
    const char* str;
    FixConverter converter = FixConverter();
    // -r flag indicates that the user is providing postfix expressions
    // to be converted to prefix.
    if (argc >= 4 && is_equal_str(argv[3],"-r"))
    {
        
    }
    
    else 
    {
        while((c = fgetc(input)) != EOF)
        {
            // Ignoring register clears, spaces, and tabs
            if (c == 13 || c == 9 || c == 32) {
                continue;
            }
            // Once we read a newline character, 
            if (c == 10) { 
                
                if (converter.has_illegal_characters())
                {
                    str = "This expression contains illegal characters";
                }
                else if (!converter.is_valid())
                {
                    str = "This is not a valid prefix expression";
                }
                else 
                {
                    str = converter.get_output();
                }

                
                printf(
                    "Input: %-20s Output: %-20s",
                    converter.get_input(),
                    str
                );

                if (converter.output_length() > 0)
                {
                    fputs(converter.get_input(), output);
                    fputs(" -> ", output);
                    fputs(str, output);
                }
                fputc(13, output);
                fputc(c, output);
                converter.reset();
                putchar(13);
                putchar(c);
            } else {
                converter.next_character(c);
            }
        }
    }
    fclose(input);
    fclose(output);
}