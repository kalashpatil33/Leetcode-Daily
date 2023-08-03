//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
   int solve(int i,int j,string &a,string &s,vector<vector<int>> &dp)
   {
       if(i<0||j<0)
       return 0;
       
       if(dp[i][j]!=-1)
       return dp[i][j];
       
       if(a[i]==s[j])
       {
           return dp[i][j]=1+solve(i-1,j-1,a,s,dp);
       }
       else
       {
           return dp[i][j]=max(solve(i-1,j,a,s,dp),solve(i,j-1,a,s,dp));
       }
   }
    int longestPalinSubseq(string A) {
       string s=A;
       reverse(s.begin(),s.end());
       int n=A.size();
       vector<vector<int>> dp(n,vector<int>(n,-1));
       
       return solve(n-1,n-1,A,s,dp);
       
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends