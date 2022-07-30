#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*------------------- smallest uncommon subsequence -----------------------*/

int sus_memo(string s, string t, vector<vector<int>> &memo)
{
    int m = s.size(), n = t.size();

    if (m == 0)
        return 1005;

    if (n == 0)
        return 1;

    if (memo[m][n] == -1)
    {
        int k = 0;
        while (k < n)
        {
            if (t[k] == s[0])
                break;

            k++;
        }

        if (k == n)
            return 1;

        memo[m][n] = min(sus_memo(s.substr(1), t, memo), 1 + sus_memo(s.substr(1), t.substr(k + 1), memo));
    }

    return memo[m][n];
}

int sus_dp(string s, string t)
{
    int m = s.size(), n = t.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1001));
    for (int i = 1; i < n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c = s[i - 1];
            int k;
            for (k = j - 1; j >= 0; j--)
                if (t[k] == c)
                    break;

            if (k == -1)
                dp[i][j] = 1;
            else
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][k]);
        }
    }

    return dp[m][n];
}

/*------------------- max square submatrix -----------------------*/

int max_square(vector<vector<int>> a)
{
    int m = a.size(), n = a[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = a[0][i] ^ 1;
        ans = max(ans, dp[0][i]);
    }

    for (int i = 1; i < m; i++)
    {
        dp[i][0] = a[i][0] ^ 1;
        ans = max(ans, dp[i][0]);
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

/*------------------- Coin tower -----------------------*/

// memoization
bool coin_tower_helper(int n, int x, int y, vector<int> &memo)
{
    if (n == 0)
        return true;

    if (memo[n] == -1)
    {
        bool a = false, b = false, c = false;

        if (n - 1 >= 0)
            a = coin_tower_helper(n - 1, x, y, memo);
        if (n - x >= 0)
            b = coin_tower_helper(n - x, x, y, memo);
        if (n - y >= 0)
            c = coin_tower_helper(n - y, x, y, memo);

        memo[n] = a || b || c;
    }

    return !memo[n];
}

string coint_tower(int n, int x, int y)
{
    vector<int> memo(n + 1, -1);

    if (coin_tower_helper(n, x, y, memo))
        return "whis";
    else
        return "beerus";
}

// tabulation
bool coin_tower_dp(int n, int x, int y)
{
    vector<bool> dp(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (i - 1 >= 0)
            dp[i] = dp[i] || !dp[i - 1];
        if (i - x >= 0)
            dp[i] = dp[i] || !dp[i - x];
        if (i - y >= 0)
            dp[i] = dp[i] || !dp[i - y];
    }

    return dp[n];
}

/*------------------- matrix chain multiplication -----------------------*/

int mcm(vector<int> a, int s, int e, vector<vector<int>> &memo)
{
    int n = a.size();

    if (s == e - 1)
        return 0;

    if (memo[s][e] == INT_MAX)
    {
        for (int k = s + 1; k < e; k++)
        {
            int x = mcm(a, s, k, memo) + mcm(a, k, e, memo) + a[s] * a[k] * a[e];
            memo[s][e] = min(memo[s][e], x);
        }
    }

    return memo[s][e];
}

int mcm_dp(vector<int> a)
{
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i + 1; j++)
            dp[i][j] = 0;
    }

    int i = 0, j = 2;

    while (i != 0 || j <= n)
    {
        i = 0;
        int k = j;

        while (k < n)
        {
            dp[i][k] = min(dp[i][k], dp[i][k - 1] + dp[k - 1][k] + a[i] * a[k - 1] * a[k]);
            i++, k++;
        }
        j++;
    }

    return dp[0][n - 1];
}

/*------------------- infinite coin change -----------------------*/

int coin_change_memo(vector<int> coins, int value, int i, vector<vector<int>> &memo)
{
    if (value == 0)
        return 1;

    if (value < 0 || i >= coins.size())
        return 0;

    if (memo[value][i] == -1)
    {
        int x = coin_change_memo(coins, value - coins[i], i, memo);
        int y = coin_change_memo(coins, value, i + 1, memo);
        memo[value][i] = x + y;
    }

    return memo[value][i];
}

int coin_change_dp(vector<int> coins, int val)
{
    int n = coins.size();
    vector<vector<int>> dp(val + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
        dp[0][i] = 1;

    for (int i = 1; i <= val; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];

            if (i - coins[j - 1] >= 0)
                dp[i][j] += dp[i - coins[j - 1]][j];
        }
    }

    return dp[val][n];
}

/*------------------- num of ways to represent as y = a^x + b^x + ... -----------------------*/

int all_possible_ways(int a, int b, int j)
{
    if (a < 0)
        return 0;

    if (a == 0)
        return 1;

    int ans = 0;

    for (int i = j; pow(i, b) <= a; i++)
    {
        ans += all_possible_ways(a - pow(i, b), b, i + 1);
    }

    return ans;
}

