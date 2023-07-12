//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,vector<vector<int>> &Matrix, vector<vector<int>> &dp,int N)
    {
        if(j<0||j>=N||i>=N)
        return 0;
        if(i==N-1)
        return dp[i][j]=Matrix[i][j];
        int left=0;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int same= Matrix[i][j]+solve(i+1,j,Matrix,dp,N);
        if(j>0)
        left=Matrix[i][j]+solve(i+1,j-1,Matrix,dp,N);
        int right=Matrix[i][j]+solve(i+1,j+1,Matrix,dp,N);
        
        return dp[i][j]=max(same,max(left,right));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        int maxi=-1e9;
        for(int j=0;j<N;j++)
         maxi=max(maxi,solve(0,j,Matrix,dp,N));
         return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends