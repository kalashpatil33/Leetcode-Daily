//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    long long nearestPower(long long N , long long M) {
        // code here
        long long ans=1;
        while(ans<N)
        {
            ans=ans*M;
        }
        
        long long x=abs(N-ans);
        long long y=abs(N-ans/M);
        
        if(x>y)
        return ans/M;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.nearestPower(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends