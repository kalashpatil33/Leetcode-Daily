//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int ind,int nums[],int amt, vector<vector<int>> &dp)
	{
	    if(ind==0)
	    {
	        if(amt%nums[0]==0)
	        return dp[ind][amt]=amt/nums[0];
	        else
	        return dp[ind][amt]=1e9;
	    }
	    if(dp[ind][amt]!=-1)
	    {
	        return dp[ind][amt];
	    }
	    int pick=1e9,notpick=1e9;
	    
	    if(nums[ind]<=amt)
	    pick=1+solve(ind,nums,amt-nums[ind],dp);
	    
	    notpick=0+solve(ind-1,nums,amt,dp);
	    
	    return dp[ind][amt]=min(pick,notpick);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M,vector<int> (V+1,-1));
	   return (solve(M-1,coins,V,dp)==1e9)?-1:solve(M-1,coins,V,dp);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends