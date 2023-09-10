//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    
	    vector<int> rem(x+1,0);
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<x)
	         {
	             rem[arr[i]%x]++;
	         }
	    }
	    int i;
	    for(i=0;i<x/2;i++)
	    {
	        if(rem[i]>0&rem[x-i]>0)
	        return true;
	    }
	    
	    if(i>=x/2)
	    {
	        if(x%2==0)
	        {
	            if(rem[x/2]>1)
	            return true;
	        }
	        else{
	            if(rem[x/2]>0&&rem[x-x/2]>0)
	            return true;
	        }
	    }
	    
	   // cout<<"hi";
	    return false;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends