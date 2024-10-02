class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
         map<int,int> mp;
         for(auto& val : a){
            mp[val]++;
         }

         int rank = 1;
         for(auto& val:mp) {
            val.second = rank;
            rank++;
         }

         vector<int> ans(a.size());
         for(int i=0;i<a.size();i++){
            ans[i] = mp[a[i]];
         }
         return ans;
    }
};