#include <iostream>
#include <stddef.h>
#include <stdlib.h>

class String
{
    public:
    String() : m_data{nullptr}, m_size{0}
    {
    }

    String(const char *pData) : m_data{nullptr}, m_size{0}
    {
        if (!pData)
            return;
        
        size_t size = strlen(pData);
        
        m_data = (char*) malloc(sizeof(char) * (size + 1));
        if (!m_data) 
            throw std::bad_alloc();
        m_size = size;

        strcpy(m_data, pData);
    }

    String(String&& rValue) noexcept 
                          : m_data{rValue.m_data}, m_size{rValue.m_size}
    {
        std::cout << "\nMove Constructor called.";        
        
        rValue.m_data = nullptr;
        rValue.m_size = 0;
    }

    String& operator=(String &&rValue) noexcept
    {
        std::cout << "\nMove operator called.";

        if (&rValue != this)
        {
            free(m_data);
            m_data = nullptr;            

            m_data = rValue.m_data;
            m_size = rValue.m_size;

            rValue.m_size = 0;
            rValue.m_data = nullptr;
        }

        return *this;
    }

    String(const String &param) : m_data{nullptr}, m_size{param.m_size}
    {
        if (param.m_size == 0)       
            return;
        
        m_data = (char*) malloc(sizeof(char) * (param.m_size + 1));        
        strcpy(m_data, param.m_data);
    }

    String& operator=(const String &param)
    {
        if(&param == this)
            return *this;
        
        free(m_data);
        m_size = 0;
        m_data = nullptr;

        m_data = (char*) malloc(sizeof(char) * (param.m_size + 1));
        m_size = param.m_size;
        
        strcpy(m_data, param.m_data);

        return *this;
    } 

    void printString() const
    {
        if (!m_data)
            std::cout << "\nString is empty.\n";
        else
            std::cout << "\nThe string is : " << m_data << " and the size is : " << m_size << "\n";
    } 

    ~String()
    {
        if (m_data)
            free(m_data);
        
        m_data = nullptr;
        m_size = 0;
    }    

    private: 
        char *m_data;
        size_t m_size;
};

int test_custom_string()
{

    std::cout << "\nDefault constructor -";
    String str1;
    str1.printString();    

    std::cout << "\nParameterized constructor -";
    String str2("abc");
    str2.printString();

    std::cout << "\nCopy constructor with empty String -";
    String str3{str1};
    str3.printString();    

    std::cout << "\nCopy constructor with String -";
    String str4{str2};
    str4.printString();

    std::cout << "\nAssignment operators -";
    str1 = str2;
    str1.printString();
    
    std::cout << "\nMove constructor - ";
    String str5{String("abcd")};

    std::cout << "\nMove operator - ";
    String str6;
    str6 = std::move(str5);

    return 0;
}