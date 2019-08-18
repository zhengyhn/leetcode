package io.github.zhengyhn.leetcode.number_of_1_bits;

public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ret = 0;
        while (n != 0) {
            ret += n & 1;
            n >>>= 1;
        }
        return ret;
    }
    public int hammingWeight2(int n) {
        int ret = 0;
        while (n != 0) {
            ++ret;
            n = n & (n - 1);
        }
        return ret;
    }

    public int hammingWeight3(int n) {
        return Integer.bitCount(n);
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        for (int i = -1; i < 10; ++i) {
            System.out.println(sln.hammingWeight(i) + " " + sln.hammingWeight2(i) + " " + sln.hammingWeight3(i));
        }
    }
}
