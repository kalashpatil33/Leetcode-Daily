//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void solve(int i,vector<int> &A,int B, vector<vector<int>> &x,vector<int> &t,int sum)
    {
        if(i>=A.size()||sum==B)
        {
            if(sum==B)
            {
                // if(!x.empty())
                // {
                // vector<int> check=x.back();
                // if(check!=t)
                // x.push_back(t);
                // }
                // else
                x.push_back(t);
            }
            return ;
        }
        if(sum>B)
        return;
        
        while(i<A.size()-1&&A[i]==A[i+1])
        {
            i++;
        }
        if(i<A.size())
        {
        t.push_back(A[i]);
        solve(i,A,B,x,t,sum+A[i]);
        }
        t.pop_back();
        solve(i+1,A,B,x,t,sum);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        vector<vector<int>> ans;
        vector<int> t;
        solve(0,A,B,ans,t,0);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends