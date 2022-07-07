/*

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:

Input: matrix = [["0"]]
Output: 0

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

*/

/* Solution */

class Solution {
public:
  
    // Type 4:- DP on Grid.
    
    // Classic Dynamic Programming Problem
    // Time Complexity:- O(M*N)
    // Space Complexity:- O(M*N);
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int mini=0;
        
        if(m==0){
            return 0;
        }
        
        vector<vector<int>> v(m+1,vector<int> (n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    v[i][j]=1+min(mini,min({v[i-1][j],v[i][j-1],v[i-1][j-1]}));
                    if(v[i][j]>mini){
                        mini=v[i][j]; 
                    }
                   
                }
            }
        }
        
        return mini*mini;
    }
};
