//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> A, int key) {
    //code here
    int l=0,h=A.size()-1;
     while(l<=h)
        {
            int m=(l+h)/2;
            
            
            if(A[m]==key)
            return m;
            if(A[m]>=A[l])
            {
              if(key>=A[l]&&key<=A[m])
              {
                  h=m-1;
              }
              else
              l=m+1;
            }
            else{
                if(key<=A[h]&&key>=A[m])
                {
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
        }
        
        return -1;
}