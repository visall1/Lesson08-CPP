#include<iostream>
using namespace std;
struct Node{
    string value;
    Node *next;
};
// This is the main function that demonstrates the creation and traversal of a one-way linked list.
int main(){
    // Create a new Node and assign it to the pointer pHead.
    Node* pHead = new Node;

    // Assign the value "Bill" to the value field of the Node pointed to by pHead.
    pHead->value = "Bill";

    // Set the next field of the Node pointed to by pHead to NULL, indicating the end of the list.
    pHead->next = NULL;

    // Create a new Node and assign it to the next field of the Node pointed to by pHead.
    pHead->next = new Node;

    // Assign the value "Mark" to the value field of the Node pointed to by pHead->next.
    pHead->next->value = "Mark";

    // Set the next field of the Node pointed to by pHead->next to NULL, indicating the end of the list.
    pHead->next->next = NULL;

    // Create a new Node and assign it to the next field of the Node pointed to by pHead->next.
    pHead->next->next = new Node;

    // Assign the value "John" to the value field of the Node pointed to by pHead->next->next.
    pHead->next->next->value = "John";

    // Set the next field of the Node pointed to by pHead->next->next to NULL, indicating the end of the list.
    pHead->next->next->next = NULL;

    // Create a Node pointer named i and assign it the value of pHead.
    // This will be used to traverse the list.
    for(Node* i=pHead; i!=NULL; i=i->next){
        // Print the value of the Node pointed to by i.
        cout<<i->value<<" ";
    }
    // Return 0 to indicate successful execution.
    return 0;
}
