# ChaneyBLab1

## Configuration Info

Operating System: Ubuntu 22.04

C++ Compiler: g++ 11.3.0

IDE: Visual Studio Code version 1.75.1 with the most recent version of the C/C++ extension pack.

Compiling Expression: `g++ main.cpp -o main.exe -I.`

## Runtime Information

The user is expected to call the compiled executable from the command line and pass the input filepath then output file path at the same time.

For example: `./main.exe Required\ Input.txt output.txt`

If the user wants to provide an input file with postfix expressions to be converted to prefix, pass the input and output filepaths in the regular positions, then pass -r as the final command line argument.

For example: `./main.exe Postfix\ Input.txt postfix_output.txt -r`