//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &Arr , int N){
        // code here 
        int i=0,j=0; 
        long long ans=0,sum=0;
        while(i<N && j<N)
        {
            if((j-i)<k)
            {
                while(j<N &&(j-i)<k) {
                    sum+=Arr[j];
                    j++;
                }
            }
            else{
                sum-=Arr[i];
                i++;
            }
            if((j-i)==k)
                ans=max(ans,sum);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends