#include <iostream>
#include "../common/accumulation_const_bench.h"

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        return -1;
    }
    NaiveCompressionBench(argv[1]);
    return 0;
}
