#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string> person;
    person.push("Liza");
    person.push("Thanakrit");
    person.push("Nika");
    person.push("Alex");


    cout<<"Top: "<< person.top()<<endl;
    person.pop();
    while(!person.empty()){
        cout<< person.top()<<endl;
        person.pop();
    }
    
    return 0;
}