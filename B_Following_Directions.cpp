#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int x = 0, y = 0;
        bool passed = false;

        for (const char &c : s)
        {
            if (c == 'U')
                y++;
            else if (c == 'D')
                y--;
            else if (c == 'R')
                x++;
            else
                x--;

            if (x == 1 && y == 1)
            {
                passed = true;
                cout << "YES" << endl;
                break;
            }
        }

        if (!passed)
            cout << "NO" << endl;
    }

    return 0;
}