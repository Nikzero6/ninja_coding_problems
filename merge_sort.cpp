#include <iostream>
using namespace std;

void merge(int a[], int s, int mid, int e)
{
    int aux[e - s + 1];

    int i = s, j = mid + 1, k = 0;

    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
            aux[k++] = a[i++];
        else
            aux[k++] = a[j++];
    }

    while (i <= mid)
    {
        aux[k++] = a[i++];
    }

    while (j <= e)
    {
        aux[k++] = a[j++];
    }

    for (int l = 0; l <= e - s; l++)
    {
        a[l + s] = aux[l];
    }
}

void merge_sort(int a[], int s, int e)
{
    if (s >= e)
        return;

    int mid = (e - s) / 2 + s;
    merge_sort(a, s, mid);
    merge_sort(a, mid + 1, e);
    merge(a, s, mid, e);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    return 0;
}