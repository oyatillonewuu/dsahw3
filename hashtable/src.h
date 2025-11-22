#pragma once
#include <vector>
#include "../hashutils/src.h"


class HashTable {
private:
    const Compression& m_compressor;
    std::vector<std::vector<std::string>> m_container;
    size_t m_size;
    int m_a; // Accumulation constant

    size_t m_largest_bucket_idx {0}; // To make maxCollisonsHash function more efficient

    size_t findKeyIndex(size_t containerIdx, const std::string& key) const; 
    void updateLargestBucketIdx(size_t bucketIdx);
    size_t calculateHashValue(const std::string& key) const;
    void displayKeysOfBucket(size_t bucketIdx) const;
    
public:
    HashTable(size_t size, int accumulationConstant, const Compression& compressor);
    bool insert(std::string key);

    bool find(const std::string& key);
    void displayKeys() const;
    void displayMaxCollisionBuckets() const;
    long long totalCollisions() const;
};
