## linked list 

linked list similar to array. 

In array elements are stored in contiguous memory locations.

But in linked list, elements are stored in  non contiguous memory location.In simple words, a linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.

## why linked lists ?

Memory and the capacity of an array remains fixed.In case of linked lists , we can kmeep adding and removing elements without any capacity contraints.

## drawbacks of linked lists ?

1. Extra memory space for ponters is required (for every node 1 pointer is needed).
2. random access not allowed as elements are not stored in contiguous memory locations.

![Screenshot 2024-02-11 103245](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/561fb23a-c9e4-4537-9413-69a1056ce5e8)

## how to transverse the data of linked list-

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//for insert node at the begining

struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node *insertAtIndex(struct Node *head,int data,int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i =0;
    while(i != index-1){
        ptr = ptr->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// insert node at end
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
    
}
 
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    head->data = 7;
    head->next = second;
    
    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;
 

    fourth->data = 66;
    fourth->next = NULL;
    
    printf("list transversal\n");
    linkedListTraversal(head);
    
    printf("list after insert 56 at begining\n");
    head = insertAtFirst(head,56);
    linkedListTraversal(head);
    
    printf("list after insert 67 at index 1\n");
    head=insertAtIndex(head,67,1);
    linkedListTraversal(head);
    
    printf("list after insert 99 at end\n");
    head=insertAtEnd(head,99);
    linkedListTraversal(head);
    
    return 0;
}

## output

![image](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/6f36d346-2ed4-4d9d-95fc-b8fe5c5932b9)

## deletion 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* deleteFirst(struct Node* head){
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node* deleteAtIndex(struct Node* head,int index){
    struct Node* p = head;
    struct Node* q = head->next;
    for(int i=0;i< index-1;i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node* deleteAtend(struct Node* head){
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return(head);
}   
struct Node* deleteAtValue(struct Node* head, int value) {
    struct Node* p = head;
    struct Node* q = head->next;

    // Check if head node is to be deleted
    if (head->data == value) {
        head = head->next;
        free(p);
        return head;
    }

    while (q != NULL) {
        if (q->data == value) {
            p->next = q->next;
            free(q);
            break; 
        }
        p = p->next;
        q = q->next;
    }

    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    head->data = 7;
    head->next = second;
    
    second->data = 1;
    second->next = third;

    third->data = 4;
    third->next = fourth;
 

    fourth->data = 6;
    fourth->next = NULL;
    printf("linked list before deletion\n");
    linkedListTraversal(head);
    head = deleteFirst(head);
    
    printf("linked list after deletion\n");
    linkedListTraversal(head);
    
    printf("delete at index\n");
    head = deleteAtIndex(head,1);
    linkedListTraversal(head);
    
    printf("delete at end\n");
    head = deleteAtend(head);
    linkedListTraversal(head);
    
    printf("delete at value\n");
    head = deleteAtValue(head,5);
    linkedListTraversal(head);
    return 0;
}


## output

![image](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/da34703e-532a-4fc2-9ea0-182b576705e2)

## double linkled list

A doubly linked list is a different from as singly linked list in a way that each node has a extra pointer that points to the previous node,together withg next pointer and data similar th singly linked list.


## benefit of the doubly linked list 

It is help to transverse in the both either forward or backward direction.

insertion and deletion becomes more efficicent.

## drawbacks-

1.Extra memory is required than the single linked list.


## binary tree

#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node* right;
    struct node* left;
}; 

struct node *createnode(int data) {
    struct node *n;
    n = (struct node *) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node* root){
    if(root !=NULL){
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
       
      
    }
}

int countleaves(struct node* root) {
    if (root == NULL)
    return 0;
    if (root->right== NULL && root->left== NULL){
        return 1;
    } else {
        return countleaves(root->left) + countleaves(root->right);
    }
    
}

int countinternalleaves(struct node* root){
    if (root==NULL)
    return 0;
    if (root->right==NULL && root->right== NULL){
        return 0;
    }
    else{
        return 1 + countinternalleaves(root->left) + countinternalleaves(root->right);
    }
}
int height(struct node *root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
struct node* searchKey(struct node* root, int data) {
    // Base cases: root is NULL or key is present at root
    if (root == NULL || root-> data == data)
        return root;

    // Key is greater than root's key, so search in right subtree
    if (root->data < data)
        return searchKey(root->left, data);

    // Key is smaller than root's key, so search in left subtree
    return searchKey(root->right, data);
}

int main() {
    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(2);
    

    // linking 
    p->left = p1;
    p->right = p2;
    p1->right = p4;
    p1->left = p3;
    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    printf("\n");
    int leaves = countleaves(p);
    printf("Number of leaves in the tree: %d\n", leaves);
    int nonleaves = countinternalleaves(p);
    printf("Number of non-leaves in the tree: %d\n", nonleaves);
    int heightoftree = height(p);
    printf("height of tree: %d\n", heightoftree);
    struct Node *root = NULL;
    //insertnode(p,0);
    inorder(p);
    printf("\n");
   int Data = 5;
    struct node* result = searchKey(p, Data);
    if (result != NULL)
        printf("Node with value %d found in the binary search tree\n", Data);
    else
        printf("Node with value %d not found in the binary search tree\n", Data);
    return 0;
}

## output

![image](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/90514d1b-406a-46ee-b52e-4d81478e134f)

## AVL -TREE(Adelson-Velsky and Landis tree)

almost all the operations of binary search tree are of order 0(h) is a height of the tree. to guarantee an upper bound of 0(log n) foe all these operations,we use balanced trees. 



