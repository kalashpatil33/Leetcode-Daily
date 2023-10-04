//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
     bool solve(int arr[],long long target,int k,int n)
     {
         int c=1;
         int sum=0;
         for(int i=0;i<n;i++)
         {
             if(arr[i]+sum<=target)
             {
                 sum=sum+arr[i];
             }
             else{
                 c++;
                 sum=arr[i];
             }
         }
         
         return (c<=k);
     }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long l=0,h=0;
        long long ans=1e9;
        for(int i=0;i<n;i++)
        {
            h=h+arr[i];
            l=max((int)l,arr[i]);
        }
        
        while(l<=h)
        {
            long long mid=(l+h)/2;
            
            bool ispossible = solve(arr,mid,k,n);
            
            if(ispossible)
            {
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return l;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends