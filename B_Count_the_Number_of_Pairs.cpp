#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int lower[26] = {0};
        int upper[26] = {0};

        for (auto c : s)
            if (c >= 'a' && c <= 'z')
                lower[c - 'a']++;
            else
                upper[c - 'A']++;

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (lower[i] == upper[i])
                count += lower[i];
            else if (k > 0)
            {
                int pair = min(lower[i], upper[i]);
                int min_req = abs(lower[i] - upper[i]) / 2;
                if (min_req > k)
                {
                    count += (pair + k);
                    k = 0;
                }
                else
                {
                    count += (pair + min_req);
                    k -= min_req;
                }
            }
            else
            {
                count += min(lower[i], upper[i]);
            }
        }

        cout << count << endl;
    }

    return 0;
}