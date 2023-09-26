//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        
        priority_queue<pair<int,pair<int,int>>> pq;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        vector<int> ans;
        for(int i=0;i<N;i++)
        {
            pq.push({A[i]+B[N-1],{i,N-1}});
        }
        
        while(K--)
        {
            auto it=pq.top();
            pq.pop();
            int sum=it.first;
            int index1=it.second.first;
            int index2=it.second.second;
            ans.push_back(sum);
            if(index2!=0)
            {
                pq.push({A[index1]+B[index2-1],{index1,index2-1}});
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends