package io.github.zhengyhn.leetcode.word_break;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean dp[] = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 0; i < s.length(); ++i) {
            for (String word: wordDict) {
                if ((i + word.length()) <= s.length() && dp[i] &&
                        s.substring(i, i + word.length()).equals(word)) {
                    dp[i + word.length()] = true;
                    if ((i + word.length()) == s.length()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        String[] tokens = new String[]{"cats", "dog", "sand", "and", "cat"};
        System.out.println(sln.wordBreak("catsandog", Arrays.asList(tokens)));
    }
}
