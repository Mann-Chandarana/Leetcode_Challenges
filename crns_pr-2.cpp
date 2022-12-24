// Play fair cypher

#include <bits/stdc++.h>
using namespace std;

void generateKeyTable(string key, int ks, vector<vector<char>> &keyT)
{
    int i, j, k, flag = 0;

    int dicty[26] = {0};
    for (i = 0; i < ks; i++)
    {
        if (key[i] != 'j')
        {
            dicty[key[i] - 97] = 2;
        }
    }
    dicty['j' - 97] = 1;

    i = 0;
    j = 0;

    for (k = 0; k < ks; k++)
    {
        if (dicty[key[k] - 97] == 2)
        {
            dicty[key[k] - 97] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }

    for (k = 0; k < 26; k++)
    {
        if (dicty[k] == 0)
        {
            keyT[i][j] = (char)(k + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
}

pair<int, int> search(char value, vector<vector<char>> table)
{
    pair<int, int> index;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (table[i][j] == value)
            {
                index = {i, j};
                return index;
            }
        }
    }
    return index;
}

string encrytpion(string key, string str)
{
    vector<vector<char>> table(5, vector<char>(5));
    generateKeyTable(key, key.length(), table);
    string var1 = "";

    for (int i = 0; i < str.length(); i += 2)
    {
        if (i + 1 < str.length() and str[i] == str[i + 1])
        {
            var1.push_back(str[i]);
            var1.push_back('x');
            i--;
        }
        else
        {
            var1.push_back(str[i]);
            if (i + 1 < str.length())
            {
                var1.push_back(str[i + 1]);
            }
            else
            {
                var1.push_back('x');
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << var1 << endl;
    string cipher = "";
    for (int i = 0; i < var1.length(); i += 2)
    {
        pair<int, int> index1 = search(var1[i], table);
        pair<int, int> index2 = search(var1[i + 1], table);

        if (index1.first == index2.first)
        {
            int j1 = index1.second;
            int j2 = index2.second;
            cipher.push_back(table[index1.first][(j1 + 1) % 5]);
            cipher.push_back(table[index2.first][(j2 + 1) % 5]);
        }
        else if (index1.second == index2.second)
        {
            int j1 = index1.first;
            int j2 = index2.first;
            cipher.push_back(table[(j1 + 1) % 5][index1.second]);
            cipher.push_back(table[(j2 + 1) % 5][index2.second]);
        }
        else
        {
            cipher.push_back(table[index1.first][index2.second]);
            cipher.push_back(table[index2.first][index1.second]);
        }
    }
    cout << "\nAfter encrytion ---> " << cipher << endl;
    return cipher;
}

void decryption(string cipher, string key)
{
    vector<vector<char>> table(5, vector<char>(5));
    generateKeyTable(key, key.length(), table);

    string var2 = "";

    for (int i = 0; i < cipher.length(); i += 2)
    {
        pair<int, int> index1 = search(cipher[i], table);
        pair<int, int> index2 = search(cipher[i + 1], table);

        if (index1.first == index2.first)
        {
            int j1 = index1.second;
            int j2 = index2.second;

            int z1 = (j1 - 1);
            if (z1 < 0)
            {
                z1 = 4;
            }
            int z2 = (j2 - 1);
            if (z2 < 0)
            {
                z2 = 4;
            }

            var2.push_back(table[index1.first][z1]);
            var2.push_back(table[index2.first][z2]);
        }
        else if (index1.second == index2.second)
        {
            int j1 = index1.first;
            int j2 = index2.first;
            int z1 = (j1 - 1);
            if (z1 < 0)
            {
                z1 = 4;
            }
            int z2 = (j2 - 1);
            if (z2 < 0)
            {
                z2 = 4;
            }
            var2.push_back(table[z1][index1.second]);
            var2.push_back(table[z2][index2.second]);
        }
        else
        {
            var2.push_back(table[index1.first][index2.second]);
            var2.push_back(table[index2.first][index1.second]);
        }
    }
    string plain = "";

    for (int i = 0; i < var2.length(); i++)
    {
        if (var2[i] == 'x')
        {
            continue;
        }
        plain.push_back(var2[i]);
    }
    cout << "\nAfter decrytion ---> " << plain << "\n"
         << endl;
}

int main()
{
    string str;
    cout << "Enter the string for encryption " << endl;
    getline(cin, str);

    string key;
    cout << "Enter the key for encryption " << endl;
    getline(cin, key);
    string cipher = encrytpion(key, str);
    decryption(cipher, key);

    return 0;
}