//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    vector<vector<bool>> dp(n,vector<bool> (sum+1,false));
	    for(int i=0;i<n;i++)
	    {
	        dp[i][0]=true;
	        
	    }
	    if(arr[0]<=sum)
	   dp[0][arr[0]]=(true);
	    int ans=1e9;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            
	            bool pick=false;
	            if(arr[i]<=j)
	            {
	                pick=dp[i-1][j-arr[i]];
	            }
	            bool notpick=dp[i-1][j];
	            
	            
	            dp[i][j]=pick or notpick;
	            
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(dp[i][j]==true)
	            {
	                ans=min(ans,abs(sum-2*j));
	            }
	        }
	    }
	    return ans;
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends