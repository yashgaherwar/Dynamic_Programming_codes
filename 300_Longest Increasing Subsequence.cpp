/*

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104

*/

/* Solution */

class Solution {
public:
    
    // Dynamic Programming Approach
    // Bottom Up DP (Tabulation)
    // Time Complexity:- O(N*N)
    // Space Complexity:- O(N)
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(),1);    // dp vector for storing length of increasing subsequence
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);     // updating the dp vector whenever nums[i] > nums[j]
                }
                
            }
        }
        
        return *max_element(dp.begin(),dp.end());   // returning the longest increasing subsequence
        
        
    }
};
 
