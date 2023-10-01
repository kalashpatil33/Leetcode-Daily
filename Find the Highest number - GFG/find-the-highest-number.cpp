//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        // Code here.
        int n=arr.size();
         int l=0,h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])
            return arr[mid];
            if(arr[mid-1]<=arr[mid])
            l=mid+1;
            // if(arr[mid]>arr[h])else
            else
            h=mid-1;
        }
        return -1;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends