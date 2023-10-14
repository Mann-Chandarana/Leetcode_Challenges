///// Important question
/*--------Medium-----------*/

/*- Find the Student that Will Replace the Chalk -*/

//////// Question number 1894.

#include <bits/stdc++.h>
using namespace std;

/**---------------Prefix sum with binary search-----------------*/
int chalkReplacer(vector<int> &chalk, int k)
{
    int ans = -1, n = chalk.size();
    vector<long long> presum(n, 0);

    presum[0] = chalk[0];
    for (int i = 1; i < n; i++)
    {
        presum[i] = chalk[i] + presum[i - 1];
    }

    k = k % presum[n - 1];
    int i = 0, j = n - 1;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (presum[mid] == k)
        {
            cout << presum[mid] << " ";
            return mid + 1;
        }
        else if (presum[mid] < k)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return i;
}

int main()
{
    vector<int> chalk = {3, 4, 1, 2};
    cout << chalkReplacer(chalk, 25) << endl;
    return 0;
}