#include <iostream>
using namespace std;

bool check_AB(string s, char prev)
{

    if (prev == '\0' && s[0] != 'a')
        return false;

    if (s.size() == 0)
        return true;

    if (s.size() == 1)
    {
        if (s[0] == 'a')
            return true;
        else
            return false;
    }

    if (s[0] == 'a' && s[1] == 'a')
        return check_AB(s.substr(2), 'a');
    else if (s[0] == 'a' && s[1] == 'b')
        return check_AB(s.substr(1), 'a');
    else if (s[0] == 'b' && s[1] == 'b' && prev != 'b')
        return check_AB(s.substr(2), 'b');
    else
        return false;
}
int main()
{
    string s;
    cin >> s;

    cout << check_AB(s, '\0') << endl;

    return 0;
}