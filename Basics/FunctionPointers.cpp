/*
Simple program to read user input and execute call back function to do custom action when a particular key is pressed. 
*/

#include <iostream>

void printLetterOrCharacter(char input)
{
    if (input >= '0' && input <= '9')
        std::cout << "\t Number\n";
    else   
        std::cout << "\t Character\n";
}

void keyActionLoop(void(*functionPointer)(char)) 
{
    char key;
    std::cout << "Enter a key (Space or newline to exit): "; 
    while (true)
    {
        key = std::cin.get();
        if (key == ' ' || key == '\n')
            break;
        functionPointer(key);    
    }
}

int main()
{
    keyActionLoop(printLetterOrCharacter);
    return 0;
}