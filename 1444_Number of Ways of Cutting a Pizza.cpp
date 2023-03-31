/*

Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

Example 1:

Input: pizza = ["A..","AAA","..."], k = 3
Output: 3 
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

Example 2:

Input: pizza = ["A..","AA.","..."], k = 3
Output: 1

Example 3:

Input: pizza = ["A..","A..","..."], k = 1
Output: 1
 
Constraints:

1 <= rows, cols <= 50
rows == pizza.length
cols == pizza[i].length
1 <= k <= 10
pizza consists of characters 'A' and '.' only.

*/

/* Solution */

class Solution {
    #define mod 1000000007
public:

    int dp[11][51][51];
    int dp_fun(int i,int j,int k,int r,int c,vector<vector<int>> &pref){

        if(pref[i][j]==0){
            return 0;
        }
        
        if(k==0){
            return 1;
        }

        if(dp[k][i][j]!=-1){
            return dp[k][i][j];
        }

        int res = 0;

        for(int z=i+1;z<r;z++){
            int diff = pref[i][j]-pref[z][j];
            if(diff > 0){
                res = (res + dp_fun(z,j,k-1,r,c,pref))%mod;
            }
        }

        for(int z=j+1;z<c;z++){
            int diff = pref[i][j]-pref[i][z];
            if(diff > 0){
                res = (res + dp_fun(i,z,k-1,r,c,pref))%mod;
            }
        }

        return dp[k][i][j] = res;;

    }
    int ways(vector<string>& pizza, int k) {
        int r=pizza.size(),c=pizza[0].size();
        
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> pref(r+1,vector<int> (c+1,0));
        
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(pizza[i][j]=='A'){
                    pref[i][j]=(1+pref[i][j+1]+pref[i+1][j]-pref[i+1][j+1]);
                }
                else{
                    pref[i][j]=(pref[i][j+1]+pref[i+1][j]-pref[i+1][j+1]);
                }
            }
        }

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<pref[i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }

        return dp_fun(0,0,k-1,r,c,pref);
    }
};
