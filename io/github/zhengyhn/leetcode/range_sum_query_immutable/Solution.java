package io.github.zhengyhn.leetcode.range_sum_query_immutable;

public class Solution {
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray obj = new NumArray(nums);
     * int param_1 = obj.sumRange(i,j);
     */

    public static void main(String[] args) {
        NumArray numArray = new NumArray(new int[]{-2, 0, 3, -5, 2, -1});
        System.out.println(numArray.sumRange(2, 5));
    }

    public static class NumArray {
        private int[] nums;
        private int[] cache;

        public NumArray(int[] nums) {
            this.nums = nums;
            cache = new int[nums.length + 1];
            if (nums.length > 0) {
                cache[0] = nums[0];
                for (int i = 1; i < nums.length; ++i) {
                    cache[i] = cache[i - 1] + nums[i];
                }
            }
        }

        public int sumRange(int i, int j) {
            if (i == 0) {
                return cache[j];
            }
            return cache[j] - cache[i - 1];
        }
    }
}
