//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
    long long solve(long long x,long long y)
    {
        if(x==0)
        return 0;
        x=x%mod;
        long long res=1;
        while(y>0)
        {
            if(y%2!=0)
            {
                res=(res*x)%mod;
            }
            y=y/2;
            x=(x*x)%mod;
        }
        return res;
    }
    int countGoodNumbers(long long N) {
       long long count_4=N/2;
       long long count_5=N-count_4;
       
       return (solve(4,count_4)%mod*solve(5,count_5)%mod)%mod;
    };
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    }
}
// } Driver Code Ends