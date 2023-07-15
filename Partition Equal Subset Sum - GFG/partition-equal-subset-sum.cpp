//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int i,int arr[],int sum,int N,vector<vector<int>> &dp)
    {
        if(sum==0)
        return dp[i][sum]=true;
        if(i==N-1)
        {
           return dp[i][sum]=(sum==arr[N-1]);
        }
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        bool pick=false;
        if(arr[i]<=sum)
        pick=solve(i+1,arr,sum-arr[i],N,dp);
        bool notpick=solve(i+1,arr,sum,N,dp);
        
        return dp[i][sum]= pick | notpick;
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
       for(int i=0;i<N;i++)
       {
           sum+=arr[i];
       }
       if(sum%2==1)
       return false;
       else
       {
       sum=sum/2;
       vector<vector<int>> dp(N,vector<int> (sum+1,-1));
       return solve(0,arr,sum,N,dp);
       }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends