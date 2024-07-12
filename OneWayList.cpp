#include<iostream>
using namespace std;
template<class T>struct Node{
    T value;
    Node<T> *next;
};
template<class T>class OneWayList
{
private:
    Node<T>* pHead;
    Node<T>*pTail;
    int Length;
public:
    OneWayList():pHead(nullptr),pTail(nullptr){}
    // This function adds a new Node to the end of the list.
    // It creates a new Node object with the given value and a null pointer for the next Node.
    // If the list is currently empty, it sets both the head and tail pointers to the new Node.
    // If the list is not empty, it sets the next pointer of the current tail Node to the new Node
    // and updates the tail pointer to the new Node.
    // Finally, it increments the length of the list.
    void Add(T value){
        // Create a new Node object with the given value and a null pointer for the next Node.
        Node<T>* tmp = new Node<T>{value,NULL};
        
        // If the list is currently empty, set both the head and tail pointers to the new Node.
        if(pHead==NULL){
            pTail = pHead = tmp;
        }else{
            // If the list is not empty, set the next pointer of the current tail Node to the new Node
            // and update the tail pointer to the new Node.
            pTail->next = tmp;
            pTail = pTail->next;
        }
        
        // Increment the length of the list.
        Length++;
    }
    // This function inserts a new Node at a specified index in the list.
    // It creates a new Node object with the given value and a null pointer for the next Node.
    // If the index is equal to the length of the list, the new Node is inserted at the end of the list.
    // If the index is less than zero, the function returns without doing anything.
    // If the index is greater than zero and less than the length of the list, the function finds the Node
    // at the specified index and inserts the new Node between it and its next Node.
    // Finally, it increments the length of the list.
    void Insert(int index,T value){
        // If the index is equal to the length of the list, we can simply call the Add function.
        if(index == Length)return Add(value);
        // If the index is less than zero, we don't need to do anything.
        if(index<0)return;
        
        // Create a new Node object with the given value and a null pointer for the next Node.
        Node<T> *tmp = new Node<T>{value,NULL};
        
        // If the index is equal to zero, we can insert the new Node at the beginning of the list.
        if(index == 0){
            // Set the next pointer of the new Node to the current head of the list.
            tmp->next = pHead;
            // Set the head of the list to the new Node.
            pHead = tmp;
        }else{
            // If the index is greater than zero, we need to find the Node at the specified index and insert the new Node between it and its next Node.
            
            // Start at the head of the list.
            Node <T>*p =pHead;
            
            // Iterate through the list until we reach the specified index.
            for(int i =1;i<index;i++,p=p->next){
                // Set the next pointer of the new Node to the next Node after the current Node.
                tmp->next = p->next;
                // Set the next pointer of the current Node to the new Node.
                p->next = tmp;
            }
        }
        // Increment the length of the list.
        Length++;
    }
    // This function deletes a Node at a specified index from the list.
    // If the list is empty or the index is out of range, the function returns without doing anything.
    // If the index is equal to zero, the function deletes the head Node and updates the head pointer to the next Node.
    // If the index is greater than zero and less than the length of the list, the function finds the Node
    // at the specified index and deletes it by updating the next pointers of the previous and next Nodes.
    // Finally, it decrements the length of the list.
    void Delete(int index){
        // If the list is empty, we don't need to do anything.
        if(Length==0)return;
        // If the index is out of range, we don't need to do anything.
        if(index<0||index>=Length)return;

        // Create a temporary pointer to iterate through the list.
        Node<T>*tmp = pHead;
        
        // If the index is equal to zero, we can delete the head Node.
        if(index==0){
            // Set the head pointer to the next Node of the current head Node.
            pHead = tmp->next;
            // Set the next pointer of the current head Node to NULL to avoid memory leaks.
            tmp->next = NULL;
            // Delete the current head Node.
            delete tmp;

        }else{
            // If the index is greater than zero, we need to find the Node at the specified index and delete it.
            
            // Start at the head of the list.
            Node<T>*p = pHead;
            
            // Iterate through the list until we reach the previous Node of the specified index.
            for(int i=1;i<index;i++,p=p->next);
            // Set the temporary pointer to the Node at the specified index.
            tmp = p->next;
            // Set the next pointer of the previous Node to the next Node after the Node at the specified index.
            p->next = tmp->next;
            // Set the next pointer of the Node at the specified index to NULL to avoid memory leaks.
            tmp->next = NULL;
            // If the Node at the specified index is the tail Node, update the tail pointer to the previous Node.
            if(pTail== tmp) pTail=p;
            // Delete the Node at the specified index.
            delete tmp;     
        }
        // Decrement the length of the list.
        Length--;
    }
    // This function prints the values of all the Nodes in the list.
    // It starts at the head of the list and iterates through each Node,
    // printing the value of each Node.
    // The iteration continues until we reach the end of the list (i.e., NULL).
    // Finally, it prints a newline character to separate the list from the rest of the output.
    void Print(){
        // Start at the head of the list.
        Node<T>* currentNode = pHead;
        
        // Iterate through each Node in the list.
        while(currentNode != NULL){
            // Print the value of the current Node.
            cout << currentNode->value << " ";
            
            // Move to the next Node in the list.
            currentNode = currentNode->next;
        }
        
        // Print a newline character to separate the list from the rest of the output.
        cout << endl;
    }
    int GetLength(){
        return Length;
    }
};

// This is the main function that demonstrates the creation and traversal of a one-way linked list.
// It creates a new instance of the OneWayList class and adds some values to it.
// Then it inserts a new value at the beginning of the list.
// After that, it calls the Print function to display the contents of the list.
// The while loop continues until the length of the list is zero.
// Inside the loop, it deletes the first Node of the list and calls the Print function again.
int main(){
    // Create a new instance of the OneWayList class.
    OneWayList<string> list;
    
    // Add some values to the list.
    list.Add("Liza");
    list.Add("Nika");
    list.Add("Alex");
    
    // Insert a new value at the beginning of the list.
    list.Insert(0,"Jonh");
    
    // Display the contents of the list.
    list.Print();
    
    // Continue until the length of the list is zero.
    while(list.GetLength()>0){
        // Delete the first Node of the list.
        list.Delete(0);
        
        // Display the updated contents of the list.
        list.Print();
    }
    
    OneWayList<int> list2;
    list2.Add(1);
    list2.Add(2);
    list2.Add(3);
    list2.Add(4);
    list2.Insert(0,5);
    list2.Print();

    // Return 0 to indicate successful execution.
    return 0;
}
