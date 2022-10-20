#include <iostream>
#include <vector>
using namespace std;

int minimizeArrayValue(vector<int> &nums)
{
    int n = nums.size();

    bool flag = true;
    int ans = INT_MAX;

    while (flag)
    {
        flag = false;
        int maxNum = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i] && nums[i] - nums[i - 1] != 1)
            {
                long long sum = nums[i - 1] + nums[i];
                nums[i - 1] = sum / 2, nums[i] = sum / 2 + sum % 2;
                flag = true;
            }
            maxNum = max(nums[i], maxNum);
        }
        if (flag)
            ans = min(ans, maxNum);
    }

    return ans;
}

int main()
{
    vector<int> nums = {15, 15, 16, 6, 6, 7, 7};

    cout << minimizeArrayValue(nums);
    return 0;
}