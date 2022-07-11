#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
        return 0;

    grid[i][j] = '0';
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i, j + 1, m, n);
    dfs(grid, i, j - 1, m, n);

    return 1;
}

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            count += dfs(grid, i, j, m, n);
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << numIslands(grid) << endl;
    return 0;
}