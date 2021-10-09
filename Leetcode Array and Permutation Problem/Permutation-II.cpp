class Solution {
        vector<vector<int>>ans;
public:
    void permutation(vector<int>&nums,int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            permutation(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
        // return ans;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         permutation(nums,0);
        set<vector<int>>s;
        for(int i=0;i<ans.size();i++){
            s.insert(ans[i]);
        }
        vector<vector<int>>v;
        for(auto val:s){
            v.push_back(val);
        }
        return v;
    }
};