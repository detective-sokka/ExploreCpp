/*
Write a sample program to demostrate the usage of file stream for file handling in C++.
*/

#include<fstream>
#include<iostream>
#include<string>

class FileHandling
{
    std::string fileName;

    public:
        FileHandling(std::string filename) : fileName{filename}
        {
        }

        void setFileName(std::string filename)
        {
            this->fileName = filename;
        }
        
        void readFromFile()
        {
            std::ifstream fileHandler(this->fileName);            
            std::string line;

            while(std::getline(fileHandler, line))
            {
                std::cout << line << std::endl;
            }

            fileHandler.close();
        }

        void writeToFile(const std::string &inputString)
        {
            std::ofstream fileHandler(this->fileName);
            fileHandler << inputString;
            fileHandler.close();
        }
};

int main()
{
    std::string filename, text;    

    std::cout << "Enter filename : ";
    std::cin >> filename;
    std::cout << "\nWrite text to a file : ";
    std::cin.ignore();  // To clear the newline character left by std::cin
    std::getline(std::cin, text);
    FileHandling fileHandler{filename};
    fileHandler.writeToFile(text);
    std::cout << "-------------------------\n";
    std::cout << "The contents of the file " << filename << " are : \n";
    fileHandler.readFromFile();
    return 0;    
}


