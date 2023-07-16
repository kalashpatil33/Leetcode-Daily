//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int solve(int i,int arr[],int n,int sum,int target,vector<vector<int>> &dp)
	{
	     if(i>n-1)
	    {
	        if(sum==target)
	         return 1;
	        else
	        return 0;
	    }
	       // if(sum==target)
	       // return 1;
	       if(dp[i][sum]!=-1)
	       {
	           return dp[i][sum];
	       }
	   
	     int pick=0,notpick=0;
	     if(arr[i]+sum<=target)
	     pick=solve(i+1,arr,n,sum+arr[i],target,dp);
	     notpick=solve(i+1,arr,n,sum,target,dp);
	     
	     return dp[i][sum]=(pick+notpick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return (solve(0,arr,n,0,sum,dp)%mod);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends