// Reverse a Stack :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

void insertAtbottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }
    int ele = st.top();
    st.pop();
    insertAtbottom(st, element);
    st.push(ele);
}

void Reverse(stack<int> &st)
{
    if (st.empty())
        return;

    int element = st.top();
    st.pop();
    Reverse(st);

    insertAtbottom(st, element);
}

int main()
{
    return 0;
}