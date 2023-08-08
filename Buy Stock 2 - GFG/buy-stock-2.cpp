//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        //  int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int> (2,-1));
        vector<long long> next(2),curr(2);
        next[0]=0;
        next[1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j==0)
                {
                curr[j]=max(-prices[i]+next[1],next[0]);
                }
                else{
                curr[j]=max(prices[i]+next[0],next[1]);
                }
            }
            next=curr;
        }
        return next[0];
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
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends