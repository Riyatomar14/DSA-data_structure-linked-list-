#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
    
    // Constructor
    Node(int d) {
      this->data = d;
      this->prev = NULL;
      this->next = NULL;
    }
    
    ~Node() {
      int val = this->data;
      if (next != NULL) {
        delete next;
        next = NULL;
      }
      cout << "Memory is freed for value " << val << endl;
    }
};

// Function to insert at the head
void insertAtHead(Node* &tail, Node* &head, int d) {
    // For empty list
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Function to insert at the tail
void insertAtTail(Node* &tail, Node* &head, int d) {
    // For empty list
    if (tail == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Traverse the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// To find the length of the linked list
void getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    cout << "Length: " << len << endl;
}

// Insert at a specific position
void insertionAtPosition(int d, Node* &tail, Node* &head, int pos) {
    // Insert at head
    if (pos == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    // Traverse to the correct position
    Node* temp = head;
    int count = 1;
    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // Update tail if inserting at the end
    if (temp->next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }

    // Insert at the given position
    Node* insertToNode = new Node(d);
    insertToNode->next = temp->next;
    temp->next->prev = insertToNode;
    temp->next = insertToNode;
    insertToNode->prev = temp;
}

// Delete node at a specific position
void delete_node(int pos, Node* &head, Node* &tail) {
    // If deleting the first node
    if (pos == 1) {
        Node* temp = head;

        // Check if there's only one node in the list
        if (temp->next == NULL) {
            // Only one node, set both head and tail to NULL
            head = NULL;
            tail = NULL;
        } else {
            // More than one node, update head and unlink the current head
            head = temp->next;
            head->prev = NULL;
        }

        // Unlink the current node and delete it
        temp->next = NULL;
        delete temp;
    } 
    else {
        // Deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while (count < pos) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        // If deleting the last node
        if (curr->next == NULL) {
            tail = prev;
            prev->next = NULL;
        } 
        else {
            prev->next = curr->next;
            curr->next->prev = prev;
        }

        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main() {
    // Initial node
    Node* node1 = new Node(10);
    Node* head = node1;  
    Node* tail = node1;  
    
    print(head);  

    // Inserting at the head
    insertAtHead(tail, head, 5);
    print(head);  

    // Inserting at the tail
    insertAtTail(tail, head, 15);
    print(head);  
    
    getLength(head);
    
    insertionAtPosition(50, tail, head, 2);
    print(head);

    insertionAtPosition(53, tail, head, 1);
    print(head);
    
    // Deleting the head node
    delete_node(1, head, tail);
    print(head);

    // Deleting the last node
    delete_node(4, head, tail);
    print(head);

    return 0;
}
