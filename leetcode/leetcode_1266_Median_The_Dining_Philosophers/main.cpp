/*
 * @Author:darwin.lang
 * @Date:2022-06-06 22:24:44
 * @LastEditors:darwin.lang
 * @LastEditTime:2022-06-06 22:56:46
 * @Description:
 */

// mutex vs semaphore https://hackmd.io/@nKngvyhpQdGagg1V6GKLwA/Skh9Z2DpX?type=view
// code ref: https://leetcode.cn/problems/the-dining-philosophers/solution/zhe-xue-jia-jiu-can-wen-ti-by-mike-meng/
// better explain https://leetcode.cn/problems/the-dining-philosophers/solution/1ge-semaphore-1ge-reentrantlockshu-zu-by-gfu/

#include<mutex>
#include<condition_variable>
#include<functional>
// TODO: try to use semaphore.h
// #include<semaphore.h>
class Semaphore {
public:
  Semaphore(int count = 0) : count_(count) {
  }
    
  void Set(int count){
      count_ = count;
  }
    
  void Signal() {
    std::unique_lock<std::mutex> lock(mutex_);
    ++count_;
    cv_.notify_one();
  }

  void Wait() {
    std::unique_lock<std::mutex> lock(mutex_);
    while(count_ <= 0){
        cv_.wait(lock);
    }
    --count_;
  }

private:
  std::mutex mutex_;
  std::condition_variable cv_;
  int count_;
};

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        guid.Set(4);
    }
    
    void wantsToEat(int philosopher,
                    void(*pickLeftFork)(),
                    // std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher+1)%5;
        guid.Wait();        
        
        lock[l].lock();
        lock[r].lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();
        lock[r].unlock();
        lock[l].unlock();
        
        guid.Signal();
    }
private:
    std::mutex lock[5];
    Semaphore guid;
};

int main(void){
  return 0;
}
