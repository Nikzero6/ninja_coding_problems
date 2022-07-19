#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// bruteforce, time & space problem
void ansCount(vector<string> words, string target, unordered_map<string, int> &hash, string ans, int ind)
{
    if (target.size() == 0)
    {
        hash[ans] = 1;
        return;
    }

    if (ind >= words[0].size())
        return;

    for (int i = 0; i < words.size(); i++)
    {
        char c = words[i][ind];

        if (c == target[0])
        {
            ans += ('0' + i) + '-' + ('0' + ind) + ',';
            ansCount(words, target.substr(1), hash, ans, ind + 1);
        }
        else
            ansCount(words, target, hash, ans, ind + 1);
    }
}

int stringFormation(vector<string> words, string target)
{
    unordered_map<string, int> hash;
    ansCount(words, target, hash, "", 0);
    return hash.size();
}

int main()
{

    // vector<string> words = {"adc", "aec", "efg"};
    // vector<string> words = {"valya", "lyglb", "vldoh"};
    vector<string> words = {"xzu", "dfw", "eor", "mat", "jyc"};
    cout << stringFormation(words, "cf") << endl;
    return 0;
}