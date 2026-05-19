
   class Solution {
public:

    void solve(
        vector<int>& candidates,
        int target,
        int index,
        vector<int>& path,
        vector<vector<int>>& ans)
    {
        // target achieved
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }

        // out of bounds
        if(index == candidates.size())
            return;

        // target exceeded
        if(target < 0)
            return;

        // TAKE current number
        path.push_back(candidates[index]);

        solve(
            candidates,
            target - candidates[index],
            index,
            path,
            ans
        );

        // BACKTRACK
        path.pop_back();

        // SKIP current number
        solve(
            candidates,
            target,
            index + 1,
            path,
            ans
        );
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target)
    {
        vector<vector<int>> ans;

        vector<int> path;

        solve(
            candidates,
            target,
            0,
            path,
            ans
        );

        return ans;
    }
};