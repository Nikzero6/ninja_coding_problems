#include <iostream>
using namespace std;

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int partition(int a[], int s, int e)
{
    int i = s, j = e - 1;
    int pivot = a[e];

    while (i <= j)
    {
        while (a[i] <= pivot && i <= j)
            i++;
        while (a[j] > pivot && j >= 0)
            j--;

        if (i < j)
            swap(a, i, j);
    }

    swap(a, i, e);
    return i;
}
void quick_sort(int a[], int s, int e)
{
    if (s >= e)
        return;

    int pivot = partition(a, s, e);
    quick_sort(a, s, pivot - 1);
    quick_sort(a, pivot + 1, e);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
    return 0;
}