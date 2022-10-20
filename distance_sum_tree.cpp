#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// 5
// [[0,1],[0,2][2,3],[2,4]]

//          0
//        /   \
//       1     2
//           /   \
//          3    4

vector<int> node_count, sum;
vector<unordered_set<int>> tree;

void preorder(int root, int prev)
{
    for (auto child : tree[root])
    {
        if (child == prev)
            continue;

        sum[child] = sum[root] + node_count.size() - 2 * node_count[child];
        preorder(child, root);
    }
}

pair<int, int> postorder(int root, int prev)
{
    for (auto child : tree[root])
    {
        if (child == prev)
            continue;

        pair<int, int> smallAns = postorder(child, root);
        sum[root] += (smallAns.first + smallAns.second);
        node_count[root] += (smallAns.first);
    }
    node_count[root]++;

    return {node_count[root], sum[root]};
}

vector<int> distance_sum(int n, vector<vector<int>> edges)
{
    node_count.resize(n);
    sum.resize(n);
    tree.resize(n);

    for (auto edge : edges)
    {
        tree[edge[0]].insert(edge[1]);
        tree[edge[1]].insert(edge[0]);
    }

    postorder(0, -1);
    preorder(0, -1);

    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges;

    for (int i = 0; i < n - 1; i++)
    {
        vector<int> b(2);
        for (int j = 0; j < 2; j++)
            cin >> b[j];

        edges.push_back(b);
    }

    vector<int> ans = distance_sum(n, edges);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}