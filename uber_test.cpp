#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/* ---------------------------- farmer land ----------------------------------- */

/*
5
9
3
1 0 3
3
1 2 5
4
2 0 4 3
3
1 1 4
3
1 2 7
4
2 1 3 6
3
1 3 6
3
1 4 5
4
2 0 5 6
*/

vector<int> damaged_plants(vector<vector<int>> queries, int n)
{
    vector<int> patches(n, -1);
    vector<int> ans;

    for (auto q : queries)
    {
        if (q[0] == 1)
        {
            patches[q[1]] = q[2];
        }
        else
        {
            int l = q[1], r = q[2], w = q[3];
            int count = 0;
            for (int i = l; i < r; i++)
            {
                if (patches[i] == -1)
                    continue;

                if (patches[i] <= w)
                {
                    count++;
                    patches[i] = -1;
                }
            }
            ans.push_back(count);
        }
    }

    return ans;
}

/* ---------------------------- min cost to build road ----------------------------------- */

int minCost(vector<vector<int>> vertices)
{
    int n = vertices.size();

    vector<int> distances(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances[0] = 0;
    pq.push({0, 0});

    for (int i = 0; i < n - 1; i++)
    {
        // get min vertex
        int minIdx = pq.top().second;
        visited[minIdx] = true;
        pq.pop();

        // explore all other un-visited vertices
        for (int j = i + 1; j < n; j++)
        {
            if (visited[j])
                continue;

            // find distance
            int dist = min(abs(vertices[j][0] - vertices[minIdx][0]), min(abs(vertices[j][1] - vertices[minIdx][1]), abs(vertices[j][2] - vertices[minIdx][2])));

            // if smaller update distance
            if (dist < distances[j])
            {
                distances[j] = dist;
                pq.push({dist, j});
            }
        }
    }

    // calculate final sum
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += distances[i];

    return sum;
}

/* ---------------------------- substring of 10^250 a copies ----------------------------------- */

int minMax(vector<int> a, int target)
{
    int i = 0, j = a.size() - 1;
    int ans = INT_MAX;
    while (i <= j)
    {
        int mid = (j - i) / 2 + i;

        if (a[mid] > target)
        {
            j = mid - 1;
            ans = min(ans, a[mid]);
        }
        else
        {
            i = mid + 1;
        }
    }

    return ans;
}

long long solution(string a, string b)
{
    int n = a.length();
    unordered_map<char, vector<int>> hash;
    long long prev = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        hash[a[i]].push_back(i + 1);
    }

    for (int i = 0; i < b.length(); i++)
    {
        if (hash.count(b[i]) == 0)
            return -1;

        int index = minMax(hash[b[i]], prev);

        if (index == INT_MAX)
        {
            ans += (n - prev + hash[b[i]][0]);
            prev = hash[b[i]][0];
        }
        else
        {
            ans += index - prev;
            prev = index;
        }
    }

    return ans;
}

int main()
{
    // string a, b;
    // cin >> a >> b;
    // cout << solution(a, b) << endl;

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
    // cout << minCost(a) << endl;

    int n;
    cin >> n;

    int k;
    cin >> k;
    vector<vector<int>> a;

    for (int i = 0; i < k; i++)
    {
        int l;
        cin >> l;
        vector<int> b(l);
        for (int j = 0; j < l; j++)
            cin >> b[j];

        a.push_back(b);
    }

    vector<int> ans = damaged_plants(a, n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}