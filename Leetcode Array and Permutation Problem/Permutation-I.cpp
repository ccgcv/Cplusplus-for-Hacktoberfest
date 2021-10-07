class Solution
{
    vector<vector<int>> ans;

public:
    void permutation(vector<int> &nums, int idx)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            permutation(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        permutation(nums, 0);
        return ans;
    }
};