int all_possible_ways_memo(int a, int b, int j, vector<vector<int>> &memo)
{
    if (a == 0)
        return 1;

    if (memo[a][j] == -1)
    {
        memo[a][j] = 0;
        for (int i = j; pow(i, b) <= a; i++)
        {
            memo[a][j] += all_possible_ways_memo(a - pow(i, b), b, i + 1, memo);
        }
    }

    return memo[a][j];
}

/*------------------- longest increasing subsequence -----------------------*/
// 6
// 5 4 11 1 16 8

int lis(vector<int> a, int i, int prev, int count)
{
    if (i >= a.size())
        return count;

    int ans = INT_MIN;
    if (a[i] > prev)
    {
        int x = lis(a, i + 1, a[i], count + 1);
        int y = lis(a, i + 1, prev, count);
        ans = max(x, y);
    }
    else
    {
        ans = max(ans, lis(a, i + 1, prev, count));
    }

    return ans;
}

// tabulation
int lis_dp(vector<int> a)
{
    int n = a.size();
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    return ans;
}

/*------------------- loot house -----------------------*/
// 6
// 5 5 10 100 10 5

int loot_house_memo(vector<int> houses, int i, int loot, unordered_map<string, int> &memo)
{
    if (i >= houses.size())
        return loot;

    string key = to_string(i) + " " + to_string(loot);

    if (memo.count(key) == 0)
    {
        int x = loot_house_memo(houses, i + 2, loot + houses[i], memo);
        int y = loot_house_memo(houses, i + 1, loot, memo);
        memo[key] = max(x, y);
    }

    return memo[key];
}

int loot_house_dp(vector<int> houses)
{
    int n = houses.size();
    vector<int> dp(n, 0);
    dp[0] = houses[0];

    for (int i = 1; i < n; i++)
    {
        int x = houses[i];
        if (i - 2 >= 0)
            x += dp[i - 2];

        int y = dp[i - 1];

        dp[i] = max(x, y);
    }

    return dp[n - 1];
}

/*------------------- 0 1 knapsack_memo -----------------------*/

// memoization
int knapsack_memo(vector<int> weights, vector<int> values, int capacity, int value, int i, vector<int> &memo)
{
    if (capacity < 0)
        return INT_MIN;

    if (i >= weights.size())
        return value;

    if (memo[capacity] == -1)
    {
        int x = knapsack_memo(weights, values, capacity - weights[i], value, i + 1, memo) + values[i];
        int y = knapsack_memo(weights, values, capacity, value, i + 1, memo);
        memo[capacity] = max(x, y);
    }

    return memo[capacity];
}

// tabulation
int knapsack_dp(vector<int> weights, vector<int> values, int capacity)
{
    int n = weights.size(), W = capacity;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weights[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}

// tabulation space optimized
int knapsack_dp_optimized(vector<int> w, vector<int> v, int W)
{
    int n = w.size();
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
                curr[j] = max(prev[j], v[i - 1] + prev[j - w[i - 1]]);
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }

    return curr[W];
}

/*------------------- edit distance -----------------------*/

int edit_distance_memo(string s, string t, vector<vector<int>> &memo)
{
    int m = s.size(), n = t.size();

    if (m == 0 || n == 0)
    {
        return max(m, n);
    }

    if (memo[m][n] == -1)
    {
        if (s[0] == t[0])
        {
            memo[m][n] = edit_distance_memo(s.substr(1), t.substr(1), memo);
        }
        else
        {
            // delete
            int a = edit_distance_memo(s, t.substr(1), memo) + 1;
            // replace
            int b = edit_distance_memo(s.substr(1), t.substr(1), memo) + 1;
            // insert
            int c = edit_distance_memo(s.substr(1), t, memo) + 1;

            memo[m][n] = min(a, min(b, c));
        }
    }

    return memo[m][n];
}

int edit_distance_dp(string s, string t)
{
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }

    return dp[m][n];
}

/*------------------- longest common subsequence -----------------------*/

// memoization
int LCS_memo(string s, string t, vector<vector<int>> &memo)
{
    int m = s.size(), n = t.size();
    if (m == 0 || n == 0)
        return 0;

    if (memo[m][n] == -1)
    {
        if (s[0] == t[0])
        {
            memo[m][n] = 1 + LCS_memo(s.substr(1), t.substr(1), memo);
        }
        else
        {
            int a = LCS_memo(s, t.substr(1), memo);
            int b = LCS_memo(s.substr(1), t, memo);
            memo[m][n] = max(a, b);
        }
    }

    return memo[m][n];
}

// tabulation
int lcs_dp(string s, string t)
{
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

/*------------------- min cost path -----------------------*/

// memoisation
int min_cost_helper(vector<vector<int>> grid, int i, int j, vector<vector<int>> &memo)
{
    int m = grid.size(), n = grid[0].size();
    if (i >= m || j >= n)
        return INT_MAX;

    if (i == m - 1 && j == n - 1)
        return grid[i][j];

    if (memo[i][j] == -1)
    {
        int right = min_cost_helper(grid, i, j + 1, memo);
        int down = min_cost_helper(grid, i + 1, j, memo);
        int diagonal = min_cost_helper(grid, i + 1, j + 1, memo);

        memo[i][j] = min(right, min(down, diagonal)) + grid[i][j];
    }

    return memo[i][j];
}

int min_cost_path_memo(vector<vector<int>> grid, vector<vector<int>> &memo)
{
    return min_cost_helper(grid, 0, 0, memo);
}

// tabulation
int min_cost_path_dp(vector<vector<int>> grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[m - 1][n - 1] = grid[m - 1][n - 1];

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i - 1 >= 0)
                dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + grid[i - 1][j]);

            if (j - 1 >= 0)
                dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + grid[i][j - 1]);

            if (i - 1 >= 0 && j - 1 >= 0)
                dp[i - 1][j - 1] = min(dp[i - 1][j - 1], dp[i][j] + grid[i - 1][j - 1]);
        }
    }

    return dp[0][0];
}

/*-------- Num of balanced binary trees (h) ---------------*/

// memoisation
int num_of_balanced_memo(int h, vector<int> &memo)
{
    if (h <= 1)
        return 1;

    long long int mod = 1000000007;

    if (memo[h] == -1)
    {
        int x = num_of_balanced_memo(h - 1, memo) % mod;
        int y = num_of_balanced_memo(h - 2, memo) % mod;
        memo[h] = (int)((((long)x * x) % mod + 2 * ((long)x * y) % mod) % mod);
    }

    return memo[h];
}

// tabulation
int num_of_balanced_dp(int h)
{
    vector<int> dp(h + 1, 0);
    dp[0] = 1, dp[1] = 1;
    long long int mod = 1000000007;

    for (int i = 2; i <= h; i++)
    {
        int x = (int)(((long)(dp[i - 1] % mod) * (dp[i - 1] % mod)) % mod);
        int y = (int)(2 * ((long)(dp[i - 1] % mod) * (dp[i - 2] % mod)) % mod);
        dp[i] = (int)(((long)x + y) % mod);
    }

    return dp[h];
}

/*-------- minmum count to represent num as square sum ---------------*/

// memoised
int min_count_memo(int n, vector<int> &memo)
{
    if (n <= 1)
        return n;

    if (memo[n] == -1)
    {
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, min_count_memo(n - i * i, memo) + 1);
        }

        memo[n] = ans;
    }

    return memo[n];
}

// tabulation
int min_count_dp(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0, dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int x = 1; x * x <= i; x++)
            dp[i] = min(dp[i], 1 + dp[i - x * x]);
    }

    return dp[n];
}

/*-------- staircase (jump 1 or 2 or 3) ---------------*/

// memoised
int ways_to_step_memo(int n, vector<int> &memo)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    if (memo[n] == -1)
    {
        int x = ways_to_step_memo(n - 1, memo);
        int y = ways_to_step_memo(n - 2, memo);
        int z = ways_to_step_memo(n - 3, memo);

        memo[n] = x + y + z;
    }

    return memo[n];
}

// tabulation
int ways_to_step(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        if (i + 1 <= n)
            dp[i + 1] += dp[i];

        if (i + 2 <= n)
            dp[i + 2] += dp[i];

        if (dp[i + 3] <= n)
            dp[i + 3] += dp[i];
    }

    return dp[n];
}

/*-------- min steps to 1 (from n) ---------------*/

// memoised soln
int min_steps_recursive(int n, vector<int> &memo)
{
    if (n == 1)
        return 0;

    if (memo[n] == -1)
    {
        int x = min_steps_recursive(n - 1, memo);
        int y = INT_MAX, z = INT_MAX;

        if (n % 2 == 0)
            y = min_steps_recursive(n / 2, memo);

        if (n % 3 == 0)
            z = min_steps_recursive(n / 3, memo);

        memo[n] = min(x, min(y, z)) + 1;
    }

    return memo[n];
}

// tabulation
int min_steps_dp(int n)
{
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0, dp[1] = 0;

    for (int i = 1; i < n; i++)
    {
        if (i + 1 <= n)
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);

        if (i * 2 <= n)
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);

        if (i * 3 <= n)
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }

    return dp[n];
}
/*-----------------------------------------------------*/

