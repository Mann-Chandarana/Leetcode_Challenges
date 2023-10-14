/*  Maximum Sum Combination */

/* https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-sum-combination */

#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> answer;
    set<pair<int, int>> st;

    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({A[N - 1] + B[N - 1], {N - 1, N - 1}});
    st.insert({N - 1, N - 1});

    for (int count = 0; count < K; count++)
    {
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        answer.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        if (i - 1 >= 0)
        {
            int sum = A[i - 1] + B[j];
            pair<int, int> temp1 = make_pair(i - 1, j);

            if (st.find(temp1) == st.end())
            {
                pq.push({sum, temp1});
                st.insert(temp1);
            }
        }
        if (j - 1 >= 0)
        {
            int sum = A[i] + B[j - 1];
            pair<int, int> temp2 = make_pair(i, j - 1);

            if (st.find(temp2) == st.end())
            {
                pq.push({sum, temp2});
                st.insert(temp2);
            }
        }
    }
    return answer;
}

int main()
{
    return 0;
}