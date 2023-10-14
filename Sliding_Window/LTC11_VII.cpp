/*--------  Medium --------*/

/*- Maximum Points You Can Obtain from Cards -*/

//////// Question number 1423.

#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size(),ans=0;

    for (int i = 0; i < k; i++)
       ans+=cardPoints[i];

    int res = ans;

    for (int i = k-1; i >=0; i--)
    {
        res-=cardPoints[i];
        res+=cardPoints[cardPoints.size()-k+i];

        ans = max(ans,res);
    }
    
    
    return ans;
}

int main()
{
    vector<int> cardPoints = {11, 49, 100, 20, 86, 29, 72};
    cout << maxScore(cardPoints, 4) << endl;
    return 0;
}