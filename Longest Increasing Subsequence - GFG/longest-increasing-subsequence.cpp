//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> x;
       x.push_back(a[0]);
       
       for(int i=1;i<n;i++)
       {
          if(a[i]>x.back())
          {
              x.push_back(a[i]);
          }
          else{
              int index=lower_bound(x.begin(),x.end(),a[i])-x.begin();
              x[index]=a[i];
          }
       }
       return x.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends