/**
 * data-race04.cc
 *
 * Description: Sometimes one thread of a program may access a heap
 * memory while another thread is deallocating the same memory.
 *
 * Solution:
 *
 */
#include <stdlib.h>
#include <thread>

int *array;

void Thread1() {
  array[0]++;
}

void Thread2() {
  free(array);
}

int main() {
  array = (int *) malloc(10 * sizeof(int));

  std::thread t1(Thread1);
  std::thread t2(Thread2);

  t1.join();
  t2.join();

  return 0;
}
