package io.github.zhengyhn.leetcode.find_minimum_in_rotated_sorted_array;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int findMin(int[] nums) {
        if (nums.length <= 0) {
            return 0;
        }
        int min = nums[0];
        int low = 1;
        int high = nums.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > min) {
                low = mid + 1;
            } else {
                min = nums[mid];
                high = mid - 1;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        int[] nums = new int[]{3, 4, 5, 1, 2};
        System.out.println(sln.findMin(nums));

        nums = new int[]{3, 4, 5, 7, 0, 1, 2};
        System.out.println(sln.findMin(nums));

        nums = new int[]{0,1,2,4,5,6,7};
        System.out.println(sln.findMin(nums));

        nums = new int[]{1,2,4,5,6,7,0};
        System.out.println(sln.findMin(nums));

        nums = new int[]{1};
        System.out.println(sln.findMin(nums));

        nums = new int[]{1, 2};
        System.out.println(sln.findMin(nums));

        nums = new int[]{2, 1};
        System.out.println(sln.findMin(nums));
    }
}
