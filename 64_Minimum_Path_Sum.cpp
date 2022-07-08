/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

*/

/* Solution */

class Solution {
public:
    
    // Type 2:- DP on Grid
    
    // Classic Dynamic Programming Approach
    // Recursion + Memoization
    // Time Complexity:- O(N*M)
    // Space Complexity:- O(N*M)
    
    int dp[205][205];
    
    int fun(int i,int j,vector<vector<int>>& grid){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int up=grid[i][j] + fun(i-1,j,grid);
        int left=grid[i][j] + fun(i,j-1,grid);
        
        return dp[i][j]=min(up,left);
    }
    
    int minPathSum(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        return fun(m-1,n-1,grid);
    }
};
