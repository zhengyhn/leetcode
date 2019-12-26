package io.github.zhengyhn.leetcode.divisor_game;

public class Solution {
    public boolean divisorGame(int N) {
        return N % 2 == 0;
    }
    public static void main(String[] args) {
        Solution sln = new Solution();
        System.out.println(sln.divisorGame(1000));
    }
}
