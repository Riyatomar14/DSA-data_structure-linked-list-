//singly linked list

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
    ~Node(){
        int value= this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<" memory is free for the data"<<value<<endl;
    }

};

void insert_at_head(int d,Node* &head){
    //create new node
    Node* temp = new Node(d);
    temp-> next = head;
    head = temp;
}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
}
void insert_at_tail(int d,Node* tail){
    //create new node
    Node* temp = new Node(d);
    tail->next= temp;
    tail=temp;
}
void insertion_at_position(int d,Node* &tail,Node* &head,int pos){
    //inert at head
    if(pos==1){
       insert_at_head(d,head);
       return;
    }
    //at any position 
    Node* temp= head;
    int count= 1;
    while(count < pos-1){
        temp=temp->next;
        count++;
    }
    //update tail at end
    if(temp-> next == NULL){
        insert_at_tail(d,tail);
        return;
    }
    //create node to insert
    Node* insertToNode = new Node(d);
    insertToNode -> next = temp-> next;
    temp -> next = insertToNode;
}
void delete_node(int pos,Node* head){
    if(pos==1){
        Node* temp = head;
        head= head -> next;
        //memory free start node
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main() {
    // created new node
    Node* node1 = new Node(10);
   //cout << node1 -> data << endl;
  // cout << node1 -> next << endl;

   //head pointer to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);


    insert_at_head(12,head);
    print(head);

    insert_at_tail(14,tail);
    print(head);

    cout << endl;

    insertion_at_position(100,tail,head,2);
    print(head);
    
    delete_node(2,head);
    print(head);

    return 0;

}
