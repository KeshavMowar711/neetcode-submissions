class Solution {
public:
    int lengthOfLIS(vector<int>& arr) 
    {
         int n = arr.size();
    vector<int> dp(n, 1);


    for (int i = 1; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] > arr[prev]) {
                dp[i] = max(dp[i], dp[prev] + 1);
            }
        }
    }

    // Return maximum value in lis
    return *max_element(dp.begin(), dp.end());
        
    }
};
