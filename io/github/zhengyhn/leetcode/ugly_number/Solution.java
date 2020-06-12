package io.github.zhengyhn.leetcode.ugly_number;

public class Solution {
    public boolean isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        int[] factors = new int[]{5, 3, 2};
        for (int i: factors) {
            while (num % i == 0) {
                num /= i;
            }
        }
        return num == 1;
    }
    public static void main(String[] args) {
        Solution sln = new Solution();
        System.out.println(sln.isUgly(12));
    }
}
