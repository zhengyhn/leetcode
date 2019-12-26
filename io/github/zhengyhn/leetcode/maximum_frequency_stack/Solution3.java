package io.github.zhengyhn.leetcode.maximum_frequency_stack;

import java.util.*;

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */

public class Solution3 {
    public static class FreqStack {
        private Map<Integer, Integer> freqMap;
        private List<Stack<Integer>> group;
        private Integer maxFreq;

        public FreqStack() {
            freqMap = new HashMap<>();
            group = new ArrayList<>(10);
            maxFreq = 0;
        }

        public void push(int x) {
            int freq = freqMap.getOrDefault(x, 0) + 1;
            freqMap.put(x, freq);
            Stack<Integer> stack = null;
            if (group.size() < freq) {
                stack = new Stack<>();
                stack.push(x);
                group.add(stack);
            } else {
                stack = group.get(freq - 1);
                stack.push(x);
            }
            if (freq > maxFreq) {
                maxFreq = freq;
            }
        }

        public int pop() {
            Stack<Integer> stack = group.get(maxFreq - 1);
            int val = stack.pop();
            freqMap.put(val, freqMap.get(val) - 1);
            if (stack.size() <= 0) {
                --maxFreq;
            }
            return val;
        }
    }

    public static void main(String[] args) {
        FreqStack obj = new FreqStack();
        obj.push(5);
        obj.push(1);
        obj.push(2);
        obj.push(5);
        obj.push(5);
        obj.push(5);
        obj.push(1);
        obj.push(6);
        obj.push(1);
        obj.push(5);
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        System.out.println(obj.pop());

        FreqStack stack = new FreqStack();
        for (int i = 0; i < 10; ++i) {
            stack.push(i);
        }
        for (int i = 0; i < 10; ++i) {
            System.out.println(stack.pop());
        }
        FreqStack stack2 = new FreqStack();
        stack2.push(1);
        System.out.println(stack2.pop());
    }
}
