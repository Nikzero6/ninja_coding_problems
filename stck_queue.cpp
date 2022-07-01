#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverse_stack(stack<int> &s1, stack<int> &s2)
{
    while (!s1.empty())
    {
        int popped = s1.top();
        s1.pop();
        s2.push(popped);
    }

    stack<int> temp = s1;
    s1 = s2;
    s2 = temp;
}

void reverse_stack_recursive(stack<int> &s1, stack<int> &s2)
{
    if (s1.size() == 0 || s1.size() == 1)
        return;

    int x = s1.top();
    s1.pop();

    reverse_stack_recursive(s1, s2);
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

void reverse_queue(queue<int> &q)
{
    if (q.size() == 0 || q.size() == 1)
        return;

    int x = q.front();
    q.pop();

    reverse_queue(q);
    q.push(x);
}

bool redundant_brackets(string A)
{
    stack<char> st;

    for (auto c : A)
    {
        if (c == ')')
        {
            if (st.empty() || st.top() == '(')
                return true;

            int x = 0;

            while (st.top() != '(')
            {
                if (x % 2 == 0 && !(st.top() >= 97 && st.top() <= 122))
                    return true;

                if (x % 2 == 1 && st.top() != '+' && st.top() != '-' && st.top() != '*' && st.top() != '/')
                    return true;

                st.pop();
                x++;
            }

            if (x < 3)
                return true;

            st.pop();
            st.push('x');
        }
        else
            st.push(c);
    }

    return false;
}

class StockSpanner
{
    stack<pair<int, int>> s;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int ans = 1;
        while (!s.empty() && price >= s.top().first)
        {
            ans += s.top().second;
            s.pop();
        }

        s.push({price, ans});
        return ans;
    }
};

int countRev(string s)
{
    stack<char> st;

    for (auto c : s)
    {
        if (st.top() == '{' && c == '}')
            st.pop();
        else
            st.push(c);
    }

    if (st.empty())
        return 0;

    if (st.size() % 2 == 1)
        return -1;

    int count = 0;

    while (!st.empty())
    {
        int x = st.top();
        st.pop();

        if (x == st.top())
            count++;
        else
            count += 2;

        st.pop();
    }

    return count;
}

int main()
{
    // stack<int> s1, s2;

    // s1.push(10);
    // cout << s1.top() << endl;
    // s1.push(20);
    // cout << s1.top() << endl;
    // s1.push(30);
    // cout << s1.top() << endl;
    // s1.push(40);
    // cout << s1.top() << endl;
    // s1.push(50);
    // cout << s1.top() << endl;
    // cout << endl;

    // // reverse_stack(s1, s2);
    // reverse_stack_recursive(s1, s2);

    // cout << s1.top() << endl;
    // s1.pop();
    // cout << s1.top() << endl;
    // s1.pop();
    // cout << s1.top() << endl;
    // s1.pop();
    // cout << s1.top() << endl;
    // s1.pop();
    // cout << s1.top() << endl;
    // s1.pop();

    // queue<int> q;

    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);

    // reverse_queue(q);

    // cout << endl
    //      << q.front() << endl;
    // q.pop();
    // cout << q.front() << endl;
    // q.pop();
    // cout << q.front() << endl;
    // q.pop();
    // cout << q.front() << endl;
    // q.pop();
    // cout << q.front() << endl;

    // string input;
    // cin >> input;

    // cout << redundant_brackets(input) << endl;

    // stock span
    // StockSpanner stockSpanner;
    // cout << stockSpanner.next(28) << endl;
    // cout << stockSpanner.next(14) << endl;
    // cout << stockSpanner.next(28) << endl;
    // cout << stockSpanner.next(35) << endl;
    // cout << stockSpanner.next(46) << endl;
    // cout << stockSpanner.next(53) << endl;
    // cout << stockSpanner.next(66) << endl;
    // cout << stockSpanner.next(80) << endl;
    // cout << stockSpanner.next(87) << endl;
    // cout << stockSpanner.next(88) << endl;

    // min bracket reversal
    string s;
    cin >> s;

    cout << countRev(s) << endl;

    return 0;
}