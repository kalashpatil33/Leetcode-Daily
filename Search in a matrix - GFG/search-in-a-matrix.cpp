//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &matrix, int n, int m, int X)
	{
	    // your code here
	   //int n=matr.size();
    //     int m=mat[0].size();

       int row=0,col=m-1;
       
       while(row<n&&col>=0)
       {
           if(matrix[row][col]==X)
           return true;
           
           if(matrix[row][col]<X)
           {
               row++;
           }
           else
           col--;
       }
        return 0;
	}
};


//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends