#pragma once
#include <string>


// Interface class
class Compression {
public:
    virtual size_t compress(long long value, size_t size) const = 0;
};


class NaiveCompression: public Compression {
public:
    size_t compress(long long value, size_t size) const override;
};


class MadCompression: public Compression {
private:
    int m_a;
    int m_b;
public:
    MadCompression(int a, int b);
    size_t compress(long long value, size_t size) const override;
};


long long polynomialAccumulation(const std::string& str, int a);
