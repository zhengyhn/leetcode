package io.github.zhengyhn.leetcode.maximum_product_subarray;

import sun.awt.motif.X11KSC5601;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int maxProduct2(int[] nums) {
        if (nums.length <= 0) {
            return 0;
        }
        int max = nums[0];
        int[] lastResult = new int[nums.length];
        lastResult[0] = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                int product = nums[i] * lastResult[j];
                if (product > max) {
                    max = product;
                }
                lastResult[j] = product;
            }
            if (nums[i] > max) {
                max = nums[i];
            }
            lastResult[i] = nums[i];
        }
        return max;
    }

    public int maxProduct(int[] nums) {
        if (nums.length <= 0) {
            return 0;
        }
        int lastMax = nums[0];
        int lastMin = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            int tempLastMax = lastMax * nums[i];
            int tempLastMin = lastMin * nums[i];
            max = tempLastMax > max ? tempLastMax : max;
            max = tempLastMin > max ? tempLastMin : max;
            max = nums[i] > max ? nums[i] : max;
            if (tempLastMax > tempLastMin) {
               lastMax = tempLastMax;
               lastMin = tempLastMin;
            } else {
                lastMax = tempLastMin;
                lastMin = tempLastMax;
            }
            lastMax = nums[i] > lastMax ? nums[i] : lastMax;
            lastMin = nums[i] < lastMin ? nums[i] : lastMin;
        }
        return max;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        int[] nums = new int[]{2, 3, -2, 4};
        System.out.println(sln.maxProduct2(nums));
        System.out.println(sln.maxProduct(nums));

        nums = new int[]{-2, 0, -1};
        System.out.println(sln.maxProduct2(nums));
        System.out.println(sln.maxProduct(nums));

        nums = new int[]{0, 2};
        System.out.println(sln.maxProduct2(nums));
        System.out.println(sln.maxProduct(nums));

        nums = new int[]{};
        System.out.println(sln.maxProduct2(nums));
        System.out.println(sln.maxProduct(nums));

        nums = new int[]{2};
        System.out.println(sln.maxProduct2(nums));
        System.out.println(sln.maxProduct(nums));
    }
}
