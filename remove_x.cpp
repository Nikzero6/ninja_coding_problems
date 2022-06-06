#include <iostream>
using namespace std;
#include <string>

void remove_x(string &s, int i)
{
    if (i > s.size() - 1)
        return;

    if (s[i] == 'x')
    {
        s.erase(i, 1);
        return remove_x(s, i);
    }

    return remove_x(s, i + 1);
}
int main()
{
    string s;
    cin >> s;

    remove_x(s, 0);

    cout << s;

    return 0;
}