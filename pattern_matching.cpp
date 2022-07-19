#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
    TrieNode *root;

    void insert(TrieNode *root, string word)
    {
        if (word.size() == 0)
            return;

        int index = word[0] - 'a';
        TrieNode *child = root->children[index];

        if (child == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insert(child, word.substr(1));
    }

    bool match(TrieNode *root, string pattern)
    {
        if (pattern.size() == 0)
            return true;

        if (root == NULL)
            return false;

        int index = pattern[0] - 'a';
        if (root->children[index] == NULL)
            return false;

        return match(root->children[index], pattern.substr(1));
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insert(string word)
    {
        while (word.size())
        {
            insert(root, word);
            word = word.substr(1);
        }
    }

    bool match(string pattern)
    {
        return match(root, pattern);
    }
};

bool findPattern(vector<string> words, string pattern)
{
    Trie t;

    for (auto word : words)
        t.insert(word);

    return t.match(pattern);
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string pattern;
    cin >> pattern;

    cout << findPattern(a, pattern) << endl;

    return 0;
}