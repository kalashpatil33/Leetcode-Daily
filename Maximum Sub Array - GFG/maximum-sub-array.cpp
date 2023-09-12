//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    
	    int ans=INT_MIN;
	    int sum=0;
	    int startIndex=-1,endIndex=-1;
	    int start=0;
	    for(int i=0;i<n;i++)
	    {
	        sum=sum+a[i];
	        if(a[i]<0)
	        {
	            sum=0;
	            start=i+1;
	            continue;
	        }
	        if(sum==0)
	        {
	            start=i;
	        }
	        
	         if(ans==sum)
	            {
	                if((i-start)>(endIndex-startIndex))
	                {
	                    endIndex=i;
	                    startIndex=start;
	                }
	            }
	        if(ans<sum)
	        {
	            endIndex=i;
	            startIndex=start;
	            ans=sum;
	        }
	    }
	        vector<int> res;
	        
	        for(int i=startIndex;i<=endIndex;i++)
	        {
	            res.push_back(a[i]);
	        }
	        return res;
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