#include <iostream>
using namespace std;
#include <string>

int string2int(string s, int i, int ans)
{
    if (i > s.size() - 1)
        return ans;

    ans = ans * 10 + (s[i] - 48);

    return string2int(s, i + 1, ans);
}
int main()
{
    string s;
    cin >> s;

    cout << string2int(s, 0, 0) << endl;
    return 0;
}