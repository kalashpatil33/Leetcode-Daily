//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        long long solve(int i,vector<long long> &prices,int buy, vector<vector<long long>> &dp,int fee)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(dp[i][buy]!=-1)
        return dp[i][buy];
        int profit=0;

        if(buy==0){      //we can buy a stock
                profit=max(-prices[i]+solve(i+1,prices,1,dp,fee),0+solve(i+1,prices,0,dp,fee));
        }
        else{
            profit=max(prices[i]-fee+solve(i+1,prices,0,dp,fee),0+solve(i+1,prices,1,dp,fee));
        }
        return dp[i][buy]=profit;
    
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<vector<long long>> dp(n,vector<long long> (2,-1));
       
        return solve(0,prices,0,dp,fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends