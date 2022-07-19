#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    int wordIdx;
    vector<int> restIsPallindrome;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        this->wordIdx = -1;
    }
};

class Trie
{
    TrieNode *root;

    bool isPallindrome(string word, int i, int j)
    {
        if (i > j)
            return false;

        while (i < j)
        {
            if (word[i++] != word[j--])
                return false;
        }

        return true;
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insert(string word, int wordIdx)
    {
        TrieNode *curr = root;

        for (int i = word.length() - 1; i >= 0; i--)
        {
            int index = word[i] - 'a';

            if (curr->children[index] == NULL)
                curr->children[index] = new TrieNode(word[i]);

            curr = curr->children[index];

            if (isPallindrome(word, 0, i - 1))
                curr->restIsPallindrome.push_back(wordIdx);
        }

        curr->wordIdx = wordIdx;
    }
    void search(string word, int wordIdx, vector<pair<int, int>> &ans)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';

            if (curr->children[index] == NULL)
                return;

            if (curr->wordIdx != -1 && isPallindrome(word, i, word.length() - 1))
                ans.push_back({wordIdx, curr->wordIdx});

            curr = curr->children[index];
        }

        if (curr->wordIdx > -1 && curr->wordIdx != wordIdx)
            ans.push_back({wordIdx, curr->wordIdx});

        if (!curr->restIsPallindrome.empty())
        {
            for (auto idx : curr->restIsPallindrome)
                ans.push_back({wordIdx, idx});
        }
    }
};

bool isPallindrome(string word)
{
    int i = 0, j = word.length() - 1;

    while (i < j)
    {
        if (word[i] != word[j])
            return false;
    }

    return true;
}

vector<int> selfPallindromes(vector<string> words)
{
    vector<int> indices;
    for (int i = 0; i < words.size(); i++)
    {
        if (isPallindrome(words[i]))
            indices.push_back(i);
    }

    return indices;
}

vector<pair<int, int>> findPallindromepPairs(vector<string> words)
{
    Trie t;
    vector<pair<int, int>> ans;
    vector<int> pallindromes = selfPallindromes(words);

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].empty())
        {
            for (auto idx : pallindromes)
            {
                ans.push_back({idx, i});
                ans.push_back({i, idx});
            }
        }
        else
            t.insert(words[i], i);
    }

    for (int i = 0; i < words.size(); i++)
        t.search(words[i], i, ans);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, int>> ans = findPallindromepPairs(a);

    for (auto it : ans)
    {
        cout << "[" << it.first << "," << it.second << "]"
             << " ";
    }
    cout << endl;

    return 0;
}