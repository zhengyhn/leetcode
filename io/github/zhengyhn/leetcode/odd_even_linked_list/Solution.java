package io.github.zhengyhn.leetcode.odd_even_linked_list;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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
        ListNode head = stringToListNode("[2,1,3,5,6,4,7]");

        ListNode ret = new Solution().oddEvenList(head);

        String out = listNodeToString(ret);

        System.out.print(out);
    }

    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }
        ListNode pOdd = head;
        ListNode pEven = head.next;
        ListNode pOddHead = pOdd;
        ListNode pEvenHead = pEven;
        while (pEven != null) {
            if (pEven.next == null) {
                break;
            }
            pOdd.next = pEven.next;
            pOdd = pOdd.next;
            pEven.next = pOdd.next;
            pEven = pEven.next;
        }
        pOdd.next = pEvenHead;
        return pOddHead;
    }

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}