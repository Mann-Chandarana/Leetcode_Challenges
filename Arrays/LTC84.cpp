#include <bits/stdc++.h>
using namespace std;

bool isSelfCrossing(vector<int> &distance)
{
    int n = distance.size();
    set<pair<int, int>> st;
    int x_cor = 0, y_cor = 0;

    pair<int, int> p = {0, 0};
    st.insert(p);

    for (int i = 0; i < n; i++)
    {
        if (i % 4 == 0)
        {
            for (int j = y_cor + 1; j <= y_cor + distance[i]; j++)
            {
                pair<int, int> p = {x_cor, j};
                if (st.find(p) != st.end())
                {
                    return true;
                }
                else
                {
                    st.insert(p);
                }
            }
            y_cor += distance[i];
        }
        else if (i % 4 == 1)
        {
            for (int j = x_cor - 1; j >= (x_cor - distance[i]); j--)
            {
                pair<int, int> p = {j, y_cor};
                if (st.find(p) != st.end())
                {
                    return true;
                }
                else
                {
                    st.insert(p);
                }
            }
            x_cor -= distance[i];
        }
        else if (i % 4 == 2)
        {
            for (int j = y_cor - 1; j >= y_cor - distance[i]; j--)
            {
                pair<int, int> p = {x_cor, j};
                if (st.find(p) != st.end())
                {
                    return true;
                }
                else
                {
                    st.insert(p);
                }
            }
            y_cor -= distance[i];
        }
        else
        {
            for (int j = x_cor + 1; j <= x_cor + distance[i]; j++)
            {
                pair<int, int> p = {j, y_cor};

                if (st.find(p) != st.end())
                {
                    return true;
                }
                else
                {
                    st.insert(p);
                }
            }
            x_cor += distance[i];
        }
    }


    return false;
}

int main()
{
    vector<int> vec = {1,1,1,1};
    cout << isSelfCrossing(vec) << endl;
    return 0;
}