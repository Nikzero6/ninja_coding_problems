#include <iostream>
using namespace std;
void tower_of_hanoi(int n, char src, char dest, char aux)
{
    if (n == 0)
        return;

    if (n == 1)
    {
        cout << src << " " << dest << endl;
        return;
    }

    if (n == 2)
    {
        cout << src << " " << aux << endl;
        cout << src << " " << dest << endl;
        cout << aux << " " << dest << endl;
        return;
    }

    tower_of_hanoi(2, src, aux, dest);
    tower_of_hanoi(n - 2, src, dest, aux);
    tower_of_hanoi(2, aux, dest, src);

    return;
}
int main()
{
    int n;
    cin >> n;

    tower_of_hanoi(n, 'a', 'c', 'b');

    return 0;
}