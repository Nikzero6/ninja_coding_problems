#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        unordered_map<char, int> h;

        for (auto c : s)
            h[c]++;

        if (h.size() == 1)
            cout << -1 << endl;
        else if (h.size() == 2)
        {
            unordered_map<char, int>::iterator it;
            it = h.begin();
            int a = it->second;
            it++;
            int b = it->second;

            if (a == 2)
                cout << 4 << endl;
            else
                cout << 6 << endl;
        }
        else
            cout << 4 << endl;
    }

    return 0;
}