/*--------  Medium --------*/

/*- Online Stock Span -*/

//////// Question number 901.

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
    vector<int>prices;
    stack<int> st;

public:
    StockSpanner()
    {
        prices.push_back(1e6);
        st.push(0);
    }

    int next(int price)
    {
       while(price>=prices[st.top()]){
           st.pop();
       }
       int ans = prices.size() - st.top();
       st.push(prices.size());
       prices.push_back(price);
       return ans;
    }
};

int main()
{
    return 0;
}