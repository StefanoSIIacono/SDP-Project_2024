// omp_atomic.cpp
// compile with: /openmp
//jsut an simple example to check the parallelism of the thread
#include <stdio.h>
#include <omp.h>

#define MAX 10

// int main() {
//    int count = 0;
//    #pragma omp parallel num_threads(MAX)
//    {
//       #pragma omp atomic
//       count++;
//    }
//    printf("Number of threads: %d\n", count);
// }
// omp_parallel.cpp
// compile with: /openmp

// The following sample shows how to set the number of threads and define a parallel region.
//  The number of threads is equal by default to the number of logical processors on the machine.
//  For example, if you have a machine with one physical processor that has hyperthreading enabled, it will have two logical processors and two threads. 
// The order of output can vary on different machines.

int main() {
   #pragma omp parallel num_threads(4)
   {
      int i = omp_get_thread_num();
      printf("Hello from thread %d\n", i);
   }
}