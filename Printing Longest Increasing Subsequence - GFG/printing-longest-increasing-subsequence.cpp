//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastIndex=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(arr[i]>arr[prev])
                {
                    if(dp[prev]+1>dp[i])
                    {
                        dp[i]=dp[prev]+1;
                        // if(hash[i]!=i)
                        // {
                        // if(arr[hash[i]]>arr[prev])
                        // {
                        //     hash[i]=prev;
                        // }
                        // }
                        // else{
                                hash[i]=prev;
                                // lastIndex=prev;
                        // }
                    }
                }
            }
            if(dp[i]>maxi)
            {
               maxi=dp[i];
               lastIndex=i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex=hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends