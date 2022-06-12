#include <iostream>
using namespace std;
#include <string>

void remove(string &s, int i)
{
    if (i > s.size() - 1 || s.size() == 1)
        return;

    if (s[i] == s[i + 1])
    {
        s.erase(i, 1);
        return remove(s, i);
    }

    return remove(s, i + 1);
}
void remove_duplicates(char *s)
{
    if (s[0] == '\0')
        return;

    if (s[0] == s[1])
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            s[i] = s[i + 1];
        }

        return remove_duplicates(s);
    }

    return remove_duplicates(s + 1);
}
int main()
{
    // char s[] = "aaaaassdaddxxs";

    // remove_duplicates(s);

    // cout << s << endl;

    string s;
    cin >> s;

    remove(s, 0);

    cout << s << endl;
    return 0;
}