#include "src.h"
#include <iostream>

int main(void) {
    MadCompression md(3, 7);
    std::cout << md.compress(10, 20) << std::endl;
    return 0;
}
