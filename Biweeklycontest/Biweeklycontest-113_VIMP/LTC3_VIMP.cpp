/*-------- Medium -----------*/

/*- Count Pairs of Points With Distance k -*/

//////// Question number 2857.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/*
 1) finding all possible (x,y) which gives :
 2) c[i][0]^x+c[i][1]^y=k                   (a)
 3) Consider above is true , then
 4) if , c[i][0]^x=val                      (b)
    then c[i][1]^y=k-val                    (c)
We can definitely find all possible values of val (0 to k inclusive)
 5) using a^b=c , then a^c=b
 6) from (b) , we have c[i][0]^val=x;
 7) (c) , we have c[i][1]^(k-val)=y;
 8) so we just need to traverse through all possible values of val to get pairs(x,y) satisfying  eq.(0)

*/

int countPairs(vector<vector<int>> &coordinates, int k)
{
    map<pair<int, int>, int> mp;

    int n = coordinates.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int value = 0; value <= k; value++)
        {
            int x = value ^ coordinates[i][0];
            int y = (k - value) ^ coordinates[i][1];

            ans += mp[{x, y}];
        }
        mp[{coordinates[i][0], coordinates[i][1]}]++;
    }
    return ans;
}

int main()
{
    return 0;
}