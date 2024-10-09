struct Node{
    int data;
    int value;
    Node* before;
    Node* after;
    Node(int val,int valu){
        data = val;
        value = valu;
        before = NULL;
        after = NULL;
    }
};
auto init_io = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
class LRUCache {
    unordered_map<int,Node*> lookup;
    Node* head;
    Node* tail;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = head;
    }
    
    int get(int key) {
        if(lookup.find(key)==lookup.end()) return -1;
        Node* ptr = lookup[key];
        if(tail == ptr) {
            tail = tail->before;
            tail->after = NULL;
        }
        ptr->before->after = ptr->after;
        if(ptr->after) ptr->after->before = ptr->before;
        ptr->after = head->after;
        ptr->before= head;
        if(head->after) head->after->before = ptr;
        head->after = ptr;
        if(head==tail) tail = head->after;
        return ptr->value;
    }
    
    void put(int key, int value) {
        if(lookup.find(key)==lookup.end()&&lookup.size()==cap){
            lookup.erase(tail->data);
            tail = tail->before;
            
            tail->after = NULL;
        }
        if(lookup.find(key)==lookup.end()) lookup[key] = new Node(key,value);
        lookup[key]->value = value;
        Node* ptr = lookup[key];
        if(tail == ptr) {
            tail = tail->before;
            tail->after = NULL;
        }
        if(ptr->before) ptr->before->after = ptr->after;
        if(ptr->after) ptr->after->before = ptr->before;
        ptr->after = head->after;
        ptr->before= head;
        if(head->after) head->after->before = ptr;
        head->after = ptr;
        if(lookup.size()==1) tail = ptr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */