class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                v.push_back(i);
            }
        }

        if (v.size() == 0) {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        else if (v.size() == 1) {
            v.push_back(v[0]);
            return v;
        }
        else if (v.size() > 2) {
            int n = v.size();
            vector<int>v1;
            v1.push_back(v[0]);
            v1.push_back(v[n - 1]);
            return v1;
        }
        return v;
    }
};