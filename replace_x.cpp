#include <iostream>
using namespace std;
#include <string>

void replace_x(string &s, int i, char x, char y)
{
    if (i > s.size() - 1)
        return;

    if (s[i] == x)
    {
        s[i] = y;
    }

    return replace_x(s, i + 1, x, y);
}

void replace(char *s, char x, char y)
{
    if (s[0] == '\0')
        return;

    if (s[0] == x)
        s[0] = y;

    return replace(s + 1, x, y);
}
int main()
{
    string s;
    cin >> s;

    char s2[] = "axaskdaxxx";
    // replace_x(s, 0, 'x', 'y');

    replace(s2, 'x', 'y');

    cout << s2;

    return 0;
}