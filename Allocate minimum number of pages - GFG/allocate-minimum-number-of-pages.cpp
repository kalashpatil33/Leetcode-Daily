//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int solve(int A[],int N,int pages)
    {
        int c=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if((sum+A[i])>pages)
            {
                c++;
                sum=A[i];
            }
            else{
                sum+=A[i];
            }
        }
        
        return c;
    }
    int findPages(int A[], int N, int M) 
    {
        
        if(M>N)
        return -1;
        //code here
        int l=*max_element(A,A+N);
        int h=0;
         for(int i=0;i<N;i++)
          h=h+A[i];
          
        //   cout<<l<<" "<<h<<endl;
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int students=solve(A,N,mid);
            
            // if(students==M)
            // return mid;
            if(students>M)
            {
                l=mid+1;
                ans=mid;
            }
            else{
                h=mid-1;
            }
        }
        
        return l;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends