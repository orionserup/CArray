#include "Benchmark.h"
#include "MaxSub.h"

int main() {

    Data array[] = { 2, 5, -8, 77, 4, 3, 2, -44, -2, 66, 77, 88, 99, 888, -1};
    size_t size = sizeof(array)/sizeof(array[0]);

    Array arr = { array, size };

    puts("Array: ");
    PrintArray(arr);
    puts("Max Sub Array: ");
    Array max = MaxSubArrayBrute(arr);
    PrintArray(max);
    printf("Sum: %ld\n", (int64_t)SumArray(max));


    return 0;

}