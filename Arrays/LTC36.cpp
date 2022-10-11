//////// Question number 832.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> images(n, vector<int>(m, 0));
    for (int i = 0; i < image.size(); i++)
    {
        int len = image[i].size();
        for (int j = 0; j < image[i].size(); j++)
        {
            images[i][j] = 1 - image[i][len - j - 1];
        }
    }
    return images;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 0},
                                 {1, 0, 1},
                                 {0, 0, 0}};
    image = flipAndInvertImage(image);

    for (auto x : image)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}