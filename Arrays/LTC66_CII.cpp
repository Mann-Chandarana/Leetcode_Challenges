///// Important question

/*--------Medium-----------*/

/*- Integer to roman -*/

//////// Question number 12.

#include <bits/stdc++.h>
using namespace std;

// vector<int> numbers = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
// vector<string> num_str = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

// string intToRoman(int num)
// {
//     string answer = "";

//     while (num > 0)
//     {
//         int index = upper_bound(numbers.begin(), numbers.end(), num) - numbers.begin() - 1;
//         answer += num_str[index];
//         num -= numbers[index];
//     }

//     return answer;
// }

string intToRoman(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM", "MMM"};

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}

int main()
{
    cout << intToRoman(1994) << endl;
    return 0;
}