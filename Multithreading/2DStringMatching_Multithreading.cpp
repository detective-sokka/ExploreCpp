#include <iostream>
#include <mutex>
#include <string>
#include <vector>
#include <thread>

/*
Problem statement - 
Given a 2D array of strings and target string, return the indexes of strings that contain the target string. 

Input = [["abc”, “def”],
[“ghi”, “jkl”]
] ; target = “hi”

*/
using namespace std;
typedef vector<vector<string>> vvs;
typedef vector<pair<int, int>> vpii;

vpii getMatchIndices(vvs &input, string target)
{
    vpii result;
    
    mutex mtx;
    auto findStringInRow = [&mtx](vpii &result, vector<string> &row, int rowNumber, string target){
        for (int col=0; col < row.size(); col++)
            if (row[col].find(target) != string::npos)
            {
                std::lock_guard<mutex> guard(mtx);
                result.push_back({rowNumber, col});
            }
    };    
    
    vector<thread> threads;
    for (int row=0; row < input.size(); row++)
    {
        threads.push_back(thread(findStringInRow, ref(result), ref(input[row]), row, target));
    }

    for (int row=0; row < input.size(); row++)
        threads[row].join();

    return result;
}

void testGetMatchIndices(vvs &input, string &target)
{
    cout << "Testing the following list of strings :\n";
    for (int row=0; row < input.size(); row++)
    {
        for (int col=0; col < input[0].size(); col++)
            cout << input[row][col] << ", ";
        
        cout << "\n";
    }

    vpii result = getMatchIndices(input, target);

    cout << "Result is :\n";
    for (auto &row : result)
        cout << row.first << ", " << row.second << "\n";
}

int main()
{
    vvs listOfStrings = {{"abpqrf", "pqrjkl"},
                         {"mnopqr", "stuvwx"},
                         {"yz", "pqr"}};
    
    string result = "pqr";

    testGetMatchIndices(listOfStrings, result);

    return 0;
}