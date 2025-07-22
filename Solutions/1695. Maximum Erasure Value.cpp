#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxScore = 0;
        int score = 0;
        int l = 0;

        unordered_set<int> seen;

        for (int r = 0; r < nums.size(); ++r) {
            while (seen.count(nums[r])) {
                seen.erase(nums[l]);
                score -= nums[l];
                ++l;
            }
            seen.insert(nums[r]);
            score += nums[r];
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};

int main() {
    vector<int> nums = {4, 2, 4, 5, 6};

    Solution s;
    cout << s.maximumUniqueSubarray(nums) << "\n";
    return 0;
}
