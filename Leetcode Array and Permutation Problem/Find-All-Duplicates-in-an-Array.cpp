class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int>m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        vector<int>v;
        for (auto val : m) {
            if (val.second > 1) {
                v.push_back(val.first);
            }
        }
        return v;
    }
};