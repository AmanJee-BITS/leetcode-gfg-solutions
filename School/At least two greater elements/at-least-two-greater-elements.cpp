//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<int> findElements(int a[], int n){
        set<int> s;
        int j=0;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            s.insert(a[i]);
        }
        
        for(auto x:s){
            if(j!=n-1 && j!=n-2){
                ans.push_back(x);
            }
            j++;
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
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        vector <int> res = ob.findElements(a,n);
        
        for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
        cout<<endl;
    }
}
// } Driver Code Ends