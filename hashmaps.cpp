#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxFrequent(vector<int> a)
{
    pair<int, int> maxNum(-1, 0);
    unordered_map<int, int> hash;

    for (auto num : a)
    {
        if (hash.count(num) > 0)
        {
            hash[num]++;
        }
        else
        {
            hash[num] = 1;
        }

        if (hash[num] > maxNum.second)
            maxNum = {num, hash[num]};
    }

    return maxNum.first;
}

vector<int> intersection(vector<int> a, vector<int> b)
{
    unordered_map<int, int> hash;
    vector<int> ans;

    for (auto num : a)
    {
        if (hash.count(num) > 0)
            hash[num]++;
        else
            hash[num] = 1;
    }

    for (auto num : b)
    {
        if (hash.count(num) > 0 && hash[num] > 0)
        {
            hash[num]--;
            ans.push_back(num);
        }
    }
    return ans;
}

int pairSum(vector<int> a)
{
    int ans = 0;
    unordered_map<int, int> hash;

    for (auto num : a)
    {
        if (hash.count(num) > 0)
            hash[num]++;
        else
            hash[num] = 1;
    }

    unordered_map<int, int>::iterator it = hash.begin();

    while (it != hash.end())
    {
        int num = it->first;
        if (hash.find(-num) != hash.end() && hash[num] != -1)
        {
            ans += hash[num] * hash[-num];
            hash[num] = -1;
            hash[-num] = -1;
        }
        it++;
    }
    return ans;
}

string extractUnique(string s)
{
    unordered_map<char, int> hash;

    for (auto c : s)
    {
        hash[c] = 1;
    }
    string ans;
    for (auto c : s)
    {
        if (hash[c] != 0)
        {
            hash[c] = 0;
            ans += c;
        }
    }
    return ans;
}

vector<int> longest_consecutive_subsequence(vector<int> a)
{
    unordered_map<int, bool> hash;
    int maxLength = 0;
    int start, end;

    for (auto num : a)
    {
        hash[num] = true;
    }

    for (auto num : a)
    {
        if (hash[num])
        {
            int mid = num, fake_end, fake_start;
            while (hash.count(mid) > 0)
            {
                fake_end = mid;
                hash[mid] = false;
                mid++;
            }
            mid = num;
            while (hash.count(mid) > 0)
            {
                fake_start = mid;
                hash[mid] = false;
                mid--;
            }

            if (fake_end - fake_start + 1 > maxLength)
            {
                maxLength = fake_end - fake_start + 1;
                start = fake_start;
                end = fake_end;
            }
        }
    }

    vector<int> ans;
    ans.push_back(start);
    if (start != end)
        ans.push_back(end);

    return ans;
}

int differenceKpairs(vector<int> a, int k)
{
    unordered_map<int, int> hash;
    int ans = 0;

    for (auto num : a)
    {
        if (hash.count(num) > 0)
            hash[num]++;
        else
            hash[num] = 1;
    }

    for (auto num : a)
    {
        if (hash.count(num) > 0 && hash.count(num + k) > 0)
        {
            ans += k == 0 ? (hash[num] * (hash[num] - 1)) / 2 : hash[num] * hash[num + k];
            if (k == 0)
                hash[num] = 0;
        }
    }

    return ans;
}

int main()
{
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // cout << maxFrequent(a) << endl;

    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // int m;
    // cin >> m;
    // vector<int> b(m);
    // for (int i = 0; i < m; i++)
    //     cin >> b[i];
    // vector<int> ans = intersection(a, b);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // cout << pairSum(a) << endl;

    // string s;
    // cin >> s;
    // cout << extractUnique(s) << endl;

    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // vector<int> ans = longest_consecutive_subsequence(a);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    cout << differenceKpairs(a, k) << endl;

    return 0;
}