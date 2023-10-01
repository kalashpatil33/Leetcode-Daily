//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int k) 
    { 
    
       // Your code here
       long long l=0,r=N-1,m=0;
        while(l<=r)
        {
            m=(l+r)/2;
            if(arr[m]==k)
            return 1;
            // cout<<arr[m]<<endl;
                if(arr[m]<k)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return -1;
       
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends