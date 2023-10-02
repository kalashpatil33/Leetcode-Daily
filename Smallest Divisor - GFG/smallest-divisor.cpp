//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool solve(vector<int> &nums,int K,int mid)
    {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ans+=ceil(double (nums[i])/double(mid));
        }
        
        if(ans<=K)
        return true;
        // else
        return false;
    }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int n=nums.size();
        if(n>K)
        return -1;
        
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int l=1,h=maxi;
        int ans=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            bool ispossible=solve(nums,K,mid);
            if(ispossible)
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends