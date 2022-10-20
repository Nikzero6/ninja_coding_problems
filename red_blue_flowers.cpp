#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t)
    {
        int n;
        cin >> n;

        vector<int> x(n, 0);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        vector<int> y(n, 0);
        for (int j = 0; j < n; j++)
            cin >> y[j];

        int maxMin = 0;
        int sum_x = x[0], sum_y = y[0], pre_x = x[0], pre_y = y[0];

        for (int i = 1; i < n; i++)
        {
            int ans = 0, new_pre_x = pre_x, new_pre_y = pre_y;

            // take x
            ans = min(pre_x + x[i], pre_y);

            if (ans > maxMin)
            {
                new_pre_x = pre_x + x[i];
                maxMin = ans;
            }

            // take y
            ans = min(pre_x, pre_y + y[i]);

            if (ans > maxMin)
            {
                new_pre_x = pre_x;
                new_pre_y = pre_y + y[i];
                maxMin = ans;
            }

            // new x
            ans = min(x[i], sum_y);

            if (ans > maxMin)
            {
                new_pre_x = x[i];
                new_pre_y = sum_y;
                maxMin = ans;
            }

            // new y
            ans = min(sum_x, y[i]);

            if (ans > maxMin)
            {
                new_pre_x = sum_x;
                new_pre_y = y[i];
                maxMin = ans;
            }

            pre_x = new_pre_x, pre_y = new_pre_y;
            sum_x += x[i], sum_y += y[i];
        }
        cout << maxMin << endl;
        t--;
    }

    return 0;
}
