#include <iostream>
#include <omp.h>

int main() {
#pragma omp parallel
#pragma omp critical
    std::cout << "THREAD: " << omp_get_thread_num() << " OF " << omp_get_num_threads() << '\n';
}