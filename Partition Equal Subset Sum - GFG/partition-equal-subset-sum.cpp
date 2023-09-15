//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int i,int arr[],int sum,int n,vector<vector<int>> &dp)
    {
        if(i>n)
        return false;
        if(i==n)
        {
            if(sum==0)
            return true;
            else
            return false;
        }
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        bool pick=false,notpick=false;
        if(arr[i]<=sum)
        {
            pick=solve(i+1,arr,sum-arr[i],n,dp);
        }
        notpick=solve(i+1,arr,sum,n,dp);
        
        return dp[i][sum]=pick||notpick;
       
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        sum=sum/2;
        vector<vector<int>> dp(N+1,vector<int> (sum+1,-1));
      return  solve(0,arr,sum,N,dp);
    };
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