/*

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Example 1:

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

*/

/* Solution */

// Classic Dynamic Programming Problem;
// Memomization + Recursion --> Top Down DP
// Time Complexity:- O(m*n*maxMoves)
// Space Complexity:- O(m*n*maxMoves)

long long dp[51][51][51];           // Globally Declared 3Dimensional 'dp' Array;

int fun(int m,int n,int maxMove, int i, int j){
    
    if(maxMove<0){                                  // if all moves are over then return zero                                                  
        return 0;
    }
    
    if(i<0 || j<0 || i>=m || j>=n){                 // This the important out of boundary conditions which is  the main part of this  question                                                                                                                                                                                                                                          
        return 1;
    }
    
    if(dp[i][j][maxMove]!=-1){                  // If the value at that index is already visited then simply return the value at that block                                                                                                                //
        return dp[i][j][maxMove];
    }
    
    
    
    long long lf = fun(m,n,maxMove-1,i,j-1);     // for left block
    long long rg = fun(m,n,maxMove-1,i,j+1);     // for right block
    long long up = fun(m,n,maxMove-1,i-1,j);     // for up block
    long long dw = fun(m,n,maxMove-1,i+1,j);     // for down block
    
    
    long long sum=(lf+rg+up+dw)%(1000000007);    // summing up the all the paths
    
    dp[i][j][maxMove]=sum;
    
    return dp[i][j][maxMove];                               //returnng the number of paths to move the ball out of the grid boundary       
    
}


int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    
    if(maxMove==0){                              // Base condition:- if maxMoves is zero then simply return 0                                        
        return 0;
    }
    memset(dp,-1,sizeof(dp));                       // fill all the 3-D array with -1
    return fun(m,n,maxMove,startRow,startColumn);   // Calling the fun for performing the given task                                                                               
}
};
