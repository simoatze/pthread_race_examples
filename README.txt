Programs:

* data_race00.c 
  Description: Race on variable var, two threads are accessing var
  without any synchronization mechanism.
  Solution: Use a mutex to syncrhonize the access of the threads to
  var.
  Compile with:
          clang -g -fsanitize=thread data-race00.c -o data-race00 -pthreads

