//////// Question number 2383.

#include <bits/stdc++.h>
using namespace std;

int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
{
    int sum = 0;
    for (auto ele : energy)
    {
        sum += ele;
    }

    int hours = 0;
    if (initialEnergy <= sum)
    {
        hours = (sum - initialEnergy + 1);
    }

    for (int i = 0; i < experience.size(); i++)
    {
        if (experience[i] >= initialExperience)
        {
            int temp = (experience[i] - initialExperience + 1);
            hours += temp;
            initialExperience += temp + experience[i];
        }
        else
        {
            initialExperience += experience[i];
        }
    }
    return hours;
}

// int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
// {
//     int hours = 0;
//     for (int i = 0; i < energy.size(); i++)
//     {
//         if (energy[i] >= initialEnergy)
//         {
//             hours += energy[i] - initialEnergy + 1;
//             initialEnergy += energy[i] - initialEnergy + 1;
//         }

//         if (experience[i] >= initialExperience)
//         {
//             hours += experience[i] - initialExperience + 1;
//             initialExperience += experience[i] - initialExperience + 1;
//         }

//         initialEnergy -= energy[i];
//         initialExperience += experience[i];
//     }
//     return hours;
// }

int main()
{
    return 0;
}