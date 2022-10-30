/*

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

Example 1:

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

Example 2:

Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0

*/

/* Solution */

class Solution {
public:

int n,m;
    int mx = 1e4;
    
    int solve(vector<vector<int>>& grid, int k,int i,int j,vector<vector<int>>&vis,vector<vector<vector<int>>>&dp){
       
        int a = mx,b = mx,c = mx,d = mx;
     

        if(i>=n || j>=m || i<0 || j<0 || vis[i][j] == 0){
            return mx;
        }

        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }

        if(i==0 and j==0){
            return dp[i][j][k] = 0;
        }


        if(grid[i][j]==1){
            if(k>0){
                k--;
            }
            else{
                return dp[i][j][k] = mx;
            }
        }

        vis[i][j] = 0;
        
        
        if(i-1>=0 ){
            c = solve(grid,k,i-1,j,vis,dp);
        }
        if(j-1>=0){
            d = solve(grid,k,i,j-1,vis,dp);
        }
        if(i+1<n){
            a = solve(grid,k,i+1,j,vis,dp);
        }
        if(j+1<m){
            b = solve(grid,k,i,j+1,vis,dp);
        }
        vis[i][j] = 1;
        
        return dp[i][j][k] = 1 + min({a,b,c,d});
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,1));
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans =  solve(grid,k,n-1,m-1,vis,dp);
        
        if(ans>=mx){
            return -1;
        }
        return ans;
    }
  
  
/*

    // 51/52 Test Cases Passed
    
    
    int ans=0;
    int flag=0;
    vector<vector<vector<int>>> dp;

    int dfs(int m,int n,vector<vector<int>> &grid,int i,int j,int k, vector<vector<int>> &vis){
        
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j]==1){
            return 1e6;
        }

        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }

        if(i==0 && j==0){
            return dp[i][j][k]=0;
        }


        if(grid[i][j]==1){
            if(k>0){
                k--;
            }
            else{
                return dp[i][j][k]=1e6;
            }
            
        }

        vis[i][j]=1;

        int up=1+dfs(m,n,grid,i+1,j,k,vis);
        int dw=1+dfs(m,n,grid,i-1,j,k,vis);
        int rg=1+dfs(m,n,grid,i,j+1,k,vis);
        int lf=1+dfs(m,n,grid,i,j-1,k,vis);

        vis[i][j]=0;

        dp[i][j][k]=min({up,dw,rg,lf});
        
        return dp[i][j][k];

        
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        //memset(dp,-1,sizeof(dp));
        dp.resize(m+1,vector<vector<int>> (n+1,vector<int> (k+1,-1)));
        int my_res=dfs(m,n,grid,m-1,n-1,k,vis);
        
        if(my_res>=(m*n)){
            return -1;
        }
        else{
            return my_res;
        }
    }
    
    */
};
