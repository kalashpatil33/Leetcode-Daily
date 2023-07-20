//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M,vector<int> (V+1,1e9));
	    
	    for(int i=0;i<=V;i++)
	    {
	        if(i%coins[0]==0)
	        {
	            dp[0][i]=i/coins[0];
	        }
	    }
	    
	    for(int i=1;i<M;i++)
	    {
	        for(int j=0;j<=V;j++)
	        {
	   int pick=1e9,notpick=1e9;
	    
	    if(coins[i]<=j)
	    pick=1 + dp[i][j-coins[i]];
	    
	    notpick=0+dp[i-1][j];
	    
	    dp[i][j]=min(pick,notpick);
	        }
	    }
	    
	    if(dp[M-1][V]==1e9)
	    return -1;
	    else
	    return dp[M-1][V];
    
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