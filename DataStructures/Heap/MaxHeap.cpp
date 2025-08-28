#include <iostream>
#include <vector> 

using namespace std;

template <typename T>
class MaxHeap {

public:
    MaxHeap() : _data{} {
    }

    MaxHeap(vector<T> &data) : _data{data} {
        heapify();
    }

    void heapify() { //O (N)
        for (int i = (_data.size())/2 - 1; i >=0 ; i--) 
            propagateDown(i);
    }

    void push(T element) {
        _data.emplace_back(element);
        propagateUp(_data.size() - 1);
    }

    void pop() {
        if (_data.size() == 0)
            throw std::runtime_error("Empty heap");
        swap(_data.back(), _data[0]);
        _data.pop_back();
        propagateDown(0);
    }

    bool empty() const {
        return _data.size() == 0;
    }

    T top() const {
        if (_data.empty())
            throw std::runtime_error("Empty heap.");
        return _data[0];
    }

    void debugHeap () const {
        cout << "\n";
        for (auto &element : _data) 
            cout << element << " ";
    }

private:
    vector<T> _data;

    void propagateDown(size_t start) {
        
        if (start >= _data.size())
            return;

        size_t child;
        
        while (start < _data.size()) { 
            
            size_t left = 2 * start + 1;
            size_t right = 2 * start + 2;
            size_t greatest = start; 
            
            if (left < _data.size() && _data[greatest] < _data[left])
                greatest = left;
            if (right < _data.size() && _data[greatest] < _data[right])
                greatest = right;

            if (greatest == start)
                return;
            
            if (_data[start] < _data[greatest]) 
                swap(_data[start], _data[child]);

            start = greatest;
        }
    }

    void printLevelOrder() {

        if (_data.size() == 0)
            return;

        int levelSize = 1;
        size_t root = 0;
        
        queue<int> q{_data[root]};

        string levelString = "";

        while (!q.empty()) {
            root = q.front();
            q.pop();
            levelSize--;
            
            size_t left = 2 * root + 1;
            size_t right = 2 * root + 2;

            if (levelSize == 0) {

            }
        }

    }
/*
    0
  1.  2
3. 4 5. 6
*/
    void propagateUp(int index) {
        while (index > 0) {            
            auto parent = (index-1) / 2;
            if (_data[parent] < _data[index])
                swap(_data[parent], _data[index]);
            
            index = parent;            
        }
    }
};

int main () {
    vector<int> data = {1, 2, 3, 4, 5};
    MaxHeap<int> maxHeap(data);
    maxHeap.debugHeap();    
    maxHeap.push(2);
    maxHeap.push(3);
    maxHeap.push(6);
    maxHeap.debugHeap();    
    cout << "\n";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
}