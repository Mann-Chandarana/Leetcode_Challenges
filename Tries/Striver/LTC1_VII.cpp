/*--------  Medium --------*/

/*- Maximum XOR of Two Numbers in an Array -*/

//////// Question number 421.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *zero;
    Node *one;

    Node()
    {
        zero = NULL;
        one = NULL;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int n)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 1)
            {
                if (temp->one == NULL)
                    temp->one = new Node();

                temp = temp->one;
            }
            else
            {
                if (temp->zero == NULL)
                    temp->zero = new Node();

                temp = temp->zero;
            }
        }
    }

    int maximumXor(int n)
    {
        Node *temp = root;
        int answer = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->one != NULL)
                {
                    temp = temp->one;
                    answer += (1 << i);
                }
                else
                    temp = temp->zero;
            }
            else
            {
                if (temp->zero != NULL)
                {
                    temp = temp->zero;
                    answer += (1 << i);
                }
                else
                    temp = temp->one;
            }
        }
        return answer;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    int max_xo = 0;
    Trie *root = new Trie();

    for (auto element : nums)
    {
        root->insert(element);
        int curr_xor = root->maximumXor(element);
        max_xo = max(curr_xor, max_xo);
    }
    return max_xo;
}

int main()
{

    return 0;
}