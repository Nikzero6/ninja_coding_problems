#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isEnd;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isEnd = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    string insert(string word)
    {
        TrieNode *curr = root;
        for (auto c : word)
        {
            int index = c - 'a';

            if (curr->children[index] == NULL)
                curr->children[index] = new TrieNode(c);

            if (curr->isEnd)
                return word;

            curr = curr->children[index];
        }

        if (curr->isEnd)
            return word;

        for (int i = 0; i < 26; i++)
        {
            if (curr->children[i] != NULL)
                return word;
        }

        curr->isEnd = true;
        return "";
    }
};

string noPrefix(vector<string> words)
{
    Trie t;

    for (auto word : words)
    {
        string s = t.insert(word);
        if (s != "")
            return s;
    }
    return "";
}

long long maxAbsDiffSum(int n)
{
    if (n == 1)
        return 1;

    vector<int> a;

    for (int i = 1; i <= n / 2; i++)
    {
        a.push_back(i);
        a.push_back(n - i + 1);
    }

    if (n % 2 != 0)
    {
        a.push_back(n / 2 + 1);
    }

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
        ans += abs(a[i + 1] - a[i]);

    return ans;
}

int main()
{
    // int n;
    // cin >> n;
    // vector<string> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    // string ans = noPrefix(a);

    // cout << ans << endl;

    int n;
    cin >> n;
    cout << maxAbsDiffSum(n) << endl;

    return 0;
}