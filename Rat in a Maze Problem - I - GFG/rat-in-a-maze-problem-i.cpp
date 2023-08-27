//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void solve(int i,int j,vector<vector<int>> &a,int n,string &t)
    {
        if(i<0||j<0||i>=n||j>=n||a[i][j]==0)
        return ;
        
        if(i==n-1&&j==n-1)
        {
            ans.push_back(t);
            return ;
        }
        a[i][j]=0;
        t.push_back('U');
        solve(i-1,j,a,n,t);
        t.pop_back();
        t.push_back('D');
        solve(i+1,j,a,n,t);
        t.pop_back();
        t.push_back('L');
        solve(i,j-1,a,n,t);
        t.pop_back();
        t.push_back('R');
        solve(i,j+1,a,n,t);
        t.pop_back();
        a[i][j]=1;
        return ;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0||m[n-1][n-1]==0)
        return {"-1"};
        string t;
        solve(0,0,m,n,t);
        if(ans.size()==0)
        return {"-1"};
        else
        return ans;
    }
    
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends