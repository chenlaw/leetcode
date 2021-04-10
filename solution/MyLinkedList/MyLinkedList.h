struct Node {
    int val;
    Node* next;
    Node(int v) :val(v), next(NULL) {};
};
class MyLinkedList {
private:
    Node* head;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        len = 0;
        head = new Node(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index + 1>len)
            return -1;
        Node* h = head;
        for (int i = 0; i <= index; i++) {
            h = h->next;
        }
        return h->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        len++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* h = head;
        while (h->next != NULL)
            h = h->next;
        h->next = new Node(val);
        len++;
    }
    void  operator =(const MyLinkedList* l) {


    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > len)
            return;
        else if (index <= 0)
            addAtHead(val);
        else {
            Node* h = head;
            for (int i = 0; i < index; i++) {
                h = h->next;
            }
            Node* newNode = new Node(val);
            newNode->next = h->next;
            h->next = newNode;
            len++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index <0 || index + 1 >len)
            return;
        Node* h = head;
        for (int i = 0; i < index; i++) {
            h = h->next;
        }
        h->next = h->next->next;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
