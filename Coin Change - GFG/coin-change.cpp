//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9;
    long long int count(int coins[], int N, int sum) {

        vector<vector<long long int>> dp(N,vector<long long int> (sum+1,0));
	    
	    for(long long int i=0;i<=sum;i++)
	    {
	        if(i%coins[0]==0)
	        {
	            dp[0][i]=1;
	        }
	    }
	    
	    for(long long i=1;i<N;i++)
	    {
	        for(long long j=0;j<=sum;j++)
	        {
	   long long pick=0,notpick=0;
	    
	    if(coins[i]<=j)
	    pick= dp[i][j-coins[i]];
	    
	    notpick= dp[i-1][j];
	    
	    dp[i][j]=(pick+notpick);
	        }
	    }
	    
	    return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends