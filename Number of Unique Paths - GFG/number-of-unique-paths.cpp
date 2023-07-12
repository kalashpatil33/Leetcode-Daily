//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    //Solving in a most optimized way
    int NumberOfPath(int a, int b)
    {
       vector<int> prev(b,0);
       for(int i=0;i<a;i++)
       {
           vector<int> temp(b,0);
           for(int j=0;j<b;j++)
           {
               if(i==0&&j==0)
               temp[j]=1;
               else
               temp[j]=prev[j]+temp[j-1];
           }
           prev=temp;
       }
       return prev[b-1];
    }
    // Space used is o(1) and time as said O(a*b)
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends