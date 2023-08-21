//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  
   void solve(int i,vector<int> &nums,vector<vector<int>> &ans,vector<int> t)
   {
       if(i==nums.size())
       {
           ans.push_back(t);
           return;
       }
       
  
       t.push_back(nums[i]);
       solve(i+1,nums,ans,t);
       t.pop_back();
       
    while(i<nums.size()-1&&nums[i]==nums[i+1])
      {
          i++;
      }
       
       solve(i+1,nums,ans,t);
   }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> t;
       sort(nums.begin(),nums.end());
       solve(0,nums,ans,t);
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends