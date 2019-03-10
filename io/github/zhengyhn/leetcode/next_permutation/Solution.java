package io.github.zhengyhn.leetcode.next_permutation;

import java.util.Arrays;

public class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 1;
        for (; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                break;
            }
        }
        if (i > 0) {
            int j = nums.length - 1;
            for (; j >= i; --j) {
                if (nums[j] > nums[i - 1]) {
                    break;
                }
            }
            swap(nums, i - 1, j);
        }
        int end = nums.length - 1;
        while (i < end) {
            swap(nums, i++, end--);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        int[] nums = {1, 2, 4, 3};
        sln.nextPermutation(nums);
        Arrays.stream(nums).forEach(System.out::println);
    }
}
