#include<iostream>
using namespace std;
template<class T>struct  Elem{
    int data;
     Elem* next;
     Elem* prev;
};
template<class T>class List{
private:
    Elem<T> *pHead;
    Elem<T> *pTail;
    int Count;
public:
    List():pHead(NULL),pTail(NULL),Count(0){}
    List(const List&);
    ~List();
 
    int getCount();
    Elem<T> *getElement(int);

    void DelAll();
    void Delete(int);
    void Delete();
    
    void AddTail(T);
    void AddTail();
    
    void AddHead(T);
    void AddHead();

    void Print();
    void Print(int pos);

    List& operator=(const List&);
    List& operator+(const List&);

    bool operator==(const List&);
    bool operator!=(const List&);
    bool operator<=(const List&);
    bool operator >=(const List&);
    bool operator<(const List&);
    bool operator<(const List&);

    List operator-();
};

template <class T>
List<T>::List(const List &l)
{
    pHead = pTail = NULL;
    Count = 0;

    Elem<T> *tmp = l.pHead;
    while(tmp!=NULL){
        AddTail(tmp->data);
        tmp = tmp->next;
    }
}

template <class T>
List<T>::~List()
{
    DelAll();
}

template <class T>
Elem<T> *List<T>::getElement(int pos)
{
    Elem<T> *tmp = pHead;
    if(pos < 1 || pos > Count){
        cout<<"Position out of range"<<endl;
        return;
    }
    int i=1;
    while(i < pos && tmp !=NULL){
        tmp = tmp->next;
        i++;
    }
    if(tmp != NULL) return tmp;
    else return 0;
}

template <class T>
void List<T>::AddHead()
{
    Elem<T> *tmp = new Elem<T>;
    tmp->prev = 0;
    int data;
    cout<<"Enter Data: ";
    cin>>data;
    if(pHead != NULL)  pHead->prev = tmp;
    if(Count == 0) pHead = pTail = tmp;
    else{
        tmp->next = pHead;
        pHead = tmp;
    }
    Count++;
}
