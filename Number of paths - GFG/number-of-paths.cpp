//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    // int mod=1e9+7;
    vector<int> prev(n,0);
       for(int i=0;i<m;i++)
       {
           vector<int> temp(n,0);
           for(int j=0;j<n;j++)
           {
               if(i==0&&j==0)
               temp[j]=1;
               else
              temp[j]=(prev[j]+temp[j-1]);
           }
           prev=temp;
       }
       return prev[n-1];
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends