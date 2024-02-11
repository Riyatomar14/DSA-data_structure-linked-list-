# c-language-important-terms
## 1.ARRAY-An array is a collection of items of same data type stored at contiguous memory locations. 

for example-

![Screenshot 2024-01-27 111414](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/c07ec1be-47ad-494b-a2cf-5e16ace9769d)

![Screenshot 2024-01-27 111447](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/b6c9fb1e-baee-43af-9ced-4e819c46bde8)

![Screenshot 2024-01-27 111128](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/23993811-751a-4ebf-bcd5-cd0c562fd7b7)

# remember -  “Location of next index depends on the data type we use”.

# Note- why indexes start with 0 ?

Because as it save the subtraction (operation) cost and hence some time.It is a more efficient way. 

Let us assume a 2D array and write a row-major formula  with two different approaches:

CASE1: array indices starting from 1
CASE2 :array indices starting from 0
let the 2D array be arr[m][n] of type int

let &arr be “address”
![Screenshot 2024-01-27 113422](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/0efa0d22-2135-4d03-82df-5316f8c0d5e0)

# case 1 may look user-friendly but case 2 is more efficient. That’s why most languages like C++, PYTHON, JAVA use arrays starting with index 0 and rarely languages like Lua arrays starting with index 1.

## 2.POINTERS-

Pointers are symbolic representations of addresses. They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures. Iterating over elements in arrays or other data structures is one of the main use of pointers. 
The address of the variable you’re working with is assigned to the pointer variable that points to the same data type (such as an int or string).

![image](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/0aef3a2a-d99b-42b0-92c2-bce1dcad75d8)

## 3. ROW-MAJOR ORDER SET AND COLUMN-MAJOR ORDER SET
In computing, row-major order and column-major order are methods for storing multidimensional arrays in linear storage such as random access memory.

a) ROW-MAJOR ORDER SET-the elements in row-major order are arranged consecutively along the row.for example-In C (and many other languages like C++, Java etc), 2-D arrays are stored in row-major order.

b) COLUMN-MAJOR ORDER SET-The elements in the column-major order are arranged consecutively along the column. for example- Pascal and Fortran follows column major order.

![image](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/9618373e-8390-4e60-aafc-8d187fdc123e)

## 4. FUNCTION-A function is a set of statements that takes input, does some specific computation, and produces output. The idea is to put some commonly or repeatedly done tasks together to make a function so that instead of writing the same code again and again for different inputs, we can call this function.

for example-
![Screenshot 2024-01-27 111109](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/9a15bb05-b1e7-480f-bcc5-09e884abcccf)

# PARAMETER PASSING TECHNIQUES
![Screenshot 2024-01-27 115934](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/9d516a52-b36f-43ec-86a3-758d41e82a61)

## 5.scope of a variable 

The scope of a variable is the region of the program in which variable is declared and used.Scope is generally divided into two categories:

1.Static Scope- if a variable's scope is a certain function, then its scope is the program text of the function definition:within that that text,the variable name exists, and is bound to its variable ,but outside that text ,the variable does not exist. for example-

![Screenshot 2024-01-27 120859](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/1c4f2b57-2d9a-47be-b2e5-efaf97fd7b43)

2.Dynamic Scope-while the function is running, the variable name exists, and is bound to its variable,but after the function returns ,the variable name does not exist. for example-

![Screenshot 2024-01-27 120935](https://github.com/Riyatomar14/c-language-important-terms/assets/143107173/cda43155-d2fd-4950-a546-48e07b627182)

## int main() function 

The main function serves as the starting point for program execution. It usually controls program execution by directing the calls to other functions in the program.

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

