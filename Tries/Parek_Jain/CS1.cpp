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
        root = new Node('\0');
    }

    void insert(string str)
    {
        Node *temp = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (temp->children[str[i] - 'a'] == NULL)
            {
                temp->children[str[i] - 'a'] = new Node(str[i]);
            }
            temp = temp->children[str[i] - 'a'];
        }
        temp->isTerminal = true;
    }

    int search(string str)
    {
        Node *temp = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (temp->children[str[i] - 'a'] == NULL)
                return false;

            temp = temp->children[str[i] - 'a'];
        }
        return temp->isTerminal;
    }

    void print_suggestion(Node *temp, vector<string> &answer, string str)
    {
        if (temp->isTerminal)
        {
            answer.push_back(str);
        }

        for (int i = 0; i < 26; i++)
        {
            if (temp->children[i] != NULL)
            {
                print_suggestion(temp->children[i], answer, str + char(i + 'a'));
            }
        }
    }

    void get_suggestion(string str, vector<string> &answer)
    {
        Node *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            if (temp->children[str[i] - 'a'])
                temp = temp->children[str[i] - 'a'];
        }
        print_suggestion(temp, answer, str);
    }
};

vector<string> spellChecker(vector<string> &dictionary, string &query)
{
    Trie *root = new Trie();
    vector<string> answer;

    for (auto element : dictionary)
        root->insert(element);

    if (root->search(query))
        cout << "CORRECT" << endl;

    else
    {
        string s = "";
        Node *curr = root->root;

        for (int i = 0; i < query.length(); i++)
        {
            if (curr->children[query[i] - 'a'] != NULL)
            {
                s += query[i];
                curr = curr->children[query[i] - 'a'];
            }
            else
                break;
        }
        root->get_suggestion(s, answer);

        return s == "" ? dictionary : answer;
    }
    return dictionary;
}

int main()
{
    vector<string> dictionary = {"sni", "spl", "swt", "smja", "smn", "sz", "si", "tsctmza", "abs", "ny", "ny", "m"};
    string query = "pzurwthht";
    dictionary = spellChecker(dictionary, query);
    for (auto element : dictionary)
    {
        cout << element << " ";
    }
    return 0;
}