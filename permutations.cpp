#include <iostream>
using namespace std;
#include <string>
#include <vector>

void permutations(string s, vector<string> &ds, string ans)
{
    if (s.empty())
    {
        ds.push_back(ans);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        ans.push_back(s[i]);
        string newString = s;
        newString.erase(i, 1);
        permutations(newString, ds, ans);
        ans.pop_back();
    }
}
int main()
{
    string s;
    cin >> s;

    vector<string> ds;

    permutations(s, ds, "");

    for (auto it : ds)
    {
        for (auto vec : it)
        {
            cout << vec << " ";
        }
        cout << endl;
    }

    return 0;
}