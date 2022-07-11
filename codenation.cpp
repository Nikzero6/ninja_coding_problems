#include <iostream>
#include <vector>
using namespace std;

int worthy_king(vector<int> &a)
{
    int troops = 0;
    int x = 1;
    int d = 0;

    int n = a.size();

    sort(a.begin(), a.end(), greater<int>());

    while (n)
    {
        bool flag = true;

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == -1)
                continue;

            if (a[i] <= troops)
            {
                a[i] = -1;
                x++;
                troops = 0;
                n--;
                flag = false;
            }
        }

        if (flag)
        {
            d++;
            troops += x;
        }
    }

    return d;
}

int worthy_king_2(vector<int> &a)
{
    int x = 1;
    int d = 0;

    int n = a.size();

    sort(a.begin(), a.end());

    d = a[0];
    x++;

    int i = 1;
    while (i < n)
    {
        if (a[i] == -1)
        {
            i++;
            continue;
        }

        int fact = a[i] / x;

        if (a[i] % x == 0)
        {
            a[i] = -1;
            x++;
            i++;
            d += fact;
        }
        else
        {
            fact += 1;
            int j = i;
            while (j < n)
            {
                if (a[j] <= x * fact && a[j] != -1)
                    j++;
                else
                    break;
            }
            a[j - 1] = -1;
            x++;
            d += fact;
        }
    }

    return d;
}

int maxPow(int x, int target)
{
    int i = 1, j = x;

    int ans = INT_MIN;
    while (i <= j)
    {
        int mid = (j - i) / 2 + i;

        if (mid <= target)
        {
            ans = max(ans, mid);
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }

    return ans;
}

int minPow(int x, int target)
{
    int ans = 2;

    if (target < 0)
    {
        while (ans <= x - 2 && ans < (0 - target))
        {
            ans += 2;
        }
    }

    return ans;
}

void minEnergies(vector<int> &dp, vector<int> &ds, int ans, int c, int i, int size)
{
    if (i >= dp.size() && size < c)
        return;

    if (c == size)
    {
        ds.push_back(ans);
        return;
    }

    ans = min(ans, dp[i]);

    minEnergies(dp, ds, ans, c, i + 1, size + 1);
    minEnergies(dp, ds, INT_MAX, c, i + 1, 0);
}

vector<int> horse_race(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();
    vector<int> dp(n, 0);

    int count = n;
    while (count)
    {
        count = 0;

        for (int i = 0; i < n; i++)
        {
            if (A[i] == 0)
                continue;

            A[i] -= maxPow(B[i], A[i]);
            dp[i]++;

            if (A[i] == 0)
                continue;

            A[i] += minPow(B[i], A[i]);
            dp[i]++;

            if (A[i] == 0)
                continue;

            count++;
        }
    }

    vector<int> ds;
    int ans;
    minEnergies(dp, ds, INT_MAX, C, 0, 0);

    return ds;
}

// * 0 0 0 0
// 0 x x x 0
// 0 x x x 0
// 0 x x x 0
// 0 0 0 0 0

bool isSafe(int i, int j, int m, int n, vector<vector<int>> sea)
{
    if (i < 0 || i >= m || j < 0 || j >= n || sea[i][j] == -1)
        return false;

    return true;
}

int dfs(vector<vector<int>> &sea, int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
        return 1;

    int count = 0;

    if (isSafe(i, j, m, n, sea))
    {
        sea[i][j] = 1;
        count += dfs(sea, i + 1, j, m, n);
        count += dfs(sea, i, j + 1, m, n);
    }

    return count;
}

int safe_swim(int m, int n, int b)
{
    vector<vector<int>> sea(m, vector<int>(n, 0));

    int dir_x[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dir_y[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

    int mid_i = m / 2, mid_j = n / 2;
    sea[mid_i][mid_j] = -1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < b; j++)
        {
            int x = (dir_x[i] > 0) ? j : -j;
            int y = (dir_y[i] > 0) ? j : -j;
            sea[mid_i + dir_x[i] + x][mid_j + dir_y[i] + y] = -1;
        }
    }

    return dfs(sea, 0, 0, m, n);
}

int main()
{
    // worthy king
    // a : array of neighbours (troops)
    // n = a.size() <= 20
    // a[i] <= 10^5
    // find min num of days to capture all neighbours
    // vector<int> a = {1, 1, 1, 5, 9, 8};      //8
    // vector<int> a = {66982, 67681, 89888};   //130786
    // vector<int> a = {1, 3, 4, 6, 8, 12};     //10
    // vector<int> a = {4, 5, 7, 5, 7, 10};     //15
    // vector<int> a = {4, 3, 1};               //4
    // cout << worthy_king(a) << endl;
    // cout << worthy_king_2(a) << endl;

    // horse race
    // finish lines for horses: A {7, 3, 9}
    // power of horses: B {3, 10, 15}
    // consectuive subarray size: C
    // return energy of horses with min energy expanded in subarrays
    // vector<int> A = {7, 3, 1}; //[1, 1]
    // vector<int> B = {3, 10, 15};
    // int C = 2;
    // vector<int> A = {7, 9, 11}; //[1, 1]
    // vector<int> B = {3, 15, 5};
    // int C = 2;
    // vector<int> ans = horse_race(A, B, C);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // safe swim
    // * 0 0 0 0
    // 0 x x x 0
    // 0 x x x 0
    // 0 x x x 0
    // 0 0 0 0 0
    // m: rows (5)  always odd
    // n: cols (5)  always odd
    // b: toxic range (1)
    // moves allowes: down or right
    int m, n, b;
    cin >> m >> n >> b;
    cout << safe_swim(m, n, b) << endl;

    return 0;
}