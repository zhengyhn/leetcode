package io.github.zhengyhn.leetcode.insertion_sort_list;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    public static int[] stringToIntegerArray(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
            return new int[0];
        }

        String[] parts = input.split(",");
        int[] output = new int[parts.length];
        for (int index = 0; index < parts.length; index++) {
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
        for (int item : nodeValues) {
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
        int sign = 1;
        long num = Integer.MIN_VALUE;
        long deno = 1;
        if (num < 0) {
            sign = -sign;
            num = -num;
        }
        if (deno < 0) {
            sign = -sign;
            deno = -deno;
        }
        System.out.println(sign);

        ListNode head = stringToListNode("[4, 2, 3, 1]");
        ListNode ret = new Solution().insertionSortList(head);
        String out = listNodeToString(ret);
        System.out.println(out);


        head = stringToListNode("[4, 2, 3, 1]");
        ret = new Solution().insertionSortListOthers(head);
        out = listNodeToString(ret);
        System.out.print(out);
    }

    public ListNode insertionSortListOthers(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode prev = new ListNode(0);
        prev.next = head;
        ListNode tempNext = head.next;
        head.next = null;
        ListNode p = tempNext;
        while (p != null) {
            tempNext = p.next;
            ListNode p1 = prev;
            while (p1.next != null && p.val > p1.next.val) {
                p1 = p1.next;
            }
            p.next = p1.next;
            p1.next = p;
            p = tempNext;
        }
        return prev.next;
    }

    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode prev = head;
        ListNode newHead = head.next;
        while (newHead.next != null) {
            prev = prev.next;
            newHead = newHead.next;
        }
        prev.next = null;
        ListNode p = head;
        while (p != null) {
            ListNode tempNext = p.next;
            ListNode p1 = newHead;
            if (p1.val > p.val) {
                p.next = newHead;
                newHead = p;
            } else {
                ListNode p2 = p1;
                p1 = p1.next;
                while (p1 != null && p1.val < p.val) {
                    p1 = p1.next;
                    p2 = p2.next;
                }
                p2.next = p;
                p.next = p1;
            }
            p = tempNext;
        }
        return newHead;
    }

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}
