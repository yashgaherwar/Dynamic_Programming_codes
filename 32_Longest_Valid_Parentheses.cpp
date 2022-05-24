/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0
 
Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

*/

/* Solution */

class Solution {
public:
    //       [2]
    // Optimized Approach
    // Time Complexity:- O(N)
    // space Complexity:- O(1)------> IMP
    
    int longestValidParentheses(string s) {
        int c=0,o=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                o++;
            }
            else if(s[i]==')'){
                c++;
            }
            
            if(o==c){
                int res=2*o;
                maxi=max(maxi,res);
            }
            else if(c>o){
               c=0;
               o=0;
            }
        }
        
        int c2=0,o2=0;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                o2++;
            }
            else if(s[i]==')'){
                c2++;
            }
            
            if(o2==c2){
                int res2=2*o2;
                maxi=max(maxi,res2);
            }
            else if(o2>c2){
                c2=0;
                o2=0;
            }
        }
        
        return maxi;
           
        
        
    /*    
            [1]
        Stack Approach
    // Time Complexity:- O(N)
    // space Complexity:- O(N)----> IMP
    
        
        int maxi=0;
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int cc=(i-st.top());
                    maxi=max(maxi,cc);
                }
                
            }
        }
        
        return maxi;
        
        
       */ 
        
    
    }
};
