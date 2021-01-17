package io.github.zhengyhn.leetcode.the_dining_philosophers;

import java.util.concurrent.Semaphore;

class DiningPhilosophers {
    private Semaphore[] chopsticks = new Semaphore[5];
    private Semaphore mutex = new Semaphore(1);

    public DiningPhilosophers() {
        for (int i = 0; i < 5; ++i) {
            chopsticks[i] = new Semaphore(1);
        }
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        mutex.acquire();
        chopsticks[philosopher].acquire();
        chopsticks[(philosopher + 1) % 5].acquire();
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        chopsticks[(philosopher + 1) % 5].release();
        chopsticks[philosopher].release();
        mutex.release();
    }
}

public class Solution {
}
