#include <iostream>
#include <ranges>
#include <deque>
using namespace std;
void Print(deque<int> q)
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
    deque<int> q;
    for (int i = 1; i < 12; i++)
    {
        if (i % 2 == 0)
            q.push_front(i);
        else
            q.push_back(i);
    }
    Print(q);
    q.emplace(q.begin() + 2, 20);
    q.emplace_front(25);
    q.emplace_back(78);
    Print(q);
    return 0;
}