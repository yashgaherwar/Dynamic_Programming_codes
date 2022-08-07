/*

Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".

Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4

*/


/* Solution */

// Dynamic Programming Approach

class Solution {
    int M = 1e9+7;
    unordered_map<char, vector<char>> mp{ {'s', {'a', 'e', 'i', 'o', 'u'}},                                                      
                                          {'a', {'e'}                   }, 
                                          {'e', {'a', 'i'}              }, 
                                          {'i', {'a', 'e', 'o', 'u'}    }, 
                                          {'o', {'i', 'u'}              },
                                          {'u', {'a'}                   }
                                        };
                                                     
                                                     
    unordered_map<char, vector<int>> dp;
    
public:
    
     int fun(int k,char p) {
        if(k == 0){
            return 1;  
        }
         
        if(dp[p][k]){
            return dp[p][k];  
        }    
        for(auto itr : mp.at(p)){
             dp[p][k] = (dp[p][k] + fun(k - 1, itr))%M;  
        }               
           
        return dp[p][k];
    }
    
    int countVowelPermutation(int n) {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);
        return fun(n,'s');                        
    }
    
    
   
};
