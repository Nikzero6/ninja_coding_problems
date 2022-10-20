#include <iostream>
#include <vector>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m)
        return kthElement(arr2, arr1, m, n, k);

    int l = max(0, k - m), h = min(k, n);

    while (l <= h)
    {
        int cut1 = (h - l) / 2 + l;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            h = cut1 - 1;
        else
            l = cut1 + 1;
    }

    return -1;
}

int main()
{
    int arr1[] = {1, 10, 10, 25, 40, 54, 79}, arr2[] = {15, 24, 27, 32, 33, 39, 48, 68, 82, 88, 90}, k = 15;

    cout << kthElement(arr1, arr2, 7, 11, k);

    return 0;
}