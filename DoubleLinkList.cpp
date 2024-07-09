#include<iostream>
using namespace std;
template<class T> struct Node{
    T value;
    Node<T> *next;
    Node<T> *prev;
};
template <class T> class DoubleLinkList{
private:
    Node<T> *pHead;
    Node<T> *pTail;
    int Length;
public:
    DoubleLinkList() :pHead(nullptr),pTail(nullptr),Length(0){}
    // This function adds a new node to the end of the list.
    // It creates a new Node object with the given value and a null pointer for the next and previous nodes.
    // If the list is currently empty, it sets both the head and tail pointers to the new node.
    // If the list is not empty, it sets the next pointer of the current tail node to the new node
    // and updates the tail pointer to the new node.
    // Finally, it increments the length of the list.
    void Add(T value){
        // Create a new Node object with the given value and a null pointer for the next and previous nodes.
        Node<T> *tmp = new Node<T>{value,NULL,NULL};
        
        // If the list is currently empty, set both the head and tail pointers to the new node.
        if(pHead==NULL){
            pTail = pHead = tmp;
        }else{
            // If the list is not empty, set the next pointer of the current tail node to the new node
            // and update the tail pointer to the new node.
            pTail->next = tmp;
            tmp->prev = pTail;
            pTail = pTail->next;
        }
        
        // Increment the length of the list.
        Length++;
    }
    // This function inserts a new node at a specified index in the list.
    // It creates a new Node object with the given value and a null pointer for the next and previous nodes.
    // If the index is less than zero, the function returns without doing anything.
    // If the index is greater than or equal to the length of the list, the function adds the new node to the end of the list.
    // If the index is equal to zero, the new node is inserted at the beginning of the list.
    // If the index is between zero and the length of the list minus one, the function finds the node at the specified index and inserts the new node between it and its next node.
    // Finally, it increments the length of the list.
    void Insert(int index,T value){
        // Create a new Node object with the given value and a null pointer for the next and previous nodes.
        Node<T> *tmp = new Node<T>{value,NULL,NULL};
        
        // If the index is less than zero, return without doing anything.
        if(index<0) return;
        
        // If the index is greater than or equal to the length of the list, add the new node to the end of the list.
        if(index>=Length) return Add(value);
        
        // If the index is equal to zero, insert the new node at the beginning of the list.
        if(index == 0){
            // Set the next pointer of the new node to the current head of the list.
            tmp->next = pHead;
            // Set the previous pointer of the current head of the list to the new node.
            pHead->prev = tmp;
            // Set the head of the list to the new node.
            pHead = tmp;
        }else{
            // If the index is between zero and the length of the list minus one, find the node at the specified index and insert the new node between it and its next node.
            
            // Start at the head of the list.
            Node<T> *p = pHead;
            
            // Iterate through the list until we reach the specified index.
            for(int i = 1; i < index; i++, p = p->next);
            
            // Set the next pointer of the new node to the next node after the current node.
            tmp->next = p->next;
            // Set the previous pointer of the next node to the new node.
            tmp->next->prev = tmp;
            // Set the next pointer of the current node to the new node.
            p->next = tmp;
            // Set the previous pointer of the new node to the current node.
            tmp->prev = p;
        }
        
        // Increment the length of the list.
        Length++;
    }
    // This function deletes a node at a specified index from the list.
    void Delete(int index){
        // Create a temporary pointer to iterate through the list.
        Node<T>* tmp = pHead;
        
        // If the list is empty, we don't need to do anything.
        if(Length == 0) return;
        
        // If the index is out of range, we don't need to do anything.
        if(index < 0 || index >= Length) return;
        
        // If the index is equal to zero, we can delete the head node.
        if(index == 0){
            // Set the head pointer to the next node of the current head node.
            pHead = tmp->next;
            
            // Set the next pointer of the current head node to NULL to avoid memory leaks.
            tmp->next = NULL;
            
            // If the new head node exists, set its previous pointer to NULL.
            if(pHead != NULL) pHead->prev = NULL;
            
            // Delete the current head node.
            delete tmp;
        }else{
            // If the index is greater than zero, we need to find the node at the specified index and delete it.
            
            // Start at the head of the list.
            Node<T>* p = pHead;
            
            // Iterate through the list until we reach the previous node of the specified index.
            for(int i = 1; i < index; i++, p = p->next);
            
            // Set the temporary pointer to the node at the specified index.
            tmp = p->next;
            
            // Set the next pointer of the previous node to the next node after the node at the specified index.
            p->next = tmp->next;
            
            // Set the previous pointer of the next node to the previous node of the node at the specified index.
            tmp->next->prev = p;
            
            // Set the next pointer and previous pointer of the node at the specified index to NULL to avoid memory leaks.
            tmp->next = NULL;
            tmp->prev = NULL;
            
            // If the node at the specified index is the tail node, update the tail pointer to the previous node.
            if(pTail == tmp) pTail = p;
            
            // Delete the node at the specified index.
            delete tmp;
        }
        
        // Decrement the length of the list.
        Length--;
    }

    /**
     * This function prints the values of all the nodes in the list.
     * It starts at the head of the list and iterates through each node,
     * printing the value of each node. The iteration continues until we
     * reach the end of the list (i.e., NULL). Finally, it prints a newline
     * character to separate the list from the rest of the output.
     */
    void Print(){
        // Start at the head of the list.
        Node<T>* currentNode = pHead;
        
        // Iterate through each node in the list.
        while(currentNode != NULL){
            // Print the value of the current node.
            cout << currentNode->value << " ";
            
            // Move to the next node in the list.
            currentNode = currentNode->next;
        }
        
        // Print a newline character to separate the list from the rest of the output.
        cout << endl;
    }

    void PrintReverse(){
        for(Node<T>*i=pTail;i!=NULL;i=i->prev){
            cout<<i->value<<" ";
        }
        cout<<endl;
    }

    int getLength(){
        return Length;
    }
};

int main(){
    DoubleLinkList<string> list;

    list.Add("liza");
    list.Add("nika");
    list.Add("alex");
    list.Insert(0,"jonh");
    list.PrintReverse();
    while(list.getLength()>0){
        list.Delete(0);
        list.Print();
    }
    
    DoubleLinkList<int> list2;
    list2.Add(1);
    list2.Add(3);
    list2.Add(5);
    list2.Insert(0,7);
    list2.Print();
    return 0;
}