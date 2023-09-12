//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int sum=0;
	    vector<int> ans;
	    int startind=-1,endind=n-1;
	    int maxi=INT_MIN;
	    int start=-1;
	    for(int i=0;i<n;i++)
	    {
	         if(sum<0||a[i]<0)
	        {
	           // endind=i+1;
	            sum=0;
	            continue;
	        }
	        if(sum==0)
	        {
	            start=i;
	        }
	        sum=sum+a[i];
	       
	        
	        if(sum>maxi)
	        {
	            maxi=sum;
	            endind=i;
	            startind=start;
	        }
	        else{
	            if(sum==maxi)
	            {
	               if(abs(i-start)>(endind-startind))
	               {
	                   startind=start;
	                   endind=i;
	               }
	            }
	        }
	    }
	    
	    for(int i=startind;i<=endind;i++)
	    {
	        ans.push_back(a[i]);
	    }
	    return ans;
	    
	}
};


//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends