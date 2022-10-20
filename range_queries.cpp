#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1000000007

vector<int> productQueries(int n, vector<vector<int>> &queries)
{
    vector<int> powers;

    for (int i = 0; i < 32; i++)
    {
        int bit = 1 << i;
        if (n & bit)
            powers.push_back(1 << i);
    }

    int size = powers.size();
    int p = 1;
    vector<int> left(size);
    vector<int> right(size);

    left[0] = 1;
    for (int i = 1; i < size; i++)
    {
        p = ((ll)p * powers[i - 1]) % MOD;
        left[i] = p;
    }

    p = 1;
    right[size - 1] = 1;
    for (int i = size - 2; i >= 0; i--)
    {
        p = ((ll)p * powers[i + 1]) % MOD;
        right[i] = p;
    }

    p = ((ll)p * powers[0]) % MOD;

    vector<int> a;
    for (auto q : queries)
    {
        ll ans = p / ((ll)left[q[0]] * right[q[1]]);
        a.push_back(ans);
    }

    return a;
}

int main()
{
    int n = 189767678;
    vector<vector<int>> v =
        {{5, 5},
         {4, 4},
         {0, 1},
         {1, 5},
         {4, 6},
         {6, 6},
         {5, 6},
         {0, 3},
         {5, 5},
         {5, 6},
         {1, 2},
         {3, 5},
         {3, 6},
         {5, 5},
         {4, 4},
         {1, 1},
         {2, 4},
         {4, 5},
         {4, 4},
         {5, 6},
         {0, 4},
         {3, 3},
         {0, 4},
         {0, 5},
         {4, 4},
         {5, 5},
         {4, 6},
         {4, 5},
         {0, 4},
         {6, 6},
         {6, 6},
         {6, 6},
         {2, 2},
         {0, 5},
         {1, 4},
         {0, 3},
         {2, 4},
         {5, 5},
         {6, 6},
         {2, 2},
         {2, 3},
         {5, 5},
         {0, 6},
         {3, 3},
         {6, 6},
         {4, 4},
         {0, 0},
         {0, 2},
         {6, 6},
         {6, 6},
         {3, 6},
         {0, 4},
         {6, 6},
         {2, 2},
         {4, 6}};

    vector<int>
        ans = productQueries(n, v);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}