//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        
         int n = nums.size();
        int can1 = INT_MIN, can2 = INT_MIN;
        int counter1 = 0, counter2 = 0;

        // Step 1: Finding two candidates
        for (int i = 0; i < n; i++) {
            if (nums[i] == can1) {
                counter1++;
            } else if (nums[i] == can2) {
                counter2++;
            } else if (counter1 == 0) {
                can1 = nums[i];
                counter1 = 1;
            } else if (counter2 == 0) {
                can2 = nums[i];
                counter2 = 1;
            } else {
                counter1--;
                counter2--;
            }
        }

        // Step 2: Counting votes for the candidates
        int vote1 = 0, vote2 = 0;
        for (int x : nums) {
            if (x == can1) vote1++;
            else if (x == can2) vote2++;
        }

        // Step 3: Prepare the result
        vector<int> ans;
        if (vote1 > n / 3) ans.push_back(can1);
        if (vote2 > n / 3) ans.push_back(can2);

        // If no majority element found
        if (ans.empty()) ans.push_back(-1);

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends