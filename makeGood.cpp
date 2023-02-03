#include <iostream>
#include <string>
using namespace std;

string makeGood(string s)
{
    bool flag = true;
    int diff = 'a' - 'A';

    while (flag)
    {
        int i = 1;
        flag = false;

        while (i < s.size())
        {
            if (!i)
                i++;

            if (abs(s[i - 1] - s[i]) == diff)
            {
                s.erase(s.begin() + i);
                s.erase(s.begin() + i - 1);
                i--;
                flag = true;
            }
            else
                i++;
        }
    }

    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << makeGood(s);
    return 0;
}