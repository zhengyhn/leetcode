package io.github.zhengyhn.leetcode.maximum_frequency_stack;

import io.github.zhengyhn.leetcode.min_stack.Sample;

import java.util.HashMap;
import java.util.Map;

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */

public class Solution {
    public static class FreqStack {
        public static class Node {
            public Integer val;
            public Integer freq;
            public Node prev;
            public Node next;

            public Node(int val, int freq, Node prev, Node next) {
                this.val = val;
                this.freq = freq;
                this.prev = prev;
                this.next = next;
            }
        }

        private Node head;
        private Map<Integer, Integer> frequency;

        public FreqStack() {
        }

        public void push(int x) {
            if (head == null) {
                head = new Node(x, x, null, null);
                frequency = new HashMap<>();
                frequency.put(x, 1);
            } else {
                int freq = frequency.getOrDefault(x, 0);
                frequency.put(x, ++freq);
                int mostFreq = frequency.get(head.freq);
                int mostFreqElem = head.freq;
                if (freq >= mostFreq) {
                    mostFreqElem = x;
                }
                Node temp = head;
                head = new Node(x, mostFreqElem, null, head);
                temp.prev = head;
            }
        }

        public int pop() {
            Node p = head;
            while (!p.val.equals(head.freq)) {
                frequency.put(p.val, frequency.get(p.val) - 1);
                p = p.next;
            }
            frequency.put(p.val, frequency.get(p.val) - 1);
            Node pPrev = p.prev;
            Node pNext = p.next;
            if (head == p) {
                head = pNext;
            }
            p.prev = null;
            p.next = null;
            if (pPrev != null) {
                pPrev.next = pNext;
            }
            if (pNext != null) {
                pNext.prev = pPrev;
            }
            Node p2 = pPrev;
            while (p2 != null) {
                frequency.put(p2.val, frequency.getOrDefault(p2.val, 0) + 1);
                if (p2.next == null) {
                    p2.freq = p2.val;
                } else {
                    if (frequency.get(p2.val) >= frequency.get(p2.next.freq)) {
                        p2.freq = p2.val;
                    } else {
                        p2.freq = p2.next.freq;
                    }
                }
                p2 = p2.prev;
            }
            return p.val;
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
