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

        if (curr == tail) {  // If deleting the tail node
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

bool search(int data,node* &head){
    node*temp=head;
    while(temp != NULL){
        if(temp->data=data){
            return true;
        }
        temp=temp->next;
    }
    
    return false;
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

void concatenation(Node* &head, Node* &head1) {
    // If the first list is empty
    if (head == NULL) {
        head = head1;
        return;
    }

    // Otherwise, traverse to the end of the first list
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head1;
}

bool compare(Node* &head,Node* &head1){
    Node* temp1 = head;
    Node* temp2 = head1;
    while (temp1!=NULL && temp2!=NULL){
        if(temp1->data == temp2->data){
            return true;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1==NULL && temp2==NULL){
        return true;
    }
    return false;
}



int size(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void ARRAYsort(int arr[], int s) {
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            // Sort in ascending order
            if (arr[i] > arr[j]) {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort(Node*& head) {
    int s = size(head);
    if (s == 0) return; // Nothing to sort

    // Create an array to hold the linked list elements
    int* arr = new int[s];

    // Populate the array with linked list data
    Node* temp = head;
    for (int i = 0; i < s; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    // Sort the array
    ARRAYsort(arr, s);

    // Place sorted values back into the linked list
    temp = head;
    for (int i = 0; i < s; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    // Clean up
    delete[] arr;
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
    
    delete_node(1, head);
    print(head);
    
    //reverse 
    reverse(head,NULL,head);
    print(head);
    //concatenate 
    Node* node2 = new Node(50);
    Node* head1 = node2;
    concatenation(head,head1);
    print(head);
 
    //compare
    print(head);
    print(head1);
    if(compare(head,head1)){
        cout<<"lists are identical "<<endl;
    }
    else{
        cout<<"lists are not identical "<<endl;
    }
    sort(head);
    print(head);
    return 0;
}
