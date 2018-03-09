class Solution {
public:
    /*
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        int numsSize = nums.size();
        double maxSum = 0;
        double currentSum = 0;
        for (int i = 0; i < k; i ++) {
           currentSum += nums[i]; 
        }
        maxSum = currentSum;
        for (int i = k; i < numsSize; i++) {
            currentSum += nums[i] - nums[i-k];
            maxSum = max(currentSum,maxSum);
        }
        return maxSum/k;
    }
};
