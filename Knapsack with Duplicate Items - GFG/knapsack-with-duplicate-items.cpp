//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //  int solve(int i,int val[],int wt[],int W)
    //  {
    //      if(i==0)
    //      {
    //         return (int)(W/wt[0])*val[0];
    //       }
         
         
    //      int pick=INT_MIN,notpick=0;
    //      if(wt[i]<=W)
    //      {
    //          pick=val[i]+solve(i,val,wt,W-wt[i]);
    //      }
    //      notpick=solve(i-1,val,wt,W);
         
    //      return max(pick,notpick);
    //  }
    int knapSack(int N, int W, int val[], int wt[])
    {
    vector<vector<int>> dp(N,vector<int>(W+1,0));
     
     
       for(int i=wt[0];i<=W;i++)
       {
           dp[0][i]=(i/wt[0])*val[0];
       }
       
       for(int i=1;i<N;i++)
       {
           for(int j=0;j<=W;j++)
           {
               int pick=INT_MIN,notpick=0;
         if(wt[i]<=j)
         {
             pick=val[i]+dp[i][j-wt[i]];
         }
         notpick=dp[i-1][j];
         
         dp[i][j]=max(pick,notpick);
           }
       }
       return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends