/*

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3

Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: s = "aaa"
Output: 6

Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/


/* Solution */

class Solution {
public:
    // Dynamic Programming(Tabulation Approach)
    // Time Complexity: O(N^2);
    // Space Complexity: O(N^2);
    
    int countSubstrings(string s) {
        int n=s.size();
        int cc=0;
        vector<vector<bool>> dp(n,vector<bool> (n));
       
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            cc=cc+1;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true; 
                cc=cc+1;
            }
            else{
                dp[i][i+1]=false;
            }
        
           
        }
        
        for(int sz=3;sz<=n;sz++){
            int i=0;
            for(int j=sz+i-1;j<n;j++){
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    cc=cc+1;
                }
                else{
                    dp[i][j]=false;
                }
                
                i++;
            }
        }
        
        return cc;
    }
};
