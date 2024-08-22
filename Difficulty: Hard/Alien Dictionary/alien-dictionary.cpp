//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

 #include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string findOrder(string dict[], int n, int k) {
        // Step 1: Build the graph
        unordered_map<char, unordered_set<char>> adjList;
        unordered_map<char, int> indegree;
        
        // Initialize the indegree map for all characters
        for (int i = 0; i < k; ++i) {
            indegree[char('a' + i)] = 0;
        }
        
        // Step 2: Create the adjacency list and indegree count
        for (int i = 0; i < n - 1; ++i) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int len1 = word1.length(), len2 = word2.length();
            int minLen = min(len1, len2);
            
            for (int j = 0; j < minLen; ++j) {
                if (word1[j] != word2[j]) {
                    if (adjList[word1[j]].find(word2[j]) == adjList[word1[j]].end()) {
                        adjList[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
            }
        }
        
        // Step 3: Perform Topological Sort using Kahn's Algorithm
        queue<char> q;
        string result;
        
        // Enqueue nodes with zero indegree
        for (auto &pair : indegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }
        
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            result += node;
            
            for (char neighbor : adjList[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Check if all characters were processed
        if (result.length() != k) {
            return ""; // Cycle detected or not all characters are included
        }
        
        return result;
    }
};


//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends