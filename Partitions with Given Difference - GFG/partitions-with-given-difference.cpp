//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int mod=1e9+7;
    int solve(int ind,vector<int> &arr,int sum,vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(sum==0 && arr[0]==0)
            return dp[ind][sum]=2;
            if(sum==arr[0]||sum==0)
            return dp[ind][sum]=1;
            
            return dp[ind][sum]=0;
        }
         
        int pick=0,notpick=0;
        
        if(dp[ind][sum]!=-1)
        return dp[ind][sum];
        if(arr[ind]<=sum)
        pick=(solve(ind-1,arr,sum-arr[ind],dp))%mod;
        
        notpick=(solve(ind-1,arr,sum,dp))%mod;
        
        return dp[ind][sum]=(pick+notpick)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
       int sum=0;
       for(auto &it:arr) sum+=it;
       vector<vector<int>> dp(n,vector<int> (sum,-1));
       
       if(sum-d<0 || (sum-d)%2) return false;
       
       return solve(n-1,arr,(sum-d)/2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends