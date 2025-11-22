#include "src.h"
#include <string>


size_t NaiveCompression::compress(long long value, size_t size) const {
    return std::abs(value) % size;
}


MadCompression::MadCompression(int a, int b)
    : m_a{ a }
    , m_b{ b }
{};


size_t MadCompression::compress(long long value, size_t size) const {
    return std::abs(m_a * value + m_b) % size;
}


long long polynomialAccumulation(const std::string& str, int a) {
    if (str.length() == 0) return 0;

    long long p = int(str.back());
    long long i = str.length() - 2;

    // Algorithm for computing polynomial accumulation
    // based on Horner's Rule.
    while (i >= 0) {
        p = p * a + int(str.at(i));
        i--;
    }
    return p;
}
