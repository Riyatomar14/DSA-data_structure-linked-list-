// singly linked list 
#include <iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    //Destructor
    ~Node(){
        int value = this->data;
        cout << "Memory is free for the data " << value << endl;
    }

};

void insert_at_head(int d, Node* &head){
    //create new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insert_at_tail(int d, Node* &tail){
    //create new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertion_at_position(int d, Node* &tail, Node* &head, int pos){
    // Insert at head
    if(pos == 1){
       insert_at_head(d, head);
       return;
    }
    
    Node* temp = head;
    int count = 1;
    while(count < pos - 1){
        temp = temp->next;
        count++;
    }
    
    // Insert at tail
    if(temp->next == NULL){
        insert_at_tail(d, tail);
        return;
    }
    
    // Insert in the middle
    Node* insertToNode = new Node(d);
    insertToNode->next = temp->next;
    temp->next = insertToNode;
}

void delete_node(int pos, Node* &head){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

/* //by loop
    void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head = prev;
}*/
//by recursion 

void reverse(Node* &head, Node* prev, Node* curr) {
    if (curr) {
        Node* next = curr->next;
        curr->next = prev;
        reverse(head, curr, next);
    } else {
        head = prev;
    }
}


int main() {
    // Created new node
    Node* node1 = new Node(10);
    
    // Head and tail pointers pointing to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insert_at_head(12, head);
    print(head);

    insert_at_tail(14, tail);
    print(head);

    insertion_at_position(100, tail, head, 2);
    print(head);
    
    delete_node(2, head);
    print(head);
    
    //reverse(head);
    reverse(head,NULL,head);
    print(head);

    return 0;
}
