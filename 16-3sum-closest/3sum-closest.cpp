#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // ans ko bahar initialize karo
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }

                if (sum == target) {
                    return sum;
                } 
                else if (sum > target) {
                    right--;
                } 
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};
