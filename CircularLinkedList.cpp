//circular linked list..
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // Free memory
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for the data " << value << endl;
    }
};

void insertNewNode(int data, Node*& tail, int element) {
    if (tail == NULL) {
        // Empty list
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode; // Point to itself to make it circular
    }
    else {
        // Non-empty list, assuming element is present
        Node* curr = tail;
        do {
            if (curr->data == element) {
                Node* newNode = new Node(data);
                newNode->next = curr->next;
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        } while (curr != tail);
    }
}

void print(Node* tail) {
    // Empty list
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

void deleteNode(int value, Node*& tail) {
    // Empty list
    if (tail == NULL) {
        cout << "Linked list is empty, please check again" << endl;
        return;
    }

    // Non-empty list
    Node* prev = tail;
    Node* curr = prev->next;

    // Find the node to delete
    while (curr->data != value && curr != tail) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data != value) {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    // If there is only one node in the list
    if (curr == prev) {
        tail = NULL;
    }
    // If tail node is being deleted, move the tail pointer
    else if (tail == curr) {
        tail = prev;
    }
     // Node found, now delete it
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
void search(int value,Node* tail){
    if(tail==NULL){
        cout<<"LINKED LIST IS EMPTY"<<endl;
    }
    else{
        Node*curr = tail;
        
        do{
            if(curr->data==value){
                cout<<"element is found"<<endl;
            }
            else{
                cout<<"element not found"<<endl;
            }
            curr=curr->next;
 
        }while(curr!=tail);
        
    }
}
int main() {
    Node* tail = NULL;

    // When list is empty
    insertNewNode(10, tail, 1);
    print(tail);

    /*insertNewNode(20, tail, 10);
    print(tail);

    insertNewNode(50, tail, 10);
    print(tail);

    insertNewNode(100, tail, 50);
    print(tail);*/

    deleteNode(10, tail);
    print(tail);

    return 0;
}
