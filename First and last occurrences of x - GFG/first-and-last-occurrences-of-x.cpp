//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int low=0,high=n-1;
        int firstindex=-1,lastindex=-1;
        int f=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]==x)
            {
                firstindex=mid;
                high=mid-1;
            }
            else if(arr[mid]<x)
            {
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        
         low=firstindex,high=n-1;
            while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]==x)
            {
                lastindex=mid;
                low=mid+1;
            }
            else if(arr[mid]<x)
            {
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        return {firstindex,lastindex};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends