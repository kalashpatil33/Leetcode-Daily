//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int xr=0;
        for(int i=0;i<n;i++)
        {
            xr=xr xor arr[i];
            xr=xr xor (i+1);
        }
        
        int setbit= (xr & ~(xr-1));
        
        int zero=0,one=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] & setbit !=0)
            {
                one=one xor arr[i];
            }
            else{
                zero=zero xor arr[i];
            }
            
             if(((i+1) & setbit) !=0)
            {
                one=one xor (i+1);
            }
            else{
                zero=zero xor (i+1);
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(zero==arr[i])
            c++;
        }
        
        if(c==2)
        return {zero,one};
        return {one,zero};
        
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