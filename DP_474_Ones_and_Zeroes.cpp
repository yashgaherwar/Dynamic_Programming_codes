/*

You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 
Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100

*/

/* Solution */


class Solution {
public:
  
    // Dynamic Programming Approach (Memoization)
    
    int dp[601][101][101];         // globally declared dp Array
    
    int fun(vector<string> &strs,int m,int n,int i){
        if(i>=strs.size()){
            return 0;
        }
        if(m+n==0 || m<0 || n<0){
            return 0;
        }
        
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int c0=count(strs[i].begin(),strs[i].end(),'0');
        int c1=count(strs[i].begin(),strs[i].end(),'1');
        int res1=0;
        if(c0<=m && c1<=n){
            res1=(1+fun(strs,m-c0,n-c1,i+1));
        }
        int res2=0;
        res2=fun(strs,m,n,i+1);
        dp[i][m][n]=max(res1,res2);
        
        return dp[i][m][n];
       
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i=0;
        memset(dp,-1,sizeof(dp));
        return fun(strs,m,n,i); 
        
    }
    
    
    
   /* 
   
          // Recursive Approach
   
   int fun(vector<string>& strs, int m, int n,int i){
        if(i==strs.size() || (m+n)==0){         // Base Case
            return 0;
        }
        
         
        int* flag=counter(strs[i]);
        
        int ans=0;
        if(flag[0]<=m && flag[1]<=n){
            ans=1+fun(strs,m-flag[0],n-flag[1],i+1);
        }
        
        int res=fun(strs,m,n,i+1);
        
        return max(ans,res);
        
    }
    
    int* counter(string s){
        int tmp[2];
        
        for(auto j: s){
            tmp[j-'0']++;
        }
        
        return tmp;
    }*/
    
};
