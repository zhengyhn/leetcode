package io.github.zhengyhn.leetcode.min_stack;

import sun.plugin.cache.OldCacheEntry;

import java.util.ArrayList;
import java.util.List;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

public class Solution {
    public static class MinStack {
        private int[] stack;
        private Integer size = 0;
        private Integer min = Integer.MAX_VALUE;
        /** initialize your data structure here. */
        public MinStack() {
            stack = new int[10];
        }

        public void push(int x) {
            ++size;
            if (size > stack.length) {
                int[] old = stack;
                stack = new int[size * 2];
                System.arraycopy(old, 0, stack, 0, size - 1);
            }
            stack[size - 1] = x;
            if (x < min) {
                min = x;
            }
        }

        public void pop() {
            if (size <= 0) {
                return;
            }
            if (stack[size - 1] == min) {
                min = Integer.MAX_VALUE;
                for (int i = 0; i < size - 1; ++i) {
                    if (stack[i] < min) {
                        min = stack[i];
                    }
                }
            }
            --size;
            if (size == 0) {
                min = Integer.MAX_VALUE;
            }
        }

        public int top() {
            return stack[size - 1];
        }

        public int getMin() {
            return min;
        }
    }

    public static void main(String[] args) {
//        MinStack obj = new MinStack();
//        obj.push(2147483646);
//        obj.push(2147483646);
//        obj.push(2147483647);
//        System.out.println(obj.top());
//        obj.pop();
//        System.out.println(obj.getMin());
//        obj.pop();
//        System.out.println(obj.getMin());
//        obj.pop();
//        obj.push(2147483647);
//        System.out.println(obj.top());
//        System.out.println(obj.getMin());
//        obj.push(-2147483648);
//        System.out.println(obj.top());
//        System.out.println(obj.getMin());
//        obj.pop();
//        System.out.println(obj.getMin());

        MinStack stack = null;
        for (int i = 0; i < Sample.ops.length; ++i) {
            String op = Sample.ops[i];
            if (op.equals("MinStack")) {
                stack = new MinStack();
            } else if (op.equals("push")) {
                stack.push(Sample.data[i][0]);
            } else if (op.equals("pop")) {
                stack.pop();
            } else if (op.equals("top")) {
                System.out.println(stack.top());
            } else if (op.equals("getMin")) {
                System.out.println(stack.getMin());
            }
        }
    }
}
