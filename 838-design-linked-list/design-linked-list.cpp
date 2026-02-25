class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

class MyLinkedList {
public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        Node* tmp = head;
        while(index--) tmp = tmp->next;
        return tmp->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        if(size == 0) tail = head;
        size++;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if(size == 0) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        Node* prev = head;
        for(int i = 0; i < index - 1; i++)
            prev = prev->next;
        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            if(size == 1) tail = NULL;
            size--;
            return;
        }
        Node* prev = head;
        for(int i = 0; i < index - 1; i++) prev = prev->next;
        Node* del = prev->next;
        prev->next = del->next;
        if(del == tail) tail = prev;
        delete del;
        size--;
    }

private:
    Node* head;
    Node* tail;
    int size;
};