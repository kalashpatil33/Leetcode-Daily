//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
       vector<bool> prev(sum+1,false);
       prev[0]=true;
        if(arr[0]<=sum)
        prev[arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            vector<bool> curr(sum+1,false);
            for(int j=1;j<=sum;j++)
            {
                bool pick=false;
                if(arr[i]<=j)
                pick=prev[j-arr[i]];
                bool notpick=prev[j];
                
                curr[j]=pick or notpick;
            }
            prev=curr;
        }
        return prev[sum];
    }
};

// This is space optimization with time complexity as O(n*target) and space is also O(target)

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends