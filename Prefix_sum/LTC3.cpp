#include <bits/stdc++.h>
using namespace std;

// int bestClosingTime(string customers)
// {
//     int max_score = 0, score = 0, best_hour = -1;

//     for (int i = 0; i < customers.size(); i++)
//     {
//         score += customers[i] == 'Y' ? 1 : -1;
//         if (score > max_score)
//         {
//             max_score = score;
//             best_hour = i;
//         }
//     }
//     return best_hour + 1;
// }

int bestClosingTime(string customers)
{
    int n = customers.size();
    int count = (customers.begin(), customers.end(), 'N');
    int score = count, best_hour = n;
    int min_score = score;

    for (int i = n - 1; i >= 0; i--)
    {
        score += customers[i] == 'N' ? -1 : 1;

        if (score <= min_score)
        {
            best_hour = i;
            min_score = score;
        }
    }

    return best_hour;
}

int main()
{
    cout << bestClosingTime("N") << endl;
    return 0;
}