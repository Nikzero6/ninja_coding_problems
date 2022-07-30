#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m, n;

bool isInside(int i, int j)
{
    return i < m && j < n && i >= 0 && j >= 0;
}

bool dfs(vector<string> &board, string word, int i, int j)
{
    if (word.size() == 0)
        return true;

    if (!isInside(i, j))
        return false;

    if (board[i][j] != '\0')
    {
        char c = board[i][j];
        board[i][j] = '\0';

        if (c == word[0])
        {
            return dfs(board, word.substr(1), i + 1, j) ||
                   dfs(board, word.substr(1), i - 1, j) ||
                   dfs(board, word.substr(1), i, j + 1) ||
                   dfs(board, word.substr(1), i, j - 1);
        }
    }

    return false;
}

bool exist(vector<string> &board, string word)
{
    m = board.size(), n = board[0].size();

    int ans = false;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != '\0')
                ans = ans || dfs(board, word, i, j);

            if (ans)
                return true;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string word;
    cin >> word;

    cout << exist(a, word) << endl;

    return 0;
}