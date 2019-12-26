package io.github.zhengyhn.leetcode.is_subsequence;

public class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0;
        int j = 0;
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                ++i;
            }
            ++j;
        }
        if (i >= s.length()) {
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        Solution sln = new Solution();
        System.out.println(sln.isSubsequence("abc", "aabdcd"));
    }
}
