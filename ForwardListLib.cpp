#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
    forward_list<int> lst;
    lst.push_front(13);//|13|
    lst.emplace_front(15);//|15|13|
    lst.insert_after(lst.begin(),78);//|15|78|13|
    forward_list<int> lst2;
    lst2.push_front(3);
    lst2.push_front(2);
    lst2.push_front(1);
    auto d = 5.5;// <=> double d = 5.5;
    auto it = lst.begin();// <=> forward_list<int>::iterator it = lst.begin();
    it++;
    lst.splice_after(it,lst2);//15 78 1 2 3 13

    for(int i:lst){//foreach
        cout<<i<<" ";
    }
    cout<<endl;
    for(it = lst.begin(); it != lst.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
