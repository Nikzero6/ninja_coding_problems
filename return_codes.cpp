#include <iostream>
using namespace std;
#include <vector>
#include <string>

void return_codes(string s, string ans, vector<string> &ds)
{
    if (s.empty())
    {
        ds.push_back(ans);
        return;
    }

    if (s.size() == 1)
    {
        ans.push_back(s[0] + 48);
        ds.push_back(ans);
        return;
    }

    if (s[0] < 51 && s[1] < 55)
    {
        ans.push_back(s[0] + 48);
        return_codes(s.substr(1), ans, ds);
        ans.pop_back();
        ans.push_back((s[0] - 48) * 10 + (s[1] - 48) + 96);
        return_codes(s.substr(2), ans, ds);
    }
    else
    {
        ans.push_back(s[0] + 48);
        return_codes(s.substr(1), ans, ds);
    }
}
int main()
{
    string s;
    cin >> s;

    vector<string> ds;
    return_codes(s, "", ds);

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