#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> takeInput()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> a(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        a[f][s] = 1;
        a[s][f] = 1;
    }

    return a;
}

void dfs_helper(vector<vector<int>> a, int source, vector<bool> &visited)
{
    int n = a.size();
    cout << source << " ";
    visited[source] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == source || visited[i])
            continue;
        if (a[source][i] == 1)
            dfs_helper(a, i, visited);
    }
}

void dfs(vector<vector<int>> a, int source)
{
    int n = a.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs_helper(a, i, visited);
    }
}

void bfs_helper(vector<vector<int>> a, vector<bool> &visited, int source)
{
    int n = a.size();

    queue<int> pendingNodes;
    pendingNodes.push(source);
    visited[source] = true;

    while (!pendingNodes.empty())
    {
        int source = pendingNodes.front();
        pendingNodes.pop();
        cout << source << " ";

        for (int i = 0; i < n; i++)
        {
            if (i == source || visited[i])
                continue;

            if (a[source][i] == 1)
            {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(vector<vector<int>> a)
{
    cout << endl;
    int n = a.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            bfs_helper(a, visited, i);
    }
    cout << endl;
}

bool hasPath(vector<vector<int>> a, int v1, int v2)
{
    int n = a.size();
    vector<bool> visited(n, false);

    queue<int> pendingNodes;
    pendingNodes.push(v1);
    visited[v1] = true;

    while (!pendingNodes.empty())
    {
        int node = pendingNodes.front();
        pendingNodes.pop();

        if (node == v2)
            return true;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (i == node || visited[i])
                    continue;

                if (a[node][i] == 1)
                {
                    pendingNodes.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    return false;
}

bool hasPath_recursive(vector<vector<int>> a, int v1, int v2, vector<bool> &visited)
{
    if (v1 == v2)
        return true;

    visited[v1] = true;

    bool ans = false;

    for (int i = 0; i < a.size(); i++)
    {
        if (!visited[i] && a[v1][i] == 1)
            ans = ans || hasPath_recursive(a, i, v2, visited);
    }

    return ans;
}

pair<bool, vector<int>> get_path_dfs(vector<vector<int>> a, int v1, int v2, vector<bool> &visited, vector<int> path = {})
{
    path.push_back(v1);
    visited[v1] = true;

    if (v1 == v2)
        return {true, path};

    pair<bool, vector<int>> ans(false, {});

    for (int i = 0; i < a.size(); i++)
    {
        if (a[v1][i] == 1 && !visited[i])
        {
            pair<bool, vector<int>> x = get_path_dfs(a, i, v2, visited, path);
            if (x.first)
                return x;
        }
    }

    return ans;
}

vector<int> get_path_bfs(vector<vector<int>> a, int v1, int v2)
{
    int n = a.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    queue<int> pendingNodes;
    pendingNodes.push(v1);
    visited[v1] = true;
    parent[v1] = v1;

    while (!pendingNodes.empty())
    {
        int node = pendingNodes.front();
        pendingNodes.pop();

        if (node == v2)
            break;

        for (int i = 0; i < n; i++)
        {

            if (!visited[i] && a[node][i] == 1)
            {
                visited[i] = true;
                parent[i] = node;
                pendingNodes.push(i);
            }
        }
    }

    vector<int> ans;

    if (parent[v2] == -1)
        return ans;

    int i = v2;
    ans.push_back(v2);
    while (parent[i] != i)
    {
        ans.push_back(parent[i]);
        i = parent[i];
    }

    return ans;
}

void dfs_2(vector<vector<int>> a, int source, vector<bool> &visited)
{
    visited[source] = true;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[source][i] == 1 && !visited[i])
            dfs_2(a, i, visited);
    }
}

bool isConnected(vector<vector<int>> a)
{
    int n = a.size();
    vector<bool> visited(n, false);

    dfs_2(a, 0, visited);

    for (auto it : visited)
    {
        if (!it)
            return false;
    }

    return true;
}

void dfs_3(vector<vector<int>> a, int sv, vector<bool> &visited, vector<int> &component)
{
    visited[sv] = true;
    component.push_back(sv);

    for (int i = 0; i < a.size(); i++)
    {
        if (a[sv][i] == 1 && !visited[i])
            dfs_3(a, i, visited, component);
    }
}

vector<vector<int>> allConnectedComponents(vector<vector<int>> a)
{
    int n = a.size();
    vector<bool> visited(n, false);
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs_3(a, i, visited, component);
            ans.push_back(component);
        }
    }

    return ans;
}

void dfs_4(vector<vector<int>> a, vector<bool> &visited, int sv)
{
    visited[sv] = true;

    for (int i = 0; i < a.size(); i++)
    {
        if (!visited[i] && a[sv][i])
            dfs_4(a, visited, i);
    }
}

int connectedIslands(vector<vector<int>> a)
{
    int n = a.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs_4(a, visited, i);
        }
    }

    return count;
}

