Programs:

* data_race00.c 
  Description: Race on variable var, two threads are accessing var
  without any synchronization mechanism.
  Solution: Use a mutex to syncrhonize the access of the threads to
  var.
  Compile with:
          clang -g -fsanitize=thread data-race00.c -o data-race00 -pthread

* data-race01.cc
  Description: A race happens when two threads access a non-thread-safe
  complex object (e.g. an STL container) without synchronization.
  Solution: Use a mutex to perform an operation on the STL container
  (i.e. map).
  Compile with:
  	  clang++ -std=c++0x -g -fsanitize=thread data-race01.cc -o data-race01 -pthread

* data-race02.cc
  Description: One thread initializes an object pointer
  (which was initially null) with a new value, another thread spins
  until the object pointer becomes non-null. Without proper
  synchronization, the compiler may do very surprising transformations
  with such code which will lead to (occasional) failures. In addition
  to that, on some architectures this race may cause failures due to
  cache-related effects.  
  Solution: Use a mutex to synchronize the access on the object.
  Compile with:
  	  clang++ -std=c++0x -g -fsanitize=thread data-race02.cc -o data-race02 -pthread
