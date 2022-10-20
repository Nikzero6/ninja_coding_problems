#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int rs, rh;
int y_min = INT_MAX, r_min = INT_MAX, y_score = 0, r_score = 0;
int n, m;

int getDistance(int x, int y)
{
    return x * x + y * y;
}

bool isInside(int d)
{
    return d <= (rs + rh) * (rs + rh);
}

void solve(vector<int> r_dis, vector<int> y_dis)
{
    if (r_min < y_min)
    {
        for (auto d : r_dis)
        {
            if (isInside(d) && d < y_min)
                r_score++;
        }
    }
    else
    {
        for (auto d : y_dis)
        {
            if (isInside(d) && d < r_min)
                y_score++;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++)
    {
        y_min = INT_MAX, r_min = INT_MAX, y_score = 0, r_score = 0;
        cin >> rs >> rh;
        cin >> n;
        vector<int> r_stones(n);
        for (int i = 0; i < n; i++)
        {
            int z, w;
            cin >> z >> w;
            r_stones[i] = getDistance(z, w);
            r_min = min(r_stones[i], r_min);
        }

        cin >> m;
        vector<int> y_stones(m);
        for (int i = 0; i < m; i++)
        {
            int z, w;
            cin >> z >> w;
            y_stones[i] = getDistance(z, w);
            y_min = min(y_min, y_stones[i]);
        }

        solve(r_stones, y_stones);

        cout << "Case #" << x << ": " << r_score << " " << y_score << endl;
    }

    return 0;
}