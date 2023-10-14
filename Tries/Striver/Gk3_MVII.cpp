/* Geeks for Geeks :- Number of distinct substring in a strings*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *children[26];

    Node()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

int countDistinctSubstring(string s)
{
    Node *trie = new Node();
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        Node *node = trie;
        for (int j = i; j < s.length(); j++)
        {
            if (node->children[s[j] - 'a'] == NULL)
            {
                node->children[s[j] - 'a'] = new Node();
                count++;
            }
            node = node->children[s[j] - 'a'];
        }
    }
    return count+1;
}

int main()
{
    return 0;
}