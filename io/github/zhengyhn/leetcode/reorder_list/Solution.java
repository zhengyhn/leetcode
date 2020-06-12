package io.github.zhengyhn.leetcode.reorder_list;

import java.io.IOException;

public class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        ListNode p1 = head;
        ListNode p2 = p1.next;
        while (p2 != null) {
            p2 = p2.next;
            if (p2 != null) {
                p2 = p2.next;
            } else {
                break;
            }
            p1 = p1.next;
        }
        p2 = p1.next;
        p1.next = null;
        p2 = revert(p2);
        p1 = head;
        while (p1 != null) {
            ListNode temp = p1.next;
            p1.next = p2;
            p1 = temp;
            if (p2 != null) {
                temp = p2.next;
                p2.next = p1;
                p2 = temp;
            }
        }
    }

    private ListNode revert(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode newHead = revert(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }
    public static int[] stringToIntegerArray(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
            return new int[0];
        }

        String[] parts = input.split(",");
        int[] output = new int[parts.length];
        for(int index = 0; index < parts.length; index++) {
            String part = parts[index].trim();
            output[index] = Integer.parseInt(part);
        }
        return output;
    }

    public static ListNode stringToListNode(String input) {
        // Generate array from the input
        int[] nodeValues = stringToIntegerArray(input);

        // Now convert that list into linked list
        ListNode dummyRoot = new ListNode(0);
        ListNode ptr = dummyRoot;
        for(int item : nodeValues) {
            ptr.next = new ListNode(item);
            ptr = ptr.next;
        }
        return dummyRoot.next;
    }

    public static String listNodeToString(ListNode node) {
        if (node == null) {
            return "[]";
        }

        String result = "";
        while (node != null) {
            result += Integer.toString(node.val) + ", ";
            node = node.next;
        }
        return "[" + result.substring(0, result.length() - 2) + "]";
    }

    public static void main(String[] args) throws IOException {
        System.out.println((int)Math.sqrt(13));

        ListNode head = stringToListNode("[1,2,3,4,5]");
        new Solution().reorderList(head);
        String out = listNodeToString(head);
        System.out.println(out);
    }
}
