//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
    void solve(int i,vector<int> &candidates,int target,vector<int> &t,vector<vector<int>> &ans)
    {
        if(i==candidates.size()||target==0)
        {
            if(target==0)
            {
                ans.push_back(t);
            }
            
            return;
        }
        
       
        if(candidates[i]<=target)
        {
        t.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],t,ans);
        t.pop_back();
        }
          while(i<candidates.size()-1&&candidates[i]==candidates[i+1])
        {
            i++;
        }
        solve(i+1,candidates,target,t,ans);
        // t.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> t;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
       solve(0,candidates,target,t,ans);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends