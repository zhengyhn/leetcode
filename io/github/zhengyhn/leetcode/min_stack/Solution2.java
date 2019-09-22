package io.github.zhengyhn.leetcode.min_stack;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

public class Solution2 {
    public static class MinStack {
        public static class Node {
            private Integer val;
            private Integer min;
            private Node next;

            public Node(int val, int min, Node next) {
                this.val = val;
                this.min = min;
                this.next = next;
            }
        }
        private Node head;

        /** initialize your data structure here. */
        public MinStack() {
        }

        public void push(int x) {
            if (head == null) {
                head = new Node(x, x, null);
            } else {
                head = new Node(x, Math.min(x, head.min), head);
            }
        }

        public void pop() {
            head = head.next;
        }

        public int top() {
            return head.val;
        }

        public int getMin() {
            return head.min;
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
