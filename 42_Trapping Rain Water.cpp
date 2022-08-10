/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

*/

/* Solution */

class Solution {
public:
    
    // Dynamic Programming Approach
    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
    
    int trap(vector<int>& height) {
        
        int n=height.size();
        int ans=0;
        
        vector<int> left(n);
        
        left[0]=height[0];
        
        for(int i=1;i<n;i++){
            left[i]=max(height[i],left[i-1]);
        }
        
        vector<int> right(n);
        
        right[n-1]=height[n-1];
        
        for(int i=n-2;i>=0;i--){
            right[i]=max(height[i],right[i+1]);
        }
        
        for(int i=0;i<n;i++){
            ans+=(min(left[i],right[i])-height[i]);
        }
        
        return ans;
            
    }
};
