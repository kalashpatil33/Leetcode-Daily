//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i=0,j=0;//The approach used here is sliding window.
        int ans=0;//We use this technique to
        long long curr=1;
        while(j<n)
        {
            
            curr*=a[j];   //we multiply the new element and go on till we are behind the target
            while(i<=j && curr>=k)
            {
                curr/=a[i]; //This is we are making new  window.
                i++;      
            }
            if(curr<k)
            ans+=j-i+1; //Then counting the subarrays
            j++;
           
        }
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends