//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    int mod=1e9+7;
  public:
    long long int numberOfPaths(int m, int n){
        vector<int> prev(n,0);
       for(int i=0;i<m;i++)
       {
           vector<int> temp(n,0);
           for(int j=0;j<n;j++)
           {
               if(i==0&&j==0)
               temp[j]=1;
               else
               temp[j]=(prev[j]+temp[j-1])%mod;
           }
           prev=temp;
       }
       return prev[n-1]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends