#include <iostream>
#include <map>
using namespace std;
int main()
{
    

    map<string, int> scores;
    scores["Liza"] = 20;
    scores["Nika"] = 30;
    scores["Alex"] = 10;
    scores["Jonh"] = 50;

    // cout << scores["Nika"];
    scores.insert_range(scores.begin(), {{"Sivly", 15}, {"Thana", 19}});

    for (auto keyValue : scores)
    {
        cout << keyValue.first << "'s score is " << keyValue.second << endl;
    }

    map<int, string> ages;
    ages[20] = "Liza";
    ages[15] = "Sivly";
    ages[19] = "Thana";

    for (pair<int, string> keyValue : ages)
    {
        cout << keyValue.second << " is " << keyValue.first << endl;
    }

    map<string, string> dictionary;

    dictionary["Mango"] = "A kind of fruit that turns yellow when it is ripe";
    dictionary["Cow"] = "A mamal-kind animal used for farming.";
    dictionary["Cow"] = "A domestic animal that is typically kept as a pet";

    for (auto kv : dictionary)
    {
        cout << kv.first << " : " << kv.second << endl;
    }
    return 0;
}