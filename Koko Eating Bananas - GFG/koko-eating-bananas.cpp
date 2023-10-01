//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int ans(vector<int> &piles,int charge)
    {
        int totaltime=0;
        for(int i=0;i<piles.size();i++)
        {
            totaltime+=ceil((double)piles[i]/ (double)charge);
        }
        
        // cout<<totaltime<<" ";
        return totaltime;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int l=1,h=*max_element(piles.begin(),piles.end());
        int res=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            // cout<<mid<<" ";
            int timetaken=ans(piles,mid);
            // cout<<timetaken<<" "<<endl;
            if(timetaken<=H)
            {
                res=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends