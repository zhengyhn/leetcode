package io.github.zhengyhn.leetcode.convert_sorted_list_to_binary_search_tree;

import java.util.ArrayList;
import java.util.List;

public class Solution2 {
    private ListNode head;

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public TreeNode sortedListToBST(ListNode head) {
        int size = 0;
        ListNode p = head;
        while (p != null) {
            ++size;
            p = p.next;
        }
        this.head = head;
        return buildTree(0, size - 1);
    }

    private TreeNode buildTree(int start, int end) {
        if (end < start) {
            return null;
        }
        int mid = (start + end) / 2;
        TreeNode left = buildTree(start, mid - 1);
        TreeNode root = new TreeNode(this.head.val);
        this.head = this.head.next;
        root.left = left;

        TreeNode right = buildTree(mid + 1, end);
        root.right = right;

        return root;
    }

    private static ListNode createList(int[] arr) {
        if (arr.length < 1) {
           return null;
        }
        ListNode head = new ListNode(arr[0]);
        ListNode p = head;
        for (int i = 1; i < arr.length; ++i) {
           p.next = new ListNode(arr[i]);
           p = p.next;
        }
        return head;
    }

    private static void printTree(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            printTree(root.left);
        }
        System.out.print(root.val + " ");
        if (root.right != null) {
            printTree(root.right);
        }
    }

    public static void main(String[] args) {
        Solution2 sln = new Solution2();
        ListNode head = createList(new int[]{-10, -3, 0, 5, 9});
        TreeNode root = sln.sortedListToBST(head);
        printTree(root);
        System.out.println();
    }
}
