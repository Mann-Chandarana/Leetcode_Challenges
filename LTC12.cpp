#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
    int snap_id;
    vector<vector<pair<int, int>>> vec;

public:
    SnapshotArray(int length)
    {
        snap_id = 0;
        vec.resize(length);

        for (int i = 0; i < length; i++)
        {
            vec[i].push_back({0, 0});
        }
    }

    void set(int index, int val)
    {
        vec[index].push_back({snap_id, val});
    }

    int snap()
    {
        return snap_id++;
    }

    int get(int index, int snap_id)
    {
        auto it = upper_bound(begin(vec[index]), end(vec[index]), make_pair(snap_id, INT_MAX));
        // pair(snap_id, val)

        return prev(it)->second;
    }
};

int main()
{
    return 0;
}