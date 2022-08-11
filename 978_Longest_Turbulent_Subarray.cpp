/*

Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
 

Example 1:

Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

Example 2:

Input: arr = [4,8,12,16]
Output: 2

Example 3:

Input: arr = [100]
Output: 1
 

Constraints:

1 <= arr.length <= 4 * 10^4
0 <= arr[i] <= 10^9

*/

/* Solution */

class Solution {
public:
  
    // Dynamic Programming Approach
    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
    
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n);
        
        dp[0]=1;
        
        if(n==1){
            return 1;
        }
        else if(n==2 && arr[0]!=arr[1]){
            //dp[1]=dp[0]+1;
            //return dp[1];
            return 2;
        }
        else if(n==2 && arr[0]==arr[1]){
            return 1;
        }
        
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                dp[i]=dp[i-1]+1;
            }
            else if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
                dp[i]=dp[i-1]+1;
            }
            else if(arr[i]==arr[i-1] && arr[i]==arr[i+1]){
                dp[i]=0;
            }
            else{
                dp[i]=1;
            }
            
        }
        
        //int maxi=*max_element(dp.begin(),dp.end());
        
        int maxi=INT_MIN;
        
        for(int i=1;i<n;i++){
            if(maxi<dp[i]){
                maxi=dp[i];
            }
        }
        return maxi+1;
    }
};
