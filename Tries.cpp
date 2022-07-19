#include <iostream>
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

private:
    void insert(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isEnd = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insert(child, word.substr(1));
    }

public:
    void insert(string word)
    {
        insert(root, word);
    }

private:
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isEnd;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL)
            return false;

        return search(root->children[index], word.substr(1));
    }

public:
    bool search(string word)
    {
        return search(root, word);
    }

private:
    bool hasChild(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
                return true;
        }

        return false;
    }

    void remove(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isEnd = false;
            return;
        }

        TrieNode *child = root->children[word[0] - 'a'];

        if (child == NULL)
            return;

        remove(child, word.substr(1));

        if (child->isEnd || hasChild(child))
            return;

        delete child;
        root[word[0] - 'a'] = NULL;
    }

public:
    void remove(string word)
    {
        remove(root, word);
    }
};
int main()
{
    Trie t;

    t.insert("are");
    t.insert("as");
    t.insert("note");
    t.insert("no");
    t.insert("bed");
    t.insert("be");

    cout << t.search("as") << endl;
    cout << t.search("note") << endl;
    cout << t.search("be") << endl;
    cout << t.search("notes") << endl;
    cout << t.search("ar") << endl;

    t.remove("are");
    t.remove("note");
    t.remove("be");

    cout << t.search("as") << endl;
    cout << t.search("note") << endl;
    cout << t.search("be") << endl;
    cout << t.search("notes") << endl;
    cout << t.search("ar") << endl;
    cout << t.search("are") << endl;

    return 0;
}