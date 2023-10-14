///// Important question

/*-------- Hard -----------*/

/*- Earliest Possible Day of Full Bloom -*/

//////// Question number 2136.

#include <bits/stdc++.h>
using namespace std;

int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
{
    int n = plantTime.size();
    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++)
    {
        vec[i] = {growTime[i], plantTime[i]};
    }

    sort(vec.begin(), vec.end(), greater<pair<int, int>>());

    //// sort in descending order of their growth time

    int prev_plant_time = 0;
    int max_bloom_time = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        int grow_time = vec[i].first;
        int plant_time = vec[i].second;

        prev_plant_time += plant_time;
        int bloom_time = prev_plant_time + grow_time + 1;

        ////// if total bloom time is greater than bloom 
        max_bloom_time = max(max_bloom_time, bloom_time);

        /*
        eg -  plant time - {1,3,1} , grow time - {2,4,5}
        sorting in descending order - grow time -> {5,4,2}
                                      plant time -> {1,3,1}

        P - Planting  
        B - Bloomed
        G - Growing 

        day|0|1|2|3|4|5|6|7|8|
           |P|G|G|G|G|G|B| | |
             |P|P|P|G|G|G|G|B|        -----> here 4+3 is taking the maximum time so we have to check in every seed
                   |P|G|G|B|       
           
        */
    }
    return max_bloom_time-1;
}

int main()
{
    vector<int> plantTime = {27, 5, 24, 17, 27, 4, 23, 16, 6, 26, 13, 17, 21, 3, 9, 10, 28, 26, 4, 10, 28, 2};
    vector<int> growTime = {26, 9, 14, 17, 6, 14, 23, 24, 11, 6, 27, 14, 13, 1, 15, 5, 12, 15, 23, 27, 28, 12};
    cout << earliestFullBloom(plantTime, growTime) << endl;
    return 0;
}