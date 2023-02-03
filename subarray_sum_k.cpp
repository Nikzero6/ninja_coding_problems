#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int> &a, int k)
{
    int i = 0, j = 0, n = a.size();
    int sum = 0, count = 0;

    while (i < n)
    {
        j = i;
        sum = 0;
        while (j < n)
        {
            sum += a[j];

            if (sum == k)
                count++;

            j++;
        }
        i++;
    }

    return count;
}

int main()
{
    vector<int> a = {1, -1, 0};
    cout << subarraySum(a, 0);
    return 0;
}