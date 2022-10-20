#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++)
    {
        int m, n, id;
        cin >> m >> n >> id;
        vector<int> maxArr(n, 0);
        bool johnDone = false;
        ll ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int step;
                cin >> step;

                if (id == i + 1)
                {
                    if (maxArr[j] > step)
                        ans += (maxArr[j] - step);
                    else
                        maxArr[j] = step;

                    johnDone = true;
                }
                else if (step > maxArr[j])
                {
                    if (johnDone)
                        ans += (step - maxArr[j]);
                    maxArr[j] = step;
                }
            }
        }

        cout << "case #" << x << ": " << ans << endl;
    }

    return 0;
}