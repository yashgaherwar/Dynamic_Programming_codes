/*

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 109
All the values of arr are unique.

*/

/* Solution */


// Dynamic Programming and Map Approach
// Time Complexity:- O(N*N)
// Space Complexity:- O(N)


// Note:- In this Problem we need to calculate the factors of each numbers(which is  nothing but the leaf nodes) and checking whether its product is is equal to the values of the nodes or not. Also we need to use unordered map for storing the current values(No. of Binary trees obtained).

class Solution {
public:
    #define ll long long
    #define mod 1000000007
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        // Map for checking whether the factors are present or not.
        unordered_map<ll,ll> mp;
        
        ll res=0;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++){
            
            // Curr value should be 1 i.e. Leaf Node
            ll curr = 1;
            
            for(int j=0;j<i;j++){
                
                if((arr[i]%arr[j])>0){
                    continue;
                }
                
                ll n1 = arr[j], n2 = arr[i]/arr[j];
                
                curr = (curr + (mp[n1]*mp[n2])%mod)%mod;
            }
            
            //Updating the map
            
            mp[arr[i]] = curr;
            
            // Storing the number of binary trees obtained in a variable
            res = (res+curr)%mod;
        }
        
        
        //Returning the number of binary trees we can make 
        
        return (int)res;
    }
};
