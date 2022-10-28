/*--------Medium-----------*/

/*- Group anagram -*/

//////// Question number 49.

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> answer;  ////// Creating 2-D vector name answer 
    
    unordered_map<string, vector<string>> mp;  ////// Creating a map with key as a string value and value as a vector

    string midway = "";
    ///// Dummy string

    for (auto element : strs)
    {
        midway = element;
        sort(midway.begin(), midway.end());     ///// sorting string 
        mp[midway].push_back(element);         //// and pushing it to corresponding vector
    }
    

    /*
    map structure -- 
    mp[abt] = {"bat"}
    mp[atn] = {"nat","tan"}
    mp[aet] = {"ate","eat","tea"}
    */

    for (auto element : mp)
    {
        //// the vector correponding to its key in 2-d vector name answer
        answer.push_back(element.second);
    }

    return answer;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> answer = groupAnagrams(strs);
    for (auto element : answer)
    {
        for (auto ele : element)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}