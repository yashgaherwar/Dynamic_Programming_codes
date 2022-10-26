/*

Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 
Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
0 <= sum(nums[i]) <= 2^31 - 1
1 <= k <= 2^31 - 1

*/

/* Solution */

class Solution {
public:
    
    // Prefix Sum + Map Approach
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum=sum%k;
            
            if(sum==0 && i!=0){
                return true;
            }
            if(mp.find(sum)!=mp.end()){
                if((i-mp[sum])>=2){
                    return true;
                }
            }
            else{
                mp[sum]=i;
            }
  
        }  
        
        return false;
        
             
        
        /*vector<int> pref(nums.size());
        map<int,int> mp;
        
        pref[0]=nums[0];
        
        
        for(int i=1;i<nums.size();i++){
            pref[i]=pref[i-1]+nums[i];
        }
        
        for(int i=0;i<pref.size();i++){
            mp[pref[i]]++;
        }
        
        for(auto i: mp){
            if(i.second>1){
                return true;
            }
        }
        
        for(int i=1;i<pref.size();i++){
            if(pref[i]%k==0){
                return true;
            }
        }
        
        return false;*/
    }
};
