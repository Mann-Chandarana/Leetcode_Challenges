/*--------Medium-----------*/

//////// Question number 31.

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// 	    // Brute Force Solution Time O(N!*N) & Auxiliary Space O(N^2)
// 		// Recursion & Backtracking
// 	    // TLE 64/265 test cases passed
// public:
// 	// permute function takes time of O(N*N!)
//     void permute(int p,vector<int>& arr, vector<vector<int>>& res) {
//         int n=arr.size();
//         if(p==n) res.push_back(arr);
//         for(int i=p;i<n;i++) {  // Time O(N) for traversal of each permutation
//             swap(arr[i],arr[p]);
//             permute(p+1,arr,res);  // Time O(N!) for total number of permutations
//             swap(arr[i],arr[p]);
//         }
//     }
//     void nextPermutation(vector<int>& nums) {
//         vector<vector<int>> res; 
//         vector<int> arr=nums; 
//         permute(0,arr,res); 
//         set<vector<int>> s; // set stores unique elements in the sorted order
//         for(int i=0;i<res.size();i++){
//             s.insert(res[i]);
//         }
//         auto it=s.find(nums);
// 		// If nums is last element of the permutation order, 
// 		// then nums is equal to the first element of the 
// 		// permutation sequence
//         if(it==(--s.end())){
//             it=s.begin();
//             nums=*it;
//         }
// 		// else make nums equal to the immediate 
// 		// next element in the permutation sequence
//         else{
//             it++;
//             nums=*it;
//         }
//     }
// };

/*Approach 1:
Step 1: Linearly traverse the array from backwards so that the array's ith index value is less than the array's (i+1)th index value. Store  that index into a variable.
Step 2: If the index value obtained in step 1 is less than zero. This indicates that the given input array has already been sorted in descending order. Simply reverse the given array to obtain the next permutation. Otherwise, simply traverse the array backwards to find the index that has a value greater than the previously found index. Store index in another variable.
Step 3: Swap values present in indices found in the above two steps.
Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array*/

// int arr[] = {1, 3, 2};

// next_permutation(arr, arr + 3); // using in-built function of C++

// cout << arr[0] << " " << arr[1] << " " << arr[2];

void nextPermutation(vector<int> &nums)
{
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (l = 0; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}

int main()
{

    return 0;
}