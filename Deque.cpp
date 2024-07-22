#include <iostream>
#include <ranges>
#include <deque>
using namespace std;
void Print(deque<string> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << endl;
}
int main()
{
    deque<string> person;
    person.push_front("Nika");
    person.push_back("Liza"); 
    person.push_front("Thanakrit");
   // person.pop_front();
    person.emplace(person.begin(),"Jojo");
    for(auto i=person.rbegin();i != person.rend();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    Print(person);
    return 0;
}