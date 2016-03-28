/**
 * data-race02.cc
 *
 * Description: One thread initializes an object pointer (which was
 * initially null) with a new value, another thread spins until the
 * object pointer becomes non-null. Without proper synchronization,
 * the compiler may do very surprising transformations with such code
 * which will lead to (occasional) failures. In addition to that, on
 * some architectures this race may cause failures due to
 * cache-related effects.
 *
 * Solution: Use a mutex to synchronize the access on the object.
 *
 */
#include <thread>

class MyType {

public:
  MyType() {};
  void DoSomething() { printf("Computing...\n"); }
};

MyType *obj = NULL;

void Thread1() {
  obj = new MyType();
}

void Thread2() {
  while(obj == NULL)
    std::this_thread::yield();;
  obj->DoSomething();
}

int main(int argc, char **argv) {
  std::thread t1(Thread1);
  std::thread t2(Thread2);
  
  t1.join();
  t2.join();
  
  return 0;
}
