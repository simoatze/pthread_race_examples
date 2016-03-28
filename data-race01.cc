/**
 * data-race01.cc
 *
 * Description: A race happens when two threads access a
 * non-thread-safe complex object (e.g. an STL container) without
 * synchronization.
 *
 * Solution: Use a mutex to perform a synchronized operation on the
 * STL container (i.e. map).
 *
 */
#include <thread>
#include <map>
// #include <mutex>

std::map<int,int> m;
// std::mutex mtx;

void Thread1() {
  // mtx.lock();
  m[123] = 1;
  // mtx.unlock();
}

void Thread2() {
  // mtx.lock();
  m[345] = 0;
  // mtx.unlock();
}

int main(int argc, char **argv) {
  std::thread t1(Thread1);
  std::thread t2(Thread2);

  t1.join();
  t2.join();

  return 0;
}
