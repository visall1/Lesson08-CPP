#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<string> lst;
    lst.push_back("Thanak");//"Thanak"
    lst.push_front("Sophal");//"Sophal", "Thanak"
    lst.emplace_back("Chanthana");//"Sophal", "Thanak", "Chanthana"
    lst.emplace_front("TAILY");//"TAILY", "Sophal", "Thanak", "Chanthana"
    lst.insert(++lst.begin(), "Visal");//"TAILY","Visal","Sophal","Thanak","Chanthana"
    for(auto i:lst){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto it=lst.rbegin(); it!=lst.rend(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(list<string>::iterator it=lst.begin(); it!=lst.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