bool codingNinja_helper(vector<string> &a, string target, int i, int j)
{
    if (target.size() == 0)
        return true;

    int n = a.size(), m = a[0].size();

    if (i >= n || j >= m || i < 0 || j < 0)
        return false;

    if (a[i][j] != '\0' && a[i][j] == target[0])
    {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        a[i][j] = '\0';

        for (int k = 0; k < 8; k++)
        {
            bool ans = codingNinja_helper(a, target.substr(1), i + dir[k].first, j + dir[k].second);
            if (ans)
                return true;
        }
    }
    return false;
}

bool codingNinja(vector<string> a, string target)
{
    int n = a.size(), m = a[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vector<string> b = a;
            bool ans = codingNinja_helper(b, target, i, j);
            if (ans)
                return true;
        }
    }

    return false;
}

bool dots_dfs(vector<string> &a, int i, int j, int count, char prev, vector<vector<int>> &d)
{
    int m = a.size(), n = a[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n)
        return false;

    if (a[i][j] == prev && d[i][j] != 0 && d[i][j] - count >= 4)
        return true;

    if (a[i][j] == prev && d[i][j] == 0)
    {
        d[i][j] = count + 1;

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int k = 0; k < 4; k++)
        {
            bool ans = dots_dfs(a, i + dir[k].first, j + dir[k].second, count + 1, prev, d);
            if (ans)
                return true;
        }
    }

    return false;
}

bool connectingDots(vector<string> a)
{
    int m = a.size(), n = a[0].size();
    vector<vector<int>> d(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == 0)
            {
                bool ans = dots_dfs(a, i, j, 0, a[i][j], d);

                if (ans)
                    return true;
            }
        }
    }

    return false;
}

int maxOnesHelper(vector<vector<int>> &a, int i, int j)
{
    int m = a.size(), n = a[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n)
        return 0;

    if (a[i][j] == 0)
        return 0;

    int ans = 1;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    a[i][j] = 0;

    for (int k = 0; k < 4; k++)
    {
        ans += maxOnesHelper(a, i + dir[k].first, j + dir[k].second);
    }

    return ans;
}

int maxOnes(vector<vector<int>> a)
{
    int m = a.size(), n = a[0].size();

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
            {
                ans = max(ans, maxOnesHelper(a, i, j));
            }
        }
    }

    return ans;
}

int numOfTriangles(vector<vector<int>> a, bool directed = false)
{
    int n = a.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (a[i][j] && a[j][k] && a[k][i])
                    count++;
            }
        }
    }

    if (directed)
        return count / 3;
    else
        return count / 6;
}

class Edge
{
public:
    int v1;
    int v2;
    int w;
    Edge(int v1, int v2, int w)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->w = w;
    }
};

bool compare(Edge e1, Edge e2)
{
    return e1.w < e2.w;
}

int findParent(int v, vector<int> parents)
{
    while (parents[v] != v)
    {
        v = parents[v];
    }

    return v;
}

