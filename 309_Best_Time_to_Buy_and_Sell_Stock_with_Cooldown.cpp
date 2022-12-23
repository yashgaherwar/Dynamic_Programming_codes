/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0
 
Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/

/* Solution */

class Solution {
public:
    vector<vector<int>> dp;
    int fun(int idx,int buy,int n,vector<int> &prices){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
            dp[idx][buy] = max((-prices[idx] + fun(idx+1,0,n,prices)),(0 + fun(idx+1,1,n,prices)));
        }
        else{
            dp[idx][buy] = max((prices[idx] + fun(idx+2,1,n,prices)),(0 + fun(idx+1,0,n,prices)));
        }

        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int> (n+1,-1));
        return fun(0,1,n,prices);
    }
};
