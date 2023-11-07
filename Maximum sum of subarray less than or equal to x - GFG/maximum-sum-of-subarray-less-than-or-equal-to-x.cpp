//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long k)
	{
	    long long ans=0;
	    long long sum=0;
	    int cnt=0;
	    for(int i=0;i<n;i++)
	    {
	        if(sum+arr[i]<=k)
	        {
	            sum+=arr[i];
	            cnt++;
	        }
	        else{
	            sum+=arr[i];
	            cnt++;
	            
	            while(sum>k)
	            {
	                sum-=arr[i-cnt+1];
	                cnt--;
	            }
	            
	        }
	            ans=max(ans,sum);
	    }
	    
	    return (int)ans;
	
	}  

		 

};
	  



//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends