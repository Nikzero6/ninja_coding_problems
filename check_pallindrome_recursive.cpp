#include <iostream>
using namespace std;
#include <string>

bool pallindrome(string s, int i, int j)
{
    if (i >= j)
        return true;

    if (s[i] != s[j])
        return false;

    return pallindrome(s, i + 1, j - 1);
}
int main()
{
    string s;
    cin >> s;

    cout << pallindrome(s, 0, s.size() - 1) << endl;
    return 0;
}