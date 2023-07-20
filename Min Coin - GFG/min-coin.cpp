//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int ind,vector<int> &nums,int amt, vector<vector<int>> &dp)
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
	int MinCoin(vector<int>nums, int amount)
	{
	    int n=nums.size();
	    vector<vector<int>> dp(n,vector<int> (amount+1,-1));
	   return (solve(n-1,nums,amount,dp)==1e9)?-1:solve(n-1,nums,amount,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends