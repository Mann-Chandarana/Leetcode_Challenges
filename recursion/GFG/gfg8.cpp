// Sort a Stack :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

void insertAtlocation(stack<int> &s, int element)
{
    if (s.empty() || element > s.top())
    {
        s.push(element);
        return;
    }
    int ele = s.top();
    s.pop();

    insertAtlocation(s, element);
    s.push(ele);
}

void sort(stack<int> &s)
{
    if (s.empty())
        return;

    int element = s.top();
    s.pop();

    sort(s);
    insertAtlocation(s, element);
}

int main()
{
    stack<int> st;
    int n, element;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        st.push(element);
    }
    sort(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}