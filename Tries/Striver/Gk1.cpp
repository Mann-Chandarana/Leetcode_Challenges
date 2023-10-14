/* Geeks for geeks Longest common prefix in an array */

#include <bits/stdc++.h>
using namespace std;

/**** Simple solution ****/

string longestCommonPrefix(string arr[], int N)
{
    sort(arr, arr + N);
    string s = "";

    for (int i = 0; i < min(arr[0].size(), arr[N - 1].size()); i++)
    {
        if (arr[0][i] == arr[N - 1][i])
            s += arr[0][i];

        else
            break;
    }
    if (s != "")
        return s;
    else
        "-1";
}

/***** Using Trie data structure *****/
class Node
{
public:
    char data;
    Node *children[26];
    bool isTerminal;
    int noOfchild;

    Node(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->isTerminal = false;
        this->noOfchild = 0;
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
            {
                temp->children[index] = new Node(word[i]);
                temp->noOfchild += 1;
            }

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
};

string lca(Node *root, string str)
{
    string s = "";

    if (!root || str.length() == 0)
        return "";

    int check = 0;

    int index;

    for (int i = 0; i < 26; i++)
    {
        if (root->children[i])
        {
            check++;
            index = i;
        }
    }
    if (check == 0 or check > 1)
        return s;

    s.push_back(root->children[index]->data);

    return s + lca(root->children[index], str.substr(1));
}

bool compare(string a, string b) { return a.length() <= b.length(); }

string longestCommonPrefix(string arr[], int N)
{
    Trie *root = new Trie();

    for (int i = 0; i < N; i++)
        root->insert(arr[i]);

    sort(arr, arr + N, compare);

    string answer = lca(root->root, arr[0]);

    if (answer == "")
        return "-1";

    return answer;
}

int main()
{

    return 0;
}