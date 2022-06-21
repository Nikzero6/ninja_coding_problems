#include <iostream>
using namespace std;
#include <string>

bool contain(string s, string t)
{
    if (t.empty())
        return true;

    if (s.empty())
        return false;

    if (s[0] == t[0])
        return contain(s.substr(1), t.substr(1));
    else
        return contain(s.substr(1), t);
}
int main()
{
    string s, t;
    cin >> s >> t;

    cout << contain(s, t) << endl;

    return 0;
}