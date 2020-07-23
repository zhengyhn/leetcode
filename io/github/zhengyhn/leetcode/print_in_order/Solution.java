package io.github.zhengyhn.leetcode.print_in_order;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Semaphore;

class Foo {
    private final Semaphore lock1 = new Semaphore(0);
    private final Semaphore lock2 = new Semaphore(0);

    public Foo() {

    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        lock1.release();

    }

    public void second(Runnable printSecond) throws InterruptedException {
        lock1.acquire();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        lock2.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        lock2.acquire();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
class MyThread extends Thread {
    private int action;
    private Foo foo;

    public MyThread(Foo foo, int action) {
        this.foo = foo;
        this.action = action;
    }

    @Override
    public void run() {
        try {
            switch (action) {
                case 1:
                    foo.first(() -> {
                        System.out.println("first");
                    });
                    break;
                case 2:
                    foo.second(() -> {
                        System.out.println("second");
                    });
                    break;
                case 3:
                    foo.third(() -> {
                        System.out.println("third");
                    });
                    break;
                default:
                    break;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
public class Solution {
    public static void main(String[] args) {
        Foo foo = new Foo();
        int[] nums = {1, 3, 2};
        List<MyThread> threads = new ArrayList<>();
        for (int i : nums) {
            MyThread t = new MyThread(foo, i);
            t.start();
            threads.add(t);
        }
        for (MyThread thread : threads) {
            try {
                thread.join();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}