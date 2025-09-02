#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(const string &txn) {
    return true;
}

vector<string> processTransactions(vector<string>&& batch) { 
    vector<string> validated; 
    cout << "Hello";
    try {
        for (auto& txn : batch) 
            if (isValid(txn)) 
                validated.emplace_back(std::move(txn)); 
    }
    catch (exception e) {
        cout << endl << e.what();
    }
    
    cout << endl << batch[0];
    return validated; 
}

int main() {
    processTransactions(vector<string>{"abc", "def", "ghi"});
    return 0;
}