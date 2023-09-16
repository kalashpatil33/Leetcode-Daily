//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1000000007;
    long long solve(int n, vector<long long> &dp)
   {
       if(n==1||n==0)
       {
           return 1;
       }
       
       if(dp[n]!=-1)
       return dp[n];
       long long threejump=0,twojump=0,onejump=0;
       if(n>=3)
       {
           threejump=solve(n-3,dp);
        //   twojump=solve(n-2,dp);
        //   onejump=solve(n-1,dp);
       }
       if(n>=2)
       {
           twojump=solve(n-2,dp);
            // onejump=solve(n-1,dp);
           
       }
       if(n>=1)
       {
           onejump=solve(n-1,dp);
       }
       
       return dp[n]=(onejump+twojump+threejump)%mod;
   }
    long long countWays(int n)
    {
        vector<long long> dp(n+1,-1);
        return solve(n,dp)%mod;
        // your code here
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends