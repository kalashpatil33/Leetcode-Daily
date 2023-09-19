//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// The time complexity is O(2n)+ O(NlogN)
class Solution {
public:
    // static bool cmp(vector<int> &a,vector<int> &b)
    // {
    //     return a[1]<b[1];
    // }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(),intervals.end());
        //  cout<<intervals[0][0]<<" "<<intervals[0][1];
         vector<vector<int>> ans;
         int n=intervals.size();
         int j=0;
         int start=intervals[0][0];
         int end=intervals[0][1];
         for(int i=1;i<n;i++)
         {
            if(intervals[i][0]<=end)
            {
                end=max(end,intervals[i][1]);
            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
           
         }
         ans.push_back({start,end});
         return ans;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends