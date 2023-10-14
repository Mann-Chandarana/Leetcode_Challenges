/* 
Geeks for Geeks 
Q) Minimum number of coins
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> currency = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

vector<int> minPartition(int N)
{
    vector<int> answer;
    while (N > 0)
    {
        int index = upper_bound(currency.begin(), currency.end(), N) - currency.begin()-1;
        answer.push_back(currency[index]);
        N -= currency[index];
    }
    return answer;
}

int main()
{
    vector<int> answer = minPartition(43);

    for (auto element : answer)
        cout << element << endl;
    return 0;
}