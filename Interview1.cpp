#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int total_space = 2;

    ///////////////////////// For upper half

    for (int i = 0; i < n; i++)
    {
        // For Stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        // For Space

        int space = 2 * n - 2 * (n - i);
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }

        // For another stars

        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    ///////////////////////// For lower half

    int stars = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }

        int space = 2 * n - 2 * stars;

        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        stars+=1;
        cout << endl;
    }

    return 0;
}