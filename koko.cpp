#include <iostream>
#include <vector>
using namespace std;

bool valid(vector<int> &piles, int h, int k)
{
    int count = 0;

    for (const int &num : piles)
    {
        count += (num / k + !!(num % k));
    }

    return count <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{

    int maxNum = INT_MIN;

    for (const int &num : piles)
    {
        maxNum = max(num, maxNum);
    }

    int low = 1, high = maxNum, ans = -1;

    while (low <= high)
    {
        int mid = (high - low) / 2 + low;

        if (valid(piles, h, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> piles = {30, 11, 23, 4, 20};

    cout << minEatingSpeed(piles, 5);

    return 0;
}