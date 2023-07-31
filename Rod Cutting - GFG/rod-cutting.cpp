//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int i,int price[],int n)
    {
        if(i==0)
        {
            return (n)*price[0];
        }
        
        int pick=INT_MIN,notpick=INT_MIN;
        
        if((i+1)<=n)
        {
            pick=price[i]+solve(i,price,n-(i+1));
        }
        notpick=solve(i-1,price,n);
        
        return max(pick,notpick);
    }
    int cutRod(int price[], int n) {
        
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=i*price[0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=n;j++)
            {
        int pick=INT_MIN,notpick=INT_MIN;
        
        if((i+1)<=j)
        {
            pick=price[i]+dp[i][j-(i+1)];
        }
        notpick=dp[i-1][j];
        
        dp[i][j]= max(pick,notpick);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends