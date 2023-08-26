//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool solve(int i,int j,int k,string &A,string &B,string &C,vector<vector<int>> &dp)
    {
        if(k==C.size())
        {
            return dp[i][j]=true;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        // dp[i][j]=
        if(i<A.size()&&A[i]==C[k]&&j<B.size()&&B[j]==C[k])
        {
            return dp[i][j]=solve(i+1,j,k+1,A,B,C,dp)||solve(i,j+1,k+1,A,B,C,dp);
        }
        
        if(i<A.size()&&A[i]==C[k])
        return dp[i][j]=solve(i+1,j,k+1,A,B,C,dp);
        
        if(j<B.size()&&B[j]==C[k])
        return dp[i][j]=solve(i,j+1,k+1,A,B,C,dp);
        
        return dp[i][j]=false;
    }
    bool isInterleave(string A, string B, string C) 
    {
        int n=A.size();
        int m=B.size();
        int p=C.size();
        if(n+m!=p)
        return false;
        
        if(A+B==C)
        return true;
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        return solve(0,0,0,A,B,C,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends