package io.github.zhengyhn.leetcode.guess_number_higher_or_lower;


import java.io.IOException;

public class Solution {
    public int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int result = guess(mid);
            if (result < 0) {
                high = mid - 1;
            } else if (result > 0) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return n;
    }
    private int guess(int num) {
        if (num > 1702766719) {
            return -1;
        } else if (num < 1702766719) {
            return 1;
        } else {
            return 0;
        }
    }
    public static void main(String[] args) throws IOException {
        Solution sln = new Solution();
        String[] arr = new String[]{"1", "2", "3"};
        System.out.println(String.join(",", arr));
        System.out.println(sln.guessNumber(2126753390));
    }
}
