//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int position=N;
        int l=0,h=N-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(Arr[mid]==k)
            {
                return mid;
            }
            
            if(Arr[mid]<k)
            {
                l=mid+1;
            }
            else
            {
                position=mid;
                h=mid-1;
            }
        }
    return position;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends