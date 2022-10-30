#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> a, int target)
{
    int m = a.size(), n = a[0].size();

    int row_start = 0, row_end = m - 1;

    while (row_start <= row_end)
    {
        int row_mid = (row_end - row_start) / 2 + row_start;

        if (a[row_mid][0] == target)
            return true;
        else if (a[row_mid][0] < target)
        {
            int col_start = 0, col_end = n - 1;

            while (col_start <= col_end)
            {
                int col_mid = (col_end - col_start) / 2 + col_start;

                if (a[row_mid][col_mid] == target)
                    return true;
                else if (a[row_mid][col_mid] < target)
                    col_start = col_mid + 1;
                else
                    col_end = col_mid - 1;
            }

            row_start = row_mid + 1;
        }
        else
        {
            row_end = row_mid - 1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> a = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    cout << search(a, 61) << endl;

    return 0;
}