package io.github.zhengyhn.leetcode.daily_temperatures;

import java.io.IOException;
import java.util.*;

public class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] result = new int[T.length];
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(T.length - 1);
        for (int i = T.length - 2; i >= 0; --i) {
            while (!stack.empty() && T[i] >= T[stack.peek()]) {
                stack.pop();
            }
            if (!stack.empty()) {
                result[i] = stack.peek() - i;
            }
            stack.push(i);
        }
        return result;
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        int[] result = sln.dailyTemperatures(new int[]{73, 74, 75, 71, 69, 72, 76, 73});
        for (int i : result) {
            System.out.println(i);
        }
    }
}
