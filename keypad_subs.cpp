#include <iostream>
using namespace std;
#include <vector>
#include <string>

void print_comb(vector<string> keypad, string s, string ans)
{
    if (s.empty())
    {
        cout << ans << endl;
        return;
    }

    string key = keypad[s[0] - 48];

    for (int i = 0; i < key.size(); i++)
    {
        ans.push_back(key[i]);
        print_comb(keypad, s.substr(1), ans);
        ans.pop_back();
    }
}
int main()
{
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string s;
    cin >> s;

    print_comb(keypad, s, "");

    return 0;
}