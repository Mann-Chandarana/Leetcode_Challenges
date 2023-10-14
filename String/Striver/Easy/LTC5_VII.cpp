/* 205. Isomorphic Strings */

#include <bits/stdc++.h>
using namespace std;

/*
Approach :-

mp1       st
a-->x      x 
b-->y      y
c-->z      z 

*/

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, char> mp1;
    unordered_set<char> st;

    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        char key = s[i];
        char value = t[i];

        if (mp1.find(key) != mp1.end())
        {
            if (mp1[key] != value)
                return false;
        }
        else
        {
            if (st.find(value) != st.end())
                return false;

            mp1[key] = value;
            st.insert(value);
        }
    }
    return true;
}

int main()
{
    return 0;
}