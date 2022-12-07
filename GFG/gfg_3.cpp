//////// Missing and repeated number


/* Find one repeated and one repeated twice
--- > Two approach we can also use bit manipulation
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> missing_repeated_number(const vector<int> &A)
{
    long long int len = A.size();

    long long int S = (len * (len + 1)) / 2;
    long long int P = (len * (len + 1) * (2 * len + 1)) / 6;
    long long int missingNumber = 0, repeating = 0;

    for (int i = 0; i < A.size(); i++)
    {
        S -= (long long int)A[i];
        P -= (long long int)A[i] * (long long int)A[i];
    }

    missingNumber = (S + P / S) / 2;

    repeating = missingNumber - S;

    vector<int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}

int *findTwoElement(int *arr, int n)
{
    unordered_map<int, int> mp;
    int greatest = INT_MIN;
    int *answer = new int[2];
    answer[1] = 0;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        greatest = max(greatest, arr[i]);
    }

    for (auto element : mp)
    {
        if (element.second == 2)
        {
            answer[0] = element.first;
        }
    }

    for (int i = 1; i < greatest; i++)
    {
        if (mp.find(i) == mp.end())
        {
            answer[1] = i;
            break;
        }
    }
    if (answer[1] == 0)
    {
        answer[1] = greatest + 1;
    }

    return answer;
}

int main()
{
    int *arr{new int[3]{1, 3, 3}};
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = findTwoElement(arr, 3);
    cout << arr[0] << " " << arr[1] << endl;
    return 0;
}