int main()
{
    /*-------- min steps to 1 (from n) ---------------*/
    // int n;
    // cin >> n;
    // vector<int> memo(n + 1, -1);
    // cout << min_steps_recursive(n, memo) << endl;
    // cout << min_steps_dp(n) << endl;

    /*-------- staircase (jump 1 or 2 or 3) ---------------*/
    // int n;
    // cin >> n;
    // vector<int> memo(n + 1, -1);
    // cout << ways_to_step(n) << endl;
    // cout << ways_to_step_memo(n, memo) << endl;

    /*-------- minmum count to represent num as square sum ---------------*/
    // int n;
    // cin >> n;
    // vector<int> memo(n + 1, -1);
    // cout << min_count_memo(n, memo) << endl;
    // cout << min_count_dp(n) << endl;

    /*-------- Num of balanced binary trees (h) ---------------*/
    // int n;
    // cin >> n;
    // vector<int> memo(n + 1, -1);
    // cout << num_of_balanced_memo(n, memo) << endl;
    // cout << num_of_balanced_dp(n) << endl;

    /*------------------- min cost path -----------------------*/
    // int m, n;
    // cin >> m >> n;
    // vector<vector<int>> a;
    // vector<vector<int>> memo(m, vector<int>(n, -1));

    // for (int i = 0; i < m; i++)
    // {
    //     vector<int> b(n);
    //     for (int j = 0; j < n; j++)
    //         cin >> b[j];

    //     a.push_back(b);
    // }

    // cout << min_cost_path_memo(a, memo) << endl;
    // cout << min_cost_path_dp(a) << endl;

    /*------------------- longest common subsequence -----------------------*/
    // string s, t;
    // cin >> s >> t;
    // int m = s.size(), n = t.size();
    // vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    // cout << LCS_memo(s, t, memo) << endl;
    // cout << lcs_dp(s, t) << endl;

    /*------------------- edit distance -----------------------*/
    // string s, t;
    // cin >> s >> t;
    // int m = s.size(), n = t.size();
    // vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    // cout << edit_distance_memo(s, t, memo) << endl;
    // cout << edit_distance_dp(s, t) << endl;

    /*------------------- 0 1 knapsack_memo -----------------------*/
    // int n;
    // cin >> n;
    // vector<int> a(n), b(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    // for (int i = 0; i < n; i++)
    //     cin >> b[i];

    // int c;
    // cin >> c;
    // vector<int> memo(c + 1, -1);
    // cout << knapsack_memo(a, b, c, 0, 0, memo) << endl;
    // cout << knapsack_dp(a, b, c) << endl;
    // cout << knapsack_dp_optimized(a, b, c) << endl;

    /*------------------- loot house -----------------------*/
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // unordered_map<string, int> memo;
    // cout << loot_house_memo(a, 0, 0, memo) << endl;
    // cout << loot_house_dp(a) << endl;

    /*------------------- longest increasing subsequence -----------------------*/
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    // cout << lis(a, 0, INT_MIN, 0) << endl;
    // cout << lis_dp(a) << endl;

    /*------------------- num of ways to represent as y = a^x + b^x + ... -----------------------*/
    // int a, b;
    // cin >> a >> b;
    // int i = (int)(pow(a, 1.0 / b) + 1e-9);
    // vector<vector<int>> memo(a + 1, vector<int>(i + 1, -1));

    // cout << all_possible_ways(a, b, 1) << endl;
    // cout << all_possible_ways_memo(a, b, 1, memo) << endl;

    /*------------------- infinite coin change -----------------------*/
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    // int v;
    // cin >> v;
    // vector<vector<int>> memo(v + 1, vector<int>(n, -1));
    // cout << coin_change_memo(a, v, 0, memo) << endl;
    // cout << coin_change_dp(a, v) << endl;

    /*------------------- matrix chain multiplication -----------------------*/
    // int n;
    // cin >> n;
    // vector<int> a(n + 1);
    // for (int i = 0; i <= n; i++)
    //     cin >> a[i];

    // vector<vector<int>> memo(n + 1, vector<int>(n + 1, INT_MAX));
    // cout << mcm(a, 0, n, memo) << endl;
    // cout << mcm_dp(a) << endl;

    /*------------------- Coin tower -----------------------*/
    // int n, x, y;
    // cin >> n >> x >> y;
    // cout << coint_tower(n, x, y) << endl;
    // cout << coin_tower_dp(n, x, y) << endl;

    /*------------------- max square submatrix -----------------------*/
    // int m, n;
    // cin >> m >> n;
    // vector<vector<int>> a;

    // for (int i = 0; i < m; i++)
    // {
    //     vector<int> b(n);
    //     for (int j = 0; j < n; j++)
    //         cin >> b[j];

    //     a.push_back(b);
    // }

    // cout << max_square(a) << endl;

    /*------------------- smallest uncommon subsequence -----------------------*/

    string s, t;
    cin >> s >> t;
    vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
    cout << sus_memo(s, t, memo) << endl;
    cout << sus_dp(s, t) << endl;

    return 0;
}