/*
    Hash map + doubly linked list, tail = LRU, head = MRU
    get: update to MRU, put: update to MRU, remove LRU if full

    Time: O(1)
    Space: O(capacity)
*/

class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key_, int value_) {
        key = key_;
        value = value_;
    }
};

class LRUCache {
private:
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp; // {key -> node}

    void addNode(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {
        if (mp.find(key_) != mp.end()) {
            Node* rep = mp[key_];
            deleteNode(rep);
            addNode(rep);
            return rep->value;
        } else {
            return -1;
        }
    }
    void put(int key_, int value_) {
        if (mp.find(key_) != mp.end()) {
            Node* rep = mp[key_];

            mp.erase(key_);
            deleteNode(rep);

        }
        if (mp.size() == cap) {

            mp.erase(tail->prev->key);  
            deleteNode(tail->prev);
        }
        Node* curr = new Node(key_, value_);
        addNode(curr);
        mp[key_] = curr;
    }
};
