package io.github.zhengyhn.leetcode.house_robber_ii;

import java.util.Arrays;
import java.util.List;

public class Solution {
    public int rob(int[] nums) {
        if (nums.length <= 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int dp[][] = new int[nums.length + 1][2];
        dp[nums.length - 1][1] = nums[nums.length - 1];
        for (int i = nums.length - 2; i >= 0; --i) {
            for (int k = 0; k < 2; ++k) {
                int max = nums[i] + dp[i + 2][k];
                for (int j = i + 1; j < i + 3; ++j) {
                    max = Math.max(max, dp[j][k]);
                }
                dp[i][k] = max;
            }
        }
        int max = dp[0][0];
        for (int i = 1; i < 3; ++i) {
            max = Math.max(max, dp[i][1]);
        }
        return max;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        int[] tokens = new int[]{1, 2, 3, 4, 5};
        System.out.println(sln.rob(tokens));
    }
}
