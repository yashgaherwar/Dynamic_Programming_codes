/*


You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999

*/

/* Solution */

class Solution {
public:
    
    // Dynamic Programming Approach
    
    int fun(int n,vector<int>& cost,vector<int> &dp){
        
        if(n<=1){
            return dp[n]=cost[n];
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        return dp[n]=cost[n]+min(fun(n-1,cost,dp),fun(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,-1);
        if(n==0){
            return 0;
        }
        return fun(n,cost,dp);
    
    }
    
    
    
    /*int fun(int n,vector<int> &cost,vector<int> &v){
        if(n<=1){
            return v[n]=cost[n];
        }
        
        if(v[n]!=0){
            return v[n];
        }
        
        return v[n]=min(fun(n-1,cost,v),fun(n-2,cost,v))+cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        vector<int> v(n+1,0);
        int ans=fun(n,cost,v);
        return ans;
    }*/
};
