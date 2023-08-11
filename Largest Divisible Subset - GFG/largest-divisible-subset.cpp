//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& nums) {
        vector<int> dp(n,1);
        vector<int> hash(n);
        sort(nums.begin(),nums.end());
        int lastIndex=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
               {
                   if(nums[i]%nums[j]==0)
                   {
                       if(dp[j]+1>dp[i])
                       {
                           dp[i]=dp[j]+1;
                           hash[i]=j;
                       }
                   }
                   if(dp[i]>maxi)
                   {
                       maxi=dp[i];
                       lastIndex=i;
                   }
               }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends