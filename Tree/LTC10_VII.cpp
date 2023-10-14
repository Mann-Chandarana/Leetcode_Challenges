/*-------- Hard -----------*/

/*- Longest Path With Different Adjacent Characters  -*/

//////// Question number 2246.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> child;
int ans;

int dfs(string &s, int curr_node)
{
    
    int longest = 0, second_longest = 0;
    for (auto element : child[curr_node])
    {
        int len = dfs(s, element);
        ans = max(ans, len);
        if (s[curr_node] == s[element])
            continue;

        if (len > longest)
        {
            second_longest = longest;
            longest = len;
        }
        else
        {
            second_longest = max(len, second_longest);
        }
    }
    int first_possiblity = max(longest, second_longest) + 1;
    int second_possiblity = max(ans, longest + second_longest + 1);

    cout<<first_possiblity<<" "<<second_possiblity<<endl;

    ans = max(ans, max(first_possiblity, second_possiblity));
    return 1 + longest;
}
int longestPath(vector<int> &parent, string s)
{
    int n = parent.size();
    child.resize(n);
    for (int i = 1; i < n; i++)
        child[parent[i]].push_back(i);
    ans = 1;
    dfs(s, 0);
    return ans;
}

int main()
{
    vector<int> parent = {-1,0,0,1,1,2};
    cout << longestPath(parent, "abacbe") << endl;
    return 0;
}