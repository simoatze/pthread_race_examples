/**
 * data-race00.c
 *
 * Description: Race on variable var, two threads are accessing var
 * without any synchronization mechanism.
 *
 * Solution: Use a mutex to syncrhonize the access of the threads to
 * var.
 *
 */
#include <stdio.h>
#include <pthread.h>

int var;

void *Thread1() {
  var++;

  return NULL;
}

void *Thread2() {
  var++;

  return NULL;
}

int main(int argc, char **argv) {
  var = 0;
  
  pthread_t t1;
  pthread_t t2;

  pthread_create(&t1, NULL, Thread1, NULL);
  pthread_create(&t2, NULL, Thread2, NULL);
   
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  
  return 0;
}
