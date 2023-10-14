//////// Question number 1480.


/* Javascript solution
var runningSum = function(nums) {
    return nums.reduce((acc,curr,i)=>{
        if(i>0){
            acc.push(acc[i-1]+curr)
        } else {
            acc.push(curr)
        }
        return acc;
    },[])
};

runningSum([1,2,3,4])
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main()
{
    return 0;
}