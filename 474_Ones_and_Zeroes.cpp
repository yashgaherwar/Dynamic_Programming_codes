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

// Memoization Technique (Top-Down DP):-
class Solution {
public:
    
    int t[101][101][601];
    int my_fun(vector<string> &strs, int m, int n,int i){
        if(i>=strs.size() || (m+n)==0 || m<0 || n<0){
            return 0;
        }
        
        if(t[m][n][i]!=-1){
            return t[m][n][i];
        }
        
        int count_0=count(strs[i].begin(),strs[i].end(),'0');
        int count_1=strs[i].size()-count_0;
        
        int res1=0;
        if(count_0<=m && count_1<=n){
            res1=1+my_fun(strs,m-count_0,n-count_1,i+1);
        }
        int res2=my_fun(strs,m,n,i+1);
        return t[m][n][i]=max(res1,res2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i=0;
        memset(t,-1,sizeof(t));
        return my_fun(strs,m,n,i);
        
    
    }
    
    
    
    
   /* int fun(vector<string>& strs, int m, int n,int i){
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
