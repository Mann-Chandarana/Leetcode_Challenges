//////// Question number 1295.

#include <bits/stdc++.h>
using namespace std;

/* log10(num) gives number of digit of a number  */
int findNumbers(vector<int> &nums)
{
    int res = 0;
    for (auto num : nums)
    {
        res += (int)log10(num) & 1;
    }
    return res;
}

// int find_digit(int num)
// {
//     int length = 0;

//     while (num != 0)
//     {
//         int rem = num % 10;
//         length++;
//         num /= 10;
//     }
//     return length;
// }

// int findNumbers(vector<int> &nums)
// {
//     int even_digit = 0;
//     for (auto element : nums)
//     {
//         if (find_digit(element) % 2 == 0)
//         {
//             even_digit++;
//         }
//     }
//     return even_digit;
// }

int main()
{
    vector<int> vec1 = {12, 345, 2, 6, 7896};
    cout << findNumbers(vec1) << endl;
    return 0;
}