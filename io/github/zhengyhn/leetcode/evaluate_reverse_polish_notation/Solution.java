package io.github.zhengyhn.leetcode.evaluate_reverse_polish_notation;

import java.util.*;

public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        List<String> ops = new ArrayList<String>() {{
            add("+");
            add("-");
            add("*");
            add("/");
        }};
        for (String token: tokens) {
            if (!ops.contains(token)) {
                stack.push(Integer.valueOf(token));
            } else {
                int right = stack.pop();
                int left = stack.pop();
                int tempResult = 0;
                switch (token) {
                    case "+":
                        tempResult = left + right;
                        break;
                    case "-":
                        tempResult = left - right;
                        break;
                    case "*":
                        tempResult = left * right;
                        break;
                    case "/":
                        tempResult = left / right;
                        break;
                }
                stack.push(tempResult);
            }
        }
        return stack.peek();
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        String[] tokens = new String[]{"2", "1", "+", "3", "*"};
        System.out.println(sln.evalRPN(tokens));
        tokens = new String[]{"4", "13", "5", "/", "+"};
        System.out.println(sln.evalRPN(tokens));
        tokens = new String[]{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        System.out.println(sln.evalRPN(tokens));
    }
}
