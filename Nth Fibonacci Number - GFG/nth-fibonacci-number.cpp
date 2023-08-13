//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    int mod=1e9+7;
  public:
    int fib(int n,vector<int> &dp)
    {
        if(dp[n]!=-1)
        return dp[n];
        if(n<=2)
        return n-1;
        
        return dp[n]=(fib(n-1,dp)+fib(n-2,dp))%mod;
    }
    int nthFibonacci(int n){
        // code here
        vector<int> dp(n+2,-1);
        return fib(n+1,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends