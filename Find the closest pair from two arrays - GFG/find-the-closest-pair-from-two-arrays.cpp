//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        
        int i=n-1,j=0;
        int diff=INT_MAX;
        vector<int> ans(2,0);
        while(i>=0 && j< m)
        {
            if(abs(arr[i]+brr[j]-x)<diff)
            {
                ans[0]=arr[i];
                ans[1]=brr[j];
                
                diff=abs(arr[i]+brr[j]-x);
            }
            
            if(arr[i]+brr[j]<x)
            {
                j++;
            }
            else{
                i--;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends