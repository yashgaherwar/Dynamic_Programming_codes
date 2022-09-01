/*

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 
Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 100

*/

/* Solution */

class Solution {
public:
 
    int numOfSubarrays(vector<int>& arr) {
      
        // Prefix Sum Approach
        // Time Complexity:- O(n)
        // Space Complexity:- O(1)
        
        int ev=0,od=0;
        long long ans=0;
        int curr_sum=0;
        long long mod=1e9+7;
        
        for(int i=0;i<arr.size();i++){
            curr_sum+=arr[i];
            
            if(curr_sum%2!=0){
                ans++;
                od++;
                ans+=ev;
            }
            else{
                ans+=od;
                ev++;
            }
        }
        
        return ans%mod;
        
        
        /*
        
        // Brute Force Approach
        // Time Complexity:- O(n^2)
        // Space Complexity:- O(1)
        
        int count=0;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                if(sum%2!=0){
                    count++;
                }
            }
        }
        
        return count;
        
        */
    }
};
