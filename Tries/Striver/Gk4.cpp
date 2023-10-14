/* Geeks for Geeks :- Trie (delete) */

#include <bits/stdc++.h>
using namespace std;

struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};

void deleteKey(trie_node_t *root, char key[])
{
    int n = strlen(key);
    int i = 0;

    for (int i = 0; i < n; i++)
    {
        if (!root->children[key[i] - 'a'])
            return;

        root = root->children[key[i] - 'a'];
    }
    root->value = 0;
}

int main()
{
    return 0;
}