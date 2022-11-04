#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestPalindrome(vector<string> &words)
{
    unordered_map<string, int> ump;
    unordered_map<string, int> ump2;

    for (auto &word : words)
        ump[word]++;

    int pair_count = 0;

    for (auto &word : words)
    {
        if (!ump[word])
            continue;

        string rev_word = "";
        rev_word += word[1];
        rev_word += word[0];

        if (rev_word == word)
            ump2[word]++;
        else if (ump.count(rev_word) > 0 && ump[rev_word])
        {
            pair_count++;
            ump[word]--;
            ump[rev_word]--;
        }
    }

    unordered_map<string, int>::iterator it = ump2.begin();

    int odd = 0;
    while (it != ump2.end())
    {
        int count = it->second;
        if (count & 1)
            odd = 1;
        pair_count += count / 2;
        it++;
    }

    return 4 * pair_count + 2 * odd;
}

int main()
{
    vector<string> a = {"ab",
                        "ty",
                        "yt",
                        "lc",
                        "cl",
                        "ab"};
    vector<string> b = {"lc", "cl", "gg"};
    vector<string> c = {"em", "pe", "mp", "ee", "pp", "me", "ep", "em", "em", "me"};

    cout
        << longestPalindrome(c);
    return 0;
}