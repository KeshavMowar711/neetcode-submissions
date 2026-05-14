
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // STEP 1: Count frequency
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        // STEP 2: Create buckets
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto it : count) {
            int num = it.first;
            int freq = it.second;
            buckets[freq].push_back(num);
        }

        // STEP 3: Collect top k frequent elements
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }

        return result;
    }
};
