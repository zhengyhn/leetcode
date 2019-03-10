package io.github.zhengyhn.leetcode.valid_anagram;

import java.util.Arrays;

public class Solution {
    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] first = new int[26];
        Arrays.fill(first, 0);
        int[] second = new int[26];
        Arrays.fill(second, 0);

        for (int i = 0; i < s.length(); ++i) {
            first[s.charAt(i) - 'a'] += 1;
        }
        for (int i = 0; i < t.length(); ++i) {
            second[t.charAt(i) - 'a'] += 1;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (first[i] != second[i]) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        if (isAnagram("rat", "cat")) {
            System.out.println("t");
        } else {
            System.out.println("f");
        }
    }
}
