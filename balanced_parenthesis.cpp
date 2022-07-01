#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanced(string s)
{
    stack<char> st;

    for (auto c : s)
    {
        if (!st.empty() && c == ')' && st.top() == '(')
            st.pop();
        else
            st.push(c);
    }

    return st.empty();
}

int main()
{
    string s;
    cin >> s;

    cout << balanced(s) << endl;

    return 0;
}