vector<Edge> kruksal()
{
    vector<Edge> edgeList;

    int V, E;
    cin >> V >> E;

    while (E)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edgeList.push_back(Edge(x, y, z));
        E--;
    }

    sort(edgeList.begin(), edgeList.end(), compare);

    vector<int> parents(V);
    for (int i = 0; i < V; i++)
    {
        parents[i] = i;
    }

    vector<Edge> MST;

    for (auto edge : edgeList)
    {
        if (MST.size() == V - 1)
            break;

        if (findParent(edge.v1, parents) == findParent(edge.v2, parents))
            continue;

        MST.push_back(Edge(edge.v1, edge.v2, edge.w));
        parents[edge.v1] = edge.v2;
    }

    return MST;
}

vector<Edge> prims()
{
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> a(n);

    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        a[f].push_back({s, w});
        a[s].push_back({f, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    vector<bool> included(n, false);
    vector<int> parent(n, -1);

    pq.push({0, 0});
    dist[0] = 0;

    int count = 0;

    while (count < n)
    {
        pair<int, int> minVertex = pq.top();
        pq.pop();
        included[minVertex.second] = true;

        for (auto it : a[minVertex.second])
        {
            int v = it.first;
            int weight = it.second;

            if (!included[v] && dist[v] > minVertex.first + weight)
            {
                dist[v] = minVertex.first + weight;
                pq.push({dist[v], v});
                parent[v] = minVertex.second;
            }
        }

        count++;
    }

    vector<Edge> MST;
    for (int i = 1; i < n; i++)
    {
        if (i != parent[i])
        {
            int weight = 0;
            for (auto it : a[parent[i]])
                if (it.first == i)
                    weight = it.second;

            MST.push_back({parent[i], i, weight});
        }
    }

    return MST;
}

vector<int> dijkstra()
{
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;

        adj[f].push_back({s, w});
        adj[s].push_back({f, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pair<int, int> min = pq.top();
        pq.pop();

        for (auto v : adj[min.second])
        {
            if (dist[v.first] > min.first + v.second)
            {
                dist[v.first] = min.first + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    return dist;
}

int main()
{
    // vector<vector<int>> a = takeInput();

    // dfs(a, 0);
    // bfs(a);

    // int v1, v2;
    // cin >> v1 >> v2;
    // cout << hasPath(a, v1, v2) << endl;
    // vector<bool> visited(a.size(), false);
    // cout << hasPath_recursive(a, v1, v2, visited) << endl;

    // vector<int> ans = get_path_dfs(a, v1, v2, visited).second;

    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // vector<int> vec = get_path_bfs(a, v1, v2);

    // for (auto it : vec)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // cout << isConnected(a) << endl;

    // vector<vector<int>> ans = allConnectedComponents(a);
    // for (auto it : ans)
    // {
    //     for (auto vec : it)
    //     {
    //         cout << vec << " ";
    //     }
    //     cout << endl;
    // }

    // cout << connectedIslands(a) << endl;

    // int m, n;
    // cin >> m >> n;
    // vector<string> a(m);

    // for (int i = 0; i < m; i++)
    // {
    //     cin >> a[i];
    // }

    // // cout << codingNinja(a, "CODINGNINJA") << endl;
    // cout << connectingDots(a) << endl;

    // int m;
    // cin >> m;
    // vector<vector<int>> a;

    // for (int i = 0; i < m; i++)
    // {
    //     vector<int> b(m);
    //     for (int j = 0; j < m; j++)
    //         cin >> b[j];

    //     a.push_back(b);
    // }

    // cout << maxOnes(a) << endl;

    // cout << numOfTriangles(a) << endl;

    // vector<Edge> Mst = kruksal();
    // cout << endl;
    // for (auto edge : Mst)
    // {
    //     cout << edge.v1 << " " << edge.v2 << " " << edge.w << endl;
    // }
    // cout << endl;

    // vector<Edge> Mst = prims();
    // cout << endl;
    // for (auto edge : Mst)
    // {
    //     cout << edge.v1 << " " << edge.v2 << " " << edge.w << endl;
    // }
    // cout << endl;

    vector<int> dist = dijkstra();
    cout << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    cout << endl;

    return 0;
}