//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod=1e9+7;
    //Function to count number of ways to reach the nth stair.
    int solve(int n,vector<long long > &dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        else
        return (dp[n]=(solve(n-1,dp)%mod+solve(n-2,dp))%mod)%mod;
    }
    int countWays(int n)
    {
        vector<long long > dp(n+1,-1);
        dp[1]=1;
        dp[2]=2;
        return (solve(n,dp)%mod);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends