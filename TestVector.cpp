#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main(){
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    swap(vec[0],vec[1]);
    vec.emplace_back(40);
    vec.emplace(vec.begin()+2,90);
    for(auto i:vec){
        cout<<i<< " ";
    }
    cout<<endl;
    vec.erase(vec.begin()+1);
    
    cout<<"Total space "<<vec.capacity()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }

    cout<<endl;

    return 0;
}