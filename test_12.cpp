#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool pallindrome(string s)
{
    int start = 0, end = s.size() - 1;

    while (start < end)
    {
        if (s[start] != s[end])
            return false;

        start++;
        end--;
    }

    return true;
}

void solve(string s, string sub, vector<string> ans, vector<vector<string>> &ds)
{
    if (s.size() == 0)
    {
        ds.push_back(ans);
        return;
    }

    if (pallindrome(sub + s[0]))
    {
        if (s.size() == 1)
            ans.push_back(sub + s[0]);  
        solve(s.substr(1), sub + s[0], ans, ds);
        if (sub != "")
            ans.push_back(sub);
        solve(s.substr(1), "", ans, ds);
    }
    else
    {
        ans.push_back(sub);
        solve(s, "", ans, ds);
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ds;
    vector<string> ans;
    solve(s, "", ans, ds);
    return ds;
}

int main()
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for (auto it : ans)
    {
        for (auto vec : it)
        {
            cout << vec << " ";
        }
        cout << endl;
    }
    return 0;
}
