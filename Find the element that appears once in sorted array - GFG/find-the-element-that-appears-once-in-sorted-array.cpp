//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        if(n==1)
        return arr[0];
        
        if(arr[0]!=arr[1])
        return arr[0];
        
        if(arr[n-1]!=arr[n-2])
        return arr[n-1];

        int l=1,h=n-2;             //eliminating the extra conditions we handled them additionally above
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1])
            return arr[mid];
            if((mid%2==0 and arr[mid]==arr[mid+1]) or (mid%2==1 and arr[mid]==arr[mid-1])) //odd eevn pattern
            {
                l=mid+1;              //element is in right half
            }
            else{
                h=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends