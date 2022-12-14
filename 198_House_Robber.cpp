/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 
Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

*/

/* Solution */

class Solution {
public:
    int rob(vector<int>& nums) {
       /* Greedy Approach */
        int inc=nums[0];
        int exc=0;
        for(int i=1;i<nums.size();i++){
            int ninc=nums[i]+exc;
            int nexc=max(inc,exc);
            
            inc=ninc;
            exc=nexc;
        }
        
        return max(inc,exc);
        
        
        /*
        Dynamic Programming Approach:-
        
        int sum=0,flag=0;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int dp[n+1];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        
        return dp[n-1];*/
    }
};
