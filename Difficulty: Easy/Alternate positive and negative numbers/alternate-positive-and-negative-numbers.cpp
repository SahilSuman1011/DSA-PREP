//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // Separate positive and negative numbers
        vector<int> neg, pos, ans;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= 0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        
        int i = 0, j = 0, k = 0;
        
        // Alternate between positive and negative numbers
        while(i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        
        // Add remaining positive numbers if any
        while(i < pos.size()) {
            ans.push_back(pos[i++]);  // corrected i++
        }
        
        // Add remaining negative numbers if any
        while(j < neg.size()) {
            ans.push_back(neg[j++]);
        }

        // Update the original array with rearranged elements
        arr = ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends