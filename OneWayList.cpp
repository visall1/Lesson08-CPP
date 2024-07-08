#include<iostream>
using namespace std;
struct Node{
    string value;
    Node *next;
};
class OneWayList
{
private:
    Node* pHead;
    Node*pTail;
    int Length;
public:
    OneWayList():pHead(nullptr),pTail(nullptr){}
    void Add(string value){
        Node* tmp = new Node{value,NULL};
        if(pHead==NULL){
            pTail = pHead = tmp;
        }else{
            pTail->next = tmp;
            pTail = pTail->next;
        }
        Length++;
    }
    void Insert(int index,string value){
        if(index == Length)return Add(value);
        if(index<0)return;
        
        Node*tmp = new Node{value,NULL};
        if(index == 0){
            tmp->next = pHead;
            pHead = tmp;
        }else{
            Node*p =pHead;
            for(int i =1;i<index;i++,p=p->next){
                tmp->next = p->next;
                p->next = tmp;
            }
        }
        Length++;
    }
    void Delete(int index){
        if(Length==0)return;
        if(index<0||index>=Length)return;

        Node*tmp = pHead;
        if(index==0){
            pHead = tmp->next;
            tmp->next = NULL;
            delete tmp;

        }else{
            Node*p = pHead;
            for(int i=1;i<Length;i++,p=p->next);
                tmp = p->next;
                p->next = tmp->next;
                tmp->next = NULL;
                if(pTail== tmp) pTail=p;
                delete tmp;     
        }
        Length--;
    }
    void Print(){
        for(Node*i=pHead;i!=NULL;i=i->next){
            cout<<i->value<<" ";
        }
        cout<<endl;
    }
    int GetLength(){
        return Length;
    }
};

// This is the main function that demonstrates the creation and traversal of a one-way linked list.
int main(){
    OneWayList list;
    list.Add("Liza");
    list.Add("Dima");
    list.Add("Vova");
    list.Insert(0,"Petya");
    list.Print();
    while(list.GetLength()>0){
        list.Delete(0);
        list.Print();
    }
    return 0;
}
