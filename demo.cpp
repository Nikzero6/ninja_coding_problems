#include <iostream>
using namespace std;

int DivisibilityByEleven(int num)
{
    string number = to_string(num);
    int n = number.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        string s = "";

        for (int j = i; j < n; j++)
        {
            s += number[j];
            if (stoi(s) % 11 == 0)
                count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << DivisibilityByEleven(n);

    return 0;
}