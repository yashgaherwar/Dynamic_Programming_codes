/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 
Constraints:

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

*/

/* Solution */

class Solution {
public:
    // Dynamic Programming Approach
    // Recursion + Memoization
    // Top-Down Dynamic Programming Approach
    
    
    int dp[1001][2][101];
    int dp_fun(int k,vector<int>& prices,int idx,int b){
        if(k==0){
            return 0;
        }
        
        if(idx==prices.size()){
            return 0;
        }
        
        if(dp[idx][b][k] != -1){
            return dp[idx][b][k];
        }
        
        if(b==1){
            return dp[idx][b][k] = max((-prices[idx]+dp_fun(k,prices,idx+1,0)), dp_fun(k,prices,idx+1,1));
        }
        else{
            return dp[idx][b][k] = max((prices[idx]+dp_fun(k-1,prices,idx+1,1)), dp_fun(k,prices,idx+1,0));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        
        memset(dp,-1,sizeof(dp));
        return dp_fun(k,prices,0,1);
    }
};
