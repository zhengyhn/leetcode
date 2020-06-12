package io.github.zhengyhn.leetcode.minimum_size_subarray_sum;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] >= s) {
                return 1;
            }
            int sum = nums[i];
            for (int j = i + 1; j < nums.length; ++j) {
                sum += nums[j];
                if (sum < s) {
                    continue;
                }
                min = Math.min(j - i + 1, min);
                int k = i + 1;
                int newSum = sum;
                while (k <= j) {
                    newSum -= nums[k - 1];
                    if (newSum >= s) {
                        min = Math.min(j - k + 1, min);
                    } else {
                        break;
                    }
                    ++k;
                }
                i = k;
                sum = newSum;
            }
        }
        return min == Integer.MAX_VALUE ? 0 : min;
    }
    public int minSubArrayLenOthers(int s, int[] nums) {
        int min = Integer.MAX_VALUE;
        int sum = 0;
        int i = 0;
        for (int j = 0; j < nums.length; ++j) {
            sum += nums[j];
            while (sum >= s) {
                min = Math.min(min, j - i + 1);
                sum -= nums[i];
                ++i;
            }
        }
        return min == Integer.MAX_VALUE ? 0 : min;
    }
    public static void main(String[] args) throws IOException {
        int s = 15;
        int[] nums = new int[]{5,1,3,5,10,7,4,9,2,8};
        Solution sln = new Solution();
        System.out.println(sln.minSubArrayLen(s, nums));
        System.out.println(sln.minSubArrayLenOthers(s, nums));
    }
}
