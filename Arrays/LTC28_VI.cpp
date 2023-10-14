//////// Question number 914.

#include <bits/stdc++.h>
using namespace std;

/* Gcd largest number find karne ki liye hota hai jo all possible numbers to divide kare */

bool hasGroupsSizeX(vector<int> &deck)
{
    map<int, int> MAP;
    for (int i = 0; i < deck.size(); ++i)
        MAP[deck[i]]++;
    int GCD = MAP[deck[0]];
    for (int i = 1; i < deck.size(); ++i)
        GCD = __gcd(GCD, MAP[deck[i]]);
    return GCD >= 2;
}

// bool hasGroupsSizeX(vector<int> &deck)
// {
//     unordered_map<int, int> mp;

//     for (int i = 0; i < deck.size(); i++)
//     {
//         mp[deck[i]]++;
//     }

//     int mini = INT_MAX;

//     for (auto element : mp)
//     {
//         if (element.second < mini)
//         {
//             mini = element.second;
//         }
//     }

//     if (mini < 2)
//     {
//         return false;
//     }

//     for (int i = 2; i <= mini; i++)
//     {
//         bool is_true = true;
//         for (auto element : mp)
//         {
//             if (element.second % i != 0)
//             {
//                 is_true = false;
//                 break;
//             }
//         }
//         if (is_true)
//         {
//             return true;
//         }
//     }

//     return false;
// }

int main()
{
    return 0;
}