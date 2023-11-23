//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long countSubarray(int n,vector<int> A,long long L,long long R) {
        // code here
        long long lcount=0,rcount=0,sum=0;
        
        int i=0,j=0;
        while(j<n)
        {
            sum+=A[j];
            while(sum>(L-1))
            {
                sum-=A[i];
                i++;
            }
            lcount+=(j-i+1);
            j++;
        }
        i=0,j=0,sum=0;
        while(j<n)
        {
            sum+=A[j];
            while(sum>R)
            {
                sum-=A[i];
                i++;
            }
            rcount+=(j-i+1);
            j++;
        }
        
        return rcount-lcount;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends