/**
 * data-race03.cc
 *
 * Description: If a program calls exit() while other threads are
 * still running, static objects may be destructed by one thread and
 * used by another thread at the same time.
 *
 * Solution:
 *
 */
#include "pthread.h"
#include <map>

static std::map<int, int> my_map;

void *MyThread(void *) {
  int i = 0;
  while(1) {
    my_map[(i++) % 1000]++;
  }
  return NULL;
}

int main() {
  pthread_t t;
  pthread_create(&t, 0, MyThread, 0);
  return 0;
  // exit() is called, my_map is destructed
}
