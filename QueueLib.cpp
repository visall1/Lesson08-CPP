#include<iostream>
#include<queue>
#include<ranges>
#include<vector>
using namespace std;

struct withPriority{
    string name;
    int prio;
};
int main(){
    initializer_list<withPriority> list = {
        {"Liza", 2},
        {"Nika", 1},
        {"Alex", 3}
    };
    struct{
        bool operator()(const withPriority &l,const withPriority &r){
            return l.prio < r.prio;
        }
    }custom;
    priority_queue students(list.begin(), list.end(),custom);
    while(!students.empty()){
        cout<<students.top().name<<endl;
        students.pop();
    }
    return 0;
}
