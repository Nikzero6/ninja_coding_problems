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

    void insert(string word)
    {
        TrieNode *curr = root;
        for (auto c : word)
        {
            int index = c - 'a';

            if (curr->children[index] == NULL)
                curr->children[index] = new TrieNode(c);

            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

private:
    void search(TrieNode *root, string word, string ans, vector<string> &ds)
    {
        if (root == NULL)
            return;

        if (word.size() == 0 && root->isEnd)
            ds.push_back(ans);

        if (word.size() != 0)
        {
            int index = word[0] - 'a';

            if (root->children[index] == NULL)
                return;

            ans += word[0];
            search(root->children[index], word.substr(1), ans, ds);
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    ans += root->children[i]->data;
                    search(root->children[i], word, ans, ds);
                }
            }
        }
    }

public:
    vector<string> search(string word)
    {
        vector<string> ds;
        search(root, word, "", ds);
        return ds;
    }
};

vector<string> autoComplete(vector<string> words, string word)
{
    Trie t;

    for (auto word : words)
        t.insert(word);

    return t.search(word);
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string word;
    cin >> word;
    vector<string> ans = autoComplete(a, word);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}