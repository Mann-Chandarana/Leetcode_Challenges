/*-------- Medium -----------*/

/*- Implement Trie (Prefix Tree) -*/

//////// Question number 208.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *children[26];
    bool isTerminal;

    Node(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('/0');
    }

    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (temp->children[index] == NULL)
                temp->children[index] = new Node(word[i]);

            temp = temp->children[index];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';

            if (temp->children[index] == NULL)
                return false;

            temp = temp->children[index];
        }
        return temp->isTerminal;
    }

    bool startsWith(string prefix)
    {
        Node *temp = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if (temp->children[index] == NULL)
                return false;

            temp = temp->children[index];
        }
        return true;
    }
};

Trie *Root;
int n;

int solve(int idx, string s, vector<int> &dp)
{
    if (idx >= n)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    // Considering the first char as extra
    int minExtra = INT_MAX;

    Node *now = Root->root;

    for (int i = idx; i < n; i++)
    {
        // if current character is not present than the whole string is extra
        if ((now->children[s[i] - 'a']) == NULL)
        {
            int nextExtra = solve(i + 1, s, dp);
            int currentExtra = (i - idx + 1);

            return dp[idx] = min(minExtra, (currentExtra + nextExtra));
        }

        now = now->children[s[i] - 'a'];

        if (now->isTerminal)
            minExtra = min(minExtra, solve(i + 1, s, dp));
    }

    return dp[idx] = minExtra;
}

int minExtraChar(string s, vector<string> &dictionary)
{
    for (auto &element : dictionary)
        Root->insert(element);

    n = s.length();
    vector<int> dp(n, -1);

    return solve(0, s, dp);
}

int main()
{
    return 0;
}