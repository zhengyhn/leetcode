package io.github.zhengyhn.leetcode.binary_search_tree_iterator;

import com.sun.tools.hat.internal.model.Root;

import java.io.IOException;
import java.util.*;

public class Solution {
    public static class BSTIteratorOthers {
        private Stack<TreeNode> stack = new Stack<>();

        public BSTIteratorOthers(TreeNode root) {
            this.inorderLeft(root);
        }
        private void inorderLeft(TreeNode root) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
        }

        public boolean hasNext() {
            return !stack.empty();
        }

        public int next() {
            TreeNode node = stack.pop();
            if (node.right != null) {
                inorderLeft(node.right);
            }
            return node.val;
        }
    }

    public static class BSTIterator {
        private List<Integer> elements;
        private int index = 0;

        public BSTIterator(TreeNode root) {
            elements = new ArrayList<Integer>();
            Stack<TreeNode> stack = new Stack<TreeNode>();
            TreeNode current = root;
            while (current != null || !stack.empty()) {
                while (current != null) {
                    stack.push(current);
                    current = current.left;
                }
                current = stack.pop();
                elements.add(current.val);
                current = current.right;
            }
        }

        /** @return the next smallest number */
        public int next() {
            return elements.get(index++);
        }

        /** @return whether we have a next smallest number */
        public boolean hasNext() {
            return index < elements.size();
        }
    }
    public static TreeNode stringToTreeNode(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
            return null;
        }

        String[] parts = input.split(",");
        String item = parts[0];
        TreeNode root = new TreeNode(Integer.parseInt(item));
        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);

        int index = 1;
        while (!nodeQueue.isEmpty()) {
            TreeNode node = nodeQueue.remove();

            if (index == parts.length) {
                break;
            }

            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) {
                int leftNumber = Integer.parseInt(item);
                node.left = new TreeNode(leftNumber);
                nodeQueue.add(node.left);
            }

            if (index == parts.length) {
                break;
            }

            item = parts[index++];
            item = item.trim();
            if (!item.equals("null")) {
                int rightNumber = Integer.parseInt(item);
                node.right = new TreeNode(rightNumber);
                nodeQueue.add(node.right);
            }
        }
        return root;
    }

    public static void main(String[] args) throws IOException {
        TreeNode root = stringToTreeNode("[7,3,15,null,null,9,20]");
        BSTIterator iterator = new BSTIterator(root);
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

        root = stringToTreeNode("[7,3,15,null,null,9,20]");
        BSTIteratorOthers iteratorOthers = new BSTIteratorOthers(root);
        while (iteratorOthers.hasNext()) {
            System.out.println(iteratorOthers.next());
        }
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
}
