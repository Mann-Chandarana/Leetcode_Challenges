/*--------  Medium --------*/

/*- Design Browser History -*/

//////// Question number 1472.

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
public:
    vector<string> vec;
    int idx;
    BrowserHistory(string homepage)
    {
        this->vec.push_back(homepage);
        idx = 0;
    }

    void visit(string url)
    {
        vec.resize(idx + 1);
        this->vec.push_back(url);
        this->idx++;
    }

    string back(int steps)
    {
        int prev_idx = max(0, idx - steps);
        this->idx = prev_idx;
        return this->vec[prev_idx];
    }

    string forward(int steps)
    {
        int size = this->vec.size() - 1;
        int for_idx = min(size, idx + steps);
        this->idx = for_idx;
        return vec[for_idx];
    }
};

int main()
{
    cout << "Hello" << endl;
    BrowserHistory *obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");

    cout << obj->back(1) << endl;
    cout << obj->back(1) << endl;
    cout << obj->forward(1) << endl;

    obj->visit("linkedin.com");
    cout << obj->forward(2) << endl;
    cout << obj->back(2) << endl;
    cout << obj->back(7) << endl;
    return 0;
}