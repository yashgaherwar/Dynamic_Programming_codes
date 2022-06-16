/*

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*/

/* Solution */

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int cc=1;
        int k=0;
        string res;
        
        for(int i=0; i<n; i++)
        {
            int l=i-1;
            int r=i+1;
            
            while(l>=0 && s[i]==s[l])
            {
                l--;
            }
            while(r<n && s[i]==s[r])
            {
                r++;
            }
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            int x=(r-1)-(l+1)+1;  
            if(x>cc)
            {
                cc=x;
                k=l+1;
            }
        }
        
        res=s.substr(k,cc);
        
        return res;
    }
};
