package io.github.zhengyhn.leetcode.ugly_number_ii;

public class Solution {
    public int nthUglyNumber(int n) {
        int[] nums = new int[n];
        nums[0] = 1;
        int i = 1;
        int num2 = 2;
        int num3 = 3;
        int num5 = 5;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while (i < n) {
            int min = Math.min(Math.min(num2, num3), num5);
            if (min == num2) {
                nums[i] = min;
                num2 = nums[++i2] * 2;
            }
            if (min == num3) {
                nums[i] = min;
                num3 = nums[++i3] * 3;
            }
            if (min == num5) {
                nums[i] = min;
                num5 = nums[++i5] * 5;
            }
            ++i;
        }
        return nums[i - 1];
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        System.out.println(sln.nthUglyNumber(12));
    }
}
