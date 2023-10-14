/*--------  Hard --------*/

/*- Maximal Rectangle -*/

//////// Question number 85

#include <bits/stdc++.h>
using namespace std;

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

int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size(), result = 0;
    vector<int> histogram(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
                histogram[j] += 1;
            else
                histogram[j] = 0;
        }

        result = max(result, largestRectangleArea(histogram));
        cout << result << " ";
    }
    return result;
}

int main()
{
    return 0;
}