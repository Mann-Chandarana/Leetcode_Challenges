/*--------  Hard --------*/

/*- Largest Rectangle in Histogram -*/

//////// Question number 84

#include <bits/stdc++.h>
using namespace std;

/* Optimised approach */

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxA = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() and (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

/* General approach */

vector<int> nextSmallerElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v(n);

    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and nums[st.top()] >= nums[i])
            st.pop();

        if (st.empty())
            v[i] = n - 1;
        else
            v[i] = st.top() - 1;
        st.push(i);
    }

    return v;
}

vector<int> prevSmallerElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v(n);

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and nums[st.top()] >= nums[i])
            st.pop();

        if (st.empty())
            v[i] = 0;
        else
            v[i] = st.top() + 1;
        st.push(i);
    }
    return v;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> rightSmaller(n), leftSmaller(n);

    rightSmaller = nextSmallerElements(heights);
    leftSmaller = prevSmallerElements(heights);

    int maxArea = 0;

    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));

    return maxArea;
}

int main()
{
    return 0;
}