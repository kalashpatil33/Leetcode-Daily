//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool solve(int i,int j,vector<vector<char>> &m,string &w,int n,int x,int ind)
    {
        
        if(ind==w.size())
        return true;
        if(i>=n||j>=x||i<0||j<0||m[i][j]!=w[ind])
        {
            return false;
        }
        
        
        char ch=m[i][j];
        m[i][j]='*';
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        bool ans=false;
        for(int k=0;k<4;k++)
        {
            int nr=i+drow[k];
            int nc=j+dcol[k];
            
            ans=ans||solve(nr,nc,m,w,n,x,ind+1);
            
            
            if(ans==true)
            return true;
        }
        m[i][j]=ch;
        return ans;
    }
    bool wordSearch(vector<vector<char>>& m, string w) {
        //code here
        int n=m.size();
        int x=m[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(m[i][j]==w[0])
                {
                if(solve(i,j,m,w,n,x,0))
                return true;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> mat(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        string str; cin>>str;
        Solution ob;
        auto ans=ob.wordSearch(mat,str);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends