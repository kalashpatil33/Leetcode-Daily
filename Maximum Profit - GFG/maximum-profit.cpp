//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int N, int A[]) {
        int n=N;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));

        // for(int i=0;i<2;i++)
        // {
        //     for(int j=0;j<3;j++)
        //     {
        //         dp[n][i][j]=0;
        //     }
        // }


        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int z=1;z<=k;z++)
                {
                    if(j==0)
                    {
                        dp[i][j][z]=max(-A[i]+dp[i+1][1][z],dp[i+1][0][z]);
                    }
                    else{
                        dp[i][j][z]=max(A[i]+dp[i+1][0][z-1],dp[i+1][1][z]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends