#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    vector<string> v;
    v.push_back("Thanak");//"Thanak"
    v.push_back("Sophal");//"Thanak", "Sophal"
    swap(v[0],v[1]);//"Sophal", "Thanak"
    v.emplace_back("Chanthana");//"Sophal", "Thanak", "Chanthana"
    v.emplace_back("TAILY");//"TAILY", "Sophal", "Thanak", "Chanthana"
    swap(v[0],v[3]);
    v.insert(++v.begin(), "Visal");//"TAILY","Visal","Sophal","Thanak","Chanthana"
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+2);
    v.erase(v.begin()+2);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"Total space = reserve+elements = "<<v.capacity()<<endl;
    cout<<"Size = nb of elements = "<<v.size()<<endl;
    v.shrink_to_fit();
    cout<<"Total space = reserve+elements = "<<v.capacity()<<endl;
    cout<<"Size = nb of elements = "<<v.size()<<endl;
    v.resize(8);
    cout<<"Total space = reserve+elements = "<<v.capacity()<<endl;
    cout<<"Size = nb of elements = "<<v.size()<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<"|";
    }
    cout<<endl;
    v.reserve(20);
    v.push_back("Visal2");
    cout<<"Total space = reserve+elements = "<<v.capacity()<<endl;
    cout<<"Size = nb of elements = "<<v.size()<<endl;
    cout<<"Max size = " <<v.max_size()<<endl;
    return 0;
}
