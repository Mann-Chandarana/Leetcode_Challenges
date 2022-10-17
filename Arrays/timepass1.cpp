#include <bits/stdc++.h>
using namespace std;

bool matching_array(vector<int> list, vector<int> sublist)
{
    int j = 0;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == sublist[j])
        {
            int k = i;
            while (list[k] == sublist[j] and k < list.size())
            {
                k++;
                j++;
            }
            j -= 1;
            if (j == sublist.size() - 1)
            {
                return true;
            }
            else
            {
                j = 0;
            }
        }
    }

    return false;
}

int main()
{
    int length, sub_len;
    cin >> length;
    string list1, list2;

    cin >> list1;
    vector<int> list(length);

    cin >> sub_len;
    cin >> list2;

    vector<int> sublist(sub_len);

    int i = 0, j = 0;
    while (j < list1.length())
    {
        if (list1[j] != ',')
        {
            list[i] = int(list1[j]-'0');
            i++;
        }
        j++;
    }

     i = 0, j = 0;
    while (j < list2.length())
    {
        if (list2[j] != ',')
        {
            sublist[i] = int(list2[j]-'0');
            i++;
        }
        j++;
    }

    if (matching_array(list, sublist))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}