//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int n,int x,int m)
	{
	    long long val=1;
	    int i=1;
	    while(i<=n)
	    {
	    val=val*x;
	    if(val>m)
	    return 2;
	    i++;
	    }
	   if(val==m)
	    return 1;
	    return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int l=1,h=m;
	    while(l<=h)
	    {
	        int mid=(l+h)/2;
	        int value=solve(n,mid,m);
	        
	       // cout<<l<<" "<<mid<<" "<<value<<endl;
	        if(value == 1)
	        return mid;
	        
	        if(value == 0)
	        {
	           // cout<<mid<<" "<<l<<endl;
	            l=mid+1;
	        }
	        else{
	            h=mid-1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends