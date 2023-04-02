#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<string> b = {"and",
                        "not",
                        "that",
                        "the",
                        "you"};

    for (const string &s : a)
    {
        for (const string &c : b)
            if (s == c)
            {
                cout << "Yes" << endl;
                return 0;
            }
    }

    cout << "No" << endl;

    return 0;
}