#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        int a;
        cin >> a;
        string s;
        cin >> s;

        if (a <= 3)
        {
            cout << "NO" << endl;
            continue;
        }

        int i = 0;
        while (s[i] == 'm' || s[i] == 'M')
            i++;

        if (i == 0)
        {
            cout << "NO" << endl;
            continue;
        }

        int j = i;
        while (s[j] == 'e' || s[j] == 'E')
            j++;

        if (j == i)
        {
            cout << "NO" << endl;
            continue;
        }

        int k = j;
        while (s[k] == 'o' || s[k] == 'O')
            k++;

        if (k == j)
        {
            cout << "NO" << endl;
            continue;
        }

        int l = k;
        while (s[l] == 'w' || s[l] == 'W')
            l++;

        if (l == k || a > l)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}