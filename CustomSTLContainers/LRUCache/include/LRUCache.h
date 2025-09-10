#include <exception>
#include <iostream>
#include <new>
#include <string>
#include <unordered_map>

using std::bad_alloc;
using std::cout;
using std::exception;
using std::string;
using std::unordered_map;

template <typename K, typename V>
class LRUCache {
    public:
        LRUCache(size_t capacity) : front{nullptr}, 
                                    back{nullptr},
                                    capacity{capacity} {            
        }

        ~LRUCache() {
            Node *node = front;
            Node *nextNode = node ? node->next : nullptr;

            while (node) {
                delete node;
                node = nextNode;
                nextNode = nextNode ? nextNode->next : nullptr;
            }
        }

        void put (K key, V value) {
            
            if (capacity < 1)
                return;                

            if (keyNodeMap.find(key) == keyNodeMap.end()) 
                push_front(key, value);
            else {
                keyNodeMap[key]->val = value;
                move_to_front(keyNodeMap[key]);
            }

            if (keyNodeMap.size() > capacity)
                pop_back();
        }

        V get (K key) {

            if (keyNodeMap.find(key) == keyNodeMap.end())
                return V{};
                        
            move_to_front(keyNodeMap[key]);

            return keyNodeMap[key]->val;
        }

        LRUCache(const LRUCache &) = delete;
        LRUCache(LRUCache &&) noexcept = delete;
        LRUCache& operator=(const LRUCache &) = delete;
        LRUCache& operator=(LRUCache &&) = delete;        

        void debug() {
            Node *node = front;
            cout << std::endl;
            while (node) {
                cout << "<->";
                cout << "(" << node->key << "," << node->val << ")" ;
                node = node->next;
            }
        }
        
    private:
        struct Node { // Doubly linked list
            K key;
            V val;
            Node* prev;
            Node* next;            
        };        

        void push_front (const K& key, const V& value) {
            
            Node *newNode = nullptr;

            try {
                newNode = new Node();
            } catch (bad_alloc b) {
                throw;
            } catch (exception e) {
                cout << e.what() << std::endl;
                throw;
            }

            newNode->key = key;
            newNode->val = value;
            newNode->prev = nullptr;
            newNode->next = front;

            if (front)
                front->prev = newNode;
            front = newNode;

            if (!back)
                back = front;
                
            keyNodeMap[key] = newNode;
        }

        void move_to_front(Node *node) {

            if (node == front)
                return;

            if (node == back)
                back = node->prev;

            node->prev->next = node->next;
            if (node->next)
                node->next->prev = node->prev;
            
            node->prev = nullptr;
            node->next = front;
            front->prev = node;
            front = node;   
        }   

        void pop_back() {

            if (!back)
                return;
            
            Node *newBack = back->prev;            
            keyNodeMap.erase(back->key);
            delete back;
            if (front == back)
                front = nullptr;
            back = newBack;            
            if (back)
                back->next = nullptr;
        }

        Node *front, *back; 
        unordered_map<K, Node*> keyNodeMap;
        const size_t capacity;
};