/*

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.

*/

/* Solution */

class Solution {
public:
    // Dynamic Programming Approach
    // Longest Common Subsequence Problem
    // Time Complexity--> O(m*n)
    // Space Complexity--> O(m*n)
    
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> v(m+1,vector<int> (n+1));
        if(word1==word2){
            return 0;
        }
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    v[i][j]=0;
                }
            }
        }
        
         for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]){
                    v[i][j]=1+v[i-1][j-1];
                }
                else{
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
                }
            }
        }
        
        //cout<<v[m][n]<<endl;
        return m+n-2*v[m][n];
        
        
    }
};
