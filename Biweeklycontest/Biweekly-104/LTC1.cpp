/* 2678 */

/* Number of Senior Citizens */

#include <bits/stdc++.h>
using namespace std;

int countSeniors(vector<string> &details)
{
    int answer = 0;
    for (auto element : details)
    {
        if (stoi(element.substr(11, 2)) > 60)
            answer++;
    }
    return answer;
}

int main()
{
    vector<string> details = {"1313579440F2036", "2921522980M5644"};

    cout << countSeniors(details) << endl;
    return 0;
}