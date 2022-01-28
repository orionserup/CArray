#include "Benchmark.h"
#include "MaxSub.h"

#define MIN 1
#define MAX 10
#define STEP 1
#define SIZE (MAX - MIN)/STEP

int main() {

    Data n[SIZE];
    for(size_t i = 0; i < SIZE; i++)
        n[i] = MIN + STEP * i;

    BenchmarkArrayFunction(MAXSUB_BRUTE, (Array){ n, SIZE }, 2);

    return 0;

}
