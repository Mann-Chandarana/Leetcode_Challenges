/* Geeks for Geeks :- Page Fault in LRU */

#include <bits/stdc++.h>
using namespace std;

int pageFaults(int N, int C, int pages[])
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;

    int page_faults = 0;
    for (int i = 0; i < N; i++)
    {
        if (s.size() < C)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
    }
    return page_faults;
}

int main()
{
    return 0;
}