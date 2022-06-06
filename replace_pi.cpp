#include <iostream>
using namespace std;
#include <string>

void replace_pi(string &s, int i)
{
    if (i > s.size() - 2)
        return;

    if (s[i] == 'p' && s[i + 1] == 'i')
    {
        s.replace(i, 2, "3.14");
        return replace_pi(s, i + 4);
    }

    return replace_pi(s, i + 1);
}
int main()
{
    string s;
    cin >> s;

    replace_pi(s, 0);

    cout << s;

    return 0;
}