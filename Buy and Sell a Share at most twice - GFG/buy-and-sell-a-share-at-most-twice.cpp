//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    int n=price.size();
    int k=2;
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
                        dp[i][j][z]=max(-price[i]+dp[i+1][1][z],dp[i+1][0][z]);
                    }
                    else{
                        dp[i][j][z]=max(price[i]+dp[i+1][0][z-1],dp[i+1][1][z]);
                    }
                }
            }
        }
        return dp[0][0][k];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends