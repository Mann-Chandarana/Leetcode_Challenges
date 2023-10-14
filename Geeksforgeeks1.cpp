#include <bits/stdc++.h>
using namespace std;

int minTime(int n, vector<int> &health, vector<int> &power)
{
    int time = 1;
    int count = 0, i = 1;

    while (true)
    {
        for (int i = 1; i < health.size(); i++)
        {
            health[i] -= power[i - 1];
        }
        for (int i = 0; i < health.size(); i++)
        {
            if (health[i] <= 0)
            {
                health.erase(health.begin() + i);
                power.erase(power.begin() + i);
                i--;
            }
        }
        cout << endl;
        for (int i = 0; i < health.size(); i++)
        {
            cout << health[i] << " " << power[i] << endl;
        }
        cout << "size is " << health.size() << endl;
        if (health.size() <= 1)
            break;
        time++;
    }

    return time;
}

int main()
{
    vector<int> health = {1,2,1}, power = {2,1,3};
    cout << minTime(3, health, power) << endl;
    return 0;
}