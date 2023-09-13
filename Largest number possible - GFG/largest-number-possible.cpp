//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        string ans;
        int x=9;
        while(N>0&&S>0)
        {
            if(S>=x)
            {
            ans.push_back(x+'0');
            S=S-x;
            N--;
            }
            else{
                x--;
            }
        }
        while(N!=0&&ans.size()!=0||N==1)
        {
            ans.push_back('0');
            N--;
        }
        // reverse(ans.begin(),ans.end());
        // cout<<S<<" "<<N<<" "<<ans;
        if(S!=0||N!=0)
        return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends