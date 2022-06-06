#include <iostream>
using namespace std;
#include <string>

void pair_star(string &s, int i)
{
    if (i > s.size() - 1)
        return;

    if (s[i] == s[i + 1])
    {
        s.insert(s.begin() + i + 1, '*');
        return pair_star(s, i + 2);
    }

    return pair_star(s, i + 1);
}
int main()
{
    string s;
    cin >> s;
    pair_star(s, 0);
    cout << s << endl;
    return 0;
}