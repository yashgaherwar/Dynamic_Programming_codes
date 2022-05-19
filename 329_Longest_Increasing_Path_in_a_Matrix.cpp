/*

Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:

Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:

Input: matrix = [[1]]
Output: 1
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1

*/

/* Solution */

class Solution {
public:
    
    // Dynamic Programming Approach (Memomization Technique):-
    
    vector<vector<int>> d{{1,0},{-1,0},{0,1},{0,-1}};    // down, up, right, left
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int a=matrix.size();
        int b=matrix[0].size();
        int maxi=0;

        vector<vector<int>> t(a,vector<int> (b,-1));
        
            
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                int ans=my_fun(matrix,a,b,i,j,t);
                maxi=max(maxi,ans);
            }
        }
        
        return maxi;
    }
    
    int my_fun(vector<vector<int>>& matrix,int a,int b,int p,int q,vector<vector<int>> &t){
        if(t[p][q]!=-1){
            return t[p][q];
        }
        int maxi2=0;
        for(auto itr: d){
            int x=p+itr[0];
            int y=q+itr[1];
            
            if(x>=0 && x<a && y>=0 && y<b && matrix[x][y]>matrix[p][q]){
                maxi2=max(maxi2,my_fun(matrix,a,b,x,y,t));
            }
        }
        
        t[p][q]=1+maxi2;
        return 1+maxi2;
    }
};
