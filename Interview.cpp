#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, vector<string>> mp;

    vector<string> level1 = {"Orange Juice", "Mango Juice", "Apple Juice"};
    mp['J'] = level1;

    vector<string> level2 = {"Coca Cola", "Thums Up", "Pepsi", "Fanta", "Jeera", "7 Up", "Sprite", "Mountain Dew"};
    mp['S'] = level2;

    vector<string> level3 = {"Red Bull", "Sting", "Gatorade", "Monster Energy Drink"};
    mp['E'] = level3;

    vector<string> level4 = {"Cold Coffee", "Nimbu Pani", "Lassi", "Masala Chaas"};
    mp['B'] = level4;

    cout << "Welcome to Drinks Shop!" << endl;
    char ch;
    cout << "Enter character" << endl;
    cin >> ch;

    int number;
    cin >> number;

    for (int i = 0; i < mp[ch].size(); i++)
    {
        if (i + 1 == number)
            cout << "Enjoy your " << mp[ch][i]<<"!" << endl;
    }

    return 0;
}