//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   static bool condition(pair<int,int>&p1,pair<int,int>&p2){
        return (p1.second==p2.second)?p1.first<p2.first :p1.second>p2.second;
    }
//CodeGenius

    vector<int> sortByFreq(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        
        vector<pair<int,int>>p(mp.begin(),mp.end());
        
        sort(p.begin(),p.end(),condition);
        
        vector<int> ans;
        
        for(pair<int,int>&temp :p){
           while(temp.second--) ans.push_back(temp.first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends