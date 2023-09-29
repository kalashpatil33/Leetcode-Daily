//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(vector<vector<int>> &grid,int i,int j,int n, int m)
    {
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0)
        return ;
        
        grid[i][j]=-1;
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        
        for(int k=0;k<4;k++)
        {
            int nr=i+drow[k]; 
            int nc=j+dcol[k];
            
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1)
            solve(grid,nr,nc,n,m);
            
        }
        // grid[i][j]=1;
    }
    
    bool isboundary(vector<vector<int>> &grid,int i,int j,int n,int m)
    {
        
            if(i==0||i==n-1||j==0||j==m-1)
            {
                return true;
            }
            else{
                return false;
            }
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isboundary(grid,i,j,n,m))
                {
                    if(grid[i][j]==1)
                    {
                        solve(grid,i,j,n,m);
                    }
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              if(grid[i][j]==1)
              {
                  c++;
              }
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends