#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

vector<vector<int>> direction = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{
    int n = img.size(), m = img[0].size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum_neigh = 0, count_neigh = 0;

            for (auto &it : direction)
            {
                int di = i + it[0];
                int dj = j + it[1];

                if (di >= 0 and di < n and dj >= 0 and dj < m)
                {
                    sum_neigh += img[di][dj];
                    count_neigh++;
                }
            }
            result[i][j] = (sum_neigh / count_neigh);
        }
    }
    return result;
}

vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{
    int n = img.size(), m = img[0].size();

    vector<int> temp(n);
    int prev_corner = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0, count = 0;

            //////// 1) Lower side

            if (i + 1 < n)
            {
                if (j - 1 >= 0)
                    sum += img[i + 1][j - 1], count++;

                sum += img[i + 1][j], count++;

                if (j + 1 < m)
                    sum += img[i + 1][j + 1], count++;
            }

            //////// 2) Right side

            if (j + 1 < m)
                sum += img[i][j + 1], count++;

            /////// 3) Current cell

            sum += img[i][j], count++;

            //////// 4) Left Side

            if (j - 1 >= 0)
                sum += temp[j-1], count++;

            ////// 5) Top Side

            if (i - 1 >= 0)
            {
                ////// Top corner
                if (j - 1 >= 0)
                    sum += prev_corner, count++;

                ////// Upper element
                sum += temp[j], count++;

                ////// Right corner
                if (j + 1 < m)
                    sum += temp[j + 1], count++;
            }

            if (i - 1 >= 0)
                prev_corner = temp[j];

            temp[j] = img[i][j];

            img[i][j] = sum / count;
        }
    }
    return img;
}

int main()
{
    return 0;
}