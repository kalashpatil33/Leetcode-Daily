//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        long long s=0,s2=0;
        long long sn=0,s2n=0;
        
        for(int i=0;i<n;i++)
        {
            s=s+arr[i];
            s2=s2+(long long)(arr[i])*(long long)(arr[i]);
        }
        
        sn= ((long long)n*(n+1))/2;
        s2n=(sn*(2*n+1))/3;
        
        long long x=sn-s;
        long long y=s2n-s2;
        
        long long missing= (y/x);
        missing= (missing+(x))/2;
        long long repeating= missing-(int)(x);
        
        return {(int)repeating,(int)missing};
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends