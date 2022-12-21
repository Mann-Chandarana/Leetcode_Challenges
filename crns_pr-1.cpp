#include <bits/stdc++.h>
using namespace std;

map<char, float> expected_freq = {
    {'a', 8.167},
    {'b', 1.492},
    {'c', 2.782},
    {'d', 4.253},
    {'e', 12.702},
    {'f', 2.228},
    {'g', 2.015},
    {'h', 6.094},
    {'i', 6.966},
    {'j', 0.153},
    {'k', 0.772},
    {'l', 4.025},
    {'m', 2.406},
    {'n', 6.749},
    {'o', 7.507},
    {'p', 1.929},
    {'q', 0.095},
    {'r', 5.987},
    {'s', 6.327},
    {'t', 9.056},
    {'u', 2.758},
    {'v', 0.978},
    {'w', 2.360},
    {'x', 0.150},
    {'y', 1.974},
    {'z', 0.074},
};

vector<string> possible_str(26, "");

/***************** Encryption **************************/

string encrypt(string s, int k)
{
    string answer = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            continue;
        }

        int total_shift = ((s[i] - 'a') + k) % 26;
        answer += ('a' + total_shift);
    }
    return answer;
}

/***************** decryption **************************/

string decryptt(string cipher, int k)
{
    string plain = "";

    for (int j = 0; j < cipher.length(); j++)
    {
        if (cipher[j] == ' ')
        {
            plain += ' ';
            continue;
        }

        int val_int = (cipher[j] - 'a');
        int shift = val_int - k;
        if (shift < 0)
        {
            plain += char('z' + shift + 1);
        }
        else
        {
            plain += (char('a' + shift));
        }
    }
    
    return plain;
}

/***************** Brute force **************************/

double freq_score(string c, int k)
{
    map<char, float> freq;

    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] == ' ')
        {
            continue;
        }

        freq[c[i]]++;
    }

    double score = 0;
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        score += freq[c] * expected_freq[c];
    }

    return score;
}

void decrypt(string str)
{
    for (int i = 0; i < 26; i++)
    {
        string answer = "";
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == ' ')
            {
                answer += ' ';
                continue;
            }

            int val_int = (str[j] - 'a');
            int shift = val_int - i;
            if (shift < 0)
            {
                answer += char('z' + shift + 1);
            }
            else
            {
                answer += (char('a' + shift));
            }
        }
        possible_str[i] = answer;
        cout << "After shift " << i << " the value is :- " << answer << " predicted score " << freq_score(answer, i) << endl;
    }
}

int Predicted_answer(string s)
{
    double maxi = INT_MIN;
    int key = 0;

    for (int i = 0; i < 26; i++)
    {
        string possible = possible_str[i];
        double score = freq_score(possible, i);

        if (score > maxi)
        {
            maxi = score;
            key = i;
        }
    }
    return key;
}

int main()
{
    string str;
    cout << "Enter plain text " << endl;
    getline(cin, str);

    int k;
    cout << "Enter your key " << endl;
    cin >> k;

    string cipher = encrypt(str, k);
    cout << "Encryption of plain text :- " << cipher << "\n"
         << endl;

    cout << "Decrytion of cipher text :- " << decryptt(cipher, k) << "\n"
         << endl;

    decrypt(cipher);

    cout << "\nPredicted shift is: " << Predicted_answer(cipher) << endl;
    return 0;
}