#include <iostream>
using namespace std;
#include <string>

void print_subsequence(string s, int i, string ans)
{
    if (i > s.size() - 1)
    {
        cout << ans << endl;
        return;
    }

    ans.push_back(s[i]);
    print_subsequence(s, i + 1, ans);
    ans.pop_back();
    print_subsequence(s, i + 1, ans);
}
int main()
{
    string s;
    cin >> s;

    print_subsequence(s, 0, "");

    return 0;
}