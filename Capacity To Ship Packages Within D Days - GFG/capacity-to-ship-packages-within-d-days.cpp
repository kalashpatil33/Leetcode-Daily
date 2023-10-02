//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool ispossible(int arr[],int D,int weight,int N)
    {
        int c=0,d=1;
        for(int i=0;i<N;i++)
        {
            
            if((c+arr[i])>weight)
            {
                d++;
                c=arr[i];
                // i--;
            }
            else{
                c=c+arr[i];
            }
        }
    //   d+=ceil ((double)c/(double) weight);
        if(d<=D)
        return true;
        return false;
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int h=accumulate(arr,arr+N,0);
        int l=*max_element(arr,arr+N);
        int ans=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            bool check=ispossible(arr,D,mid,N);
            
            if(check)
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends