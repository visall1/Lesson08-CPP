#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node<T> *next;
    Node<T> *prev;
};
template <class T>
class DoubleLinkedList
{
private:
    Node<T> *pHead;
    Node<T> *pTail;
    int Count;

public:
    DoubleLinkedList();
    // ~DoubleLinkedList()
    // {
    //     delete[] pHead;
    //     delete[] pTail;
    //     delete[] Count;
    // }
    void Add(T);
    void Insert(int, T);
    void Print();
    void Delete(int index);
    int getCount() { return Count; }
    void PrintReverse();
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    pHead = NULL;
    pTail = NULL;
    Count = 0;
}

/**
 * This function adds a new node to the end of the list.
 * It creates a new Node object with the given value and a null pointer for the next and previous nodes.
 * If the list is currently empty, it sets both the head and tail pointers to the new node.
 * If the list is not empty, it sets the next pointer of the current tail node to the new node
 * and updates the tail pointer to the new node.
 * Finally, it increments the length of the list.
 */
template <class T>
void DoubleLinkedList<T>::Add(T value)
{
    // Create a new Node object with the given value and a null pointer for the next and previous nodes.
    Node<T> *tmp = new Node<T>{value, nullptr, nullptr};

    // If the list is currently empty, set both the head and tail pointers to the new node.
    if (pHead == NULL)
    {
        pTail = pHead = tmp;
    }
    else
    {
        // If the list is not empty, set the next pointer of the current tail node to the new node
        // and update the tail pointer to the new node.
        pTail->next = tmp;
        tmp->prev = pTail;
        pTail = pTail->next;
    }

    // Increment the length of the list.
    Count++;
}

/**
 * This function inserts a new node at a specified index in the list.
 * It creates a new Node object with the given value and a null pointer for the next and previous nodes.
 * If the index is less than zero, the function returns without doing anything.
 * If the index is greater than or equal to the length of the list, the function adds the new node to the end of the list.
 * If the index is equal to zero, the new node is inserted at the beginning of the list.
 * If the index is between zero and the length of the list minus one, the function finds the node at the specified index
 * and inserts the new node between it and its next node.
 * Finally, it increments the length of the list.
 */
template <class T>
void DoubleLinkedList<T>::Insert(int index, T value)
{
    // Create a new Node object with the given value and a null pointer for the next and previous nodes.
    Node<T> *tmp = new Node<T>{value, NULL, NULL};

    // If the index is less than zero, return without doing anything.
    if (index < 0)
        return;
    // If the index is greater than or equal to the length of the list, add the new node to the end of the list.
    if (index >= Count)
        return Add(value);
    // If the index is equal to zero, insert the new node at the beginning of the list.
    if (index == 0)
    {
        // Set the next pointer of the new node to the current head of the list.
        tmp->next = pHead;
        // Set the previous pointer of the current head of the list to the new node.
        pHead->prev = tmp;
        // Set the head of the list to the new node.
        pHead = tmp;
    }
    else
    {
        // If the index is between zero and the length of the list minus one, find the node at the specified index
        // and insert the new node between it and its next node.
        Node<T> *p = pHead;
        for (int i = 0; i < index; i++, p = p->next)
        {
            // Set the next pointer of the new node to the next node after the current node.
            tmp->next = p->next;
            // Set the previous pointer of the next node to the new node.
            tmp->next->prev = tmp;
            // Set the next pointer of the current node to the new node.
            p->next = tmp;
            // Set the previous pointer of the new node to the current node.
            tmp->prev = p;
        }
    }
    // Increment the length of the list.
    Count++;
}

template <class T>
void DoubleLinkedList<T>::Print()
{
    Node<T> *currentNode = pHead;
    while (currentNode != NULL)
    {
        cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

template <class T>
void DoubleLinkedList<T>::Delete(int index)
{
    Node<T> *tmp = pHead;
    if (Count == 0)
        return;
    if (index < 0 || index >= Count)
        return;
    if (index == 0)
    {
        pHead = tmp->next;
        tmp->next = NULL;
        if (pHead != NULL)
            pHead->prev = NULL;
        delete tmp;
    }
    else
    {
        Node<T> *p = pHead;
        for (int i = 0; i < index; i++, p = p->next)
        {
            tmp = p->next;
            p->next = tmp->next;
            tmp->next->prev = p;
            tmp->next = NULL;
            tmp->prev = NULL;
            if (pTail == tmp)
                pTail = p;
            delete tmp;
        }
    }
    Count--;
}

template <class T>
void DoubleLinkedList<T>::PrintReverse()
{
    for (auto i = pTail; i != NULL; i = i->prev)
    {
        cout<<i->value<<" ";
    }
    cout<<endl;
}

int main()
{
    DoubleLinkedList<int> list;
    list.Add(10);
    list.Add(20);
    list.Add(30);
    list.Add(40);
    list.Insert(1, 5);
    list.Print();
    list.Delete(1);
    cout<<"Count : "<<list.getCount()<<endl;
    list.Print();
    list.PrintReverse();

    return 0;
}
