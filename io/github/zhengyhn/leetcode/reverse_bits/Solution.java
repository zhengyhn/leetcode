package io.github.zhengyhn.leetcode.reverse_bits;

import java.util.Arrays;

public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ret = 0;
        int i = 0;
        while (i < 32) {
            ret <<= 1;
            ret += n & 1;
            n >>= 1;
            ++i;
        }
        return ret;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();

        System.out.println(sln.reverseBits(43261596));
        System.out.println(sln.reverseBits(-3));
    }
}
