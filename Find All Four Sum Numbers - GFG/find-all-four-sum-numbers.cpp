//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        // Your code goes here
        
        
        int n=arr.size();
         vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(i>0&&(arr[i]==arr[i-1]))
            continue;
            for(int j=i+1;j<n;j++)
            {
                if(j!=(i+1)&&(arr[j]==arr[j-1]))   //neither the first nor matching
                continue;
                long long sum=arr[i]+arr[j];
                int l=j+1,h=n-1;
                while(l<h)
                {
                    if(sum+arr[l]+arr[h]==k)
                    {
                        ans.push_back({arr[i],arr[j],arr[l],arr[h]});
                        l++;
                        h--;
                        while(l<h && arr[l]==arr[l-1]) l++;
                        while(l<h && arr[h]==arr[h+1]) h--;
                    }
                    else{
                    if(sum+arr[l]+arr[h]<k)
                        {
                            l++;
                        }
                        else{
                            h--;
                        }
                    }
                }
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends