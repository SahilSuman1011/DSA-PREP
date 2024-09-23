//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int> ans;
        unordered_map<int,int>mp;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(auto i:mp){
            if(i.second==2) ans.push_back(i.first);
        }
        for(int i=1;i<=n;i++){
            if(mp.find(i) == mp.end()) ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends