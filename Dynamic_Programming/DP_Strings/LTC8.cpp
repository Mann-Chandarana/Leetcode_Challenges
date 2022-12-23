/*-------- Hard -----------*/

/*- Edit Distance  -*/

//////// Question number 72.

#include <bits/stdc++.h>
using namespace std;

/* Using memorization */

int solver(string word1, string word2, int i, int j, vector<vector<int>> dp)
{
    if (i < 0)
    {
        return j + 1;
    }

    if (j < 0)
    {
        return i + 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (word1[i] == word2[j])
    {
        return dp[i][j] = solver(word1, word2, i - 1, j - 1, dp);
    }
    else
    {
        // For insert
        int val1 = solver(word1, word2, i, j - 1, dp);

        // For delete
        int val2 = solver(word1, word2, i - 1, j, dp);

        // For replace
        int val3 = solver(word1, word2, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min(val1, min(val2, val3));
    }
}

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solver(word1, word2, n - 1, m - 1, dp);
}

/* Using Tabulation */

int minDistance(string S1, string S2)
{
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
}

/* Using space optimization */

int minDistance(string S1, string S2)
{
    int n = S1.size();
    int m = S2.size();
    
    vector<int>prev(m+1,0),curr(m+1,0);
    
    
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        curr[0] = i;
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                curr[j] = 0+prev[j-1];
            
            else curr[j] = 1+min(prev[j-1],min(prev[j],curr[j-1]));
        }
        prev = curr;
    }
    
    return prev[m];
}

int main()
{
    cout << minDistance("horse", "ros") << endl;
    return 0;
}