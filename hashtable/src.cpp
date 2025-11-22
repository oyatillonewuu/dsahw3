#include <iostream>
#include "src.h"


HashTable::HashTable(
    size_t size,
    int accumulationConstant,
    const Compression& compressor
)
    : m_size{ size }
    , m_container( size, std::vector<std::string>() )
    , m_compressor{ compressor }
    , m_a{ accumulationConstant }
{};


size_t HashTable::findKeyIndex(size_t containerIdx, const std::string& key) const {
    const std::vector<std::string>& lookupVec = m_container.at(containerIdx);
    int size = lookupVec.size();

    for (size_t i = 0; i < size; i++) {
        if (lookupVec[i] == key)
            return i;
    }
    return -1;
}


void HashTable::updateLargestBucketIdx(size_t bucketIdx) {
    int currentSize = m_container.at(m_largest_bucket_idx).size();
    int candidateSize = m_container.at(bucketIdx).size();
    if (candidateSize > currentSize) {
        m_largest_bucket_idx = bucketIdx;
    }
}


size_t HashTable::calculateHashValue(const std::string& key) const {
    long long hashCode = polynomialAccumulation(key, m_a);
    return m_compressor.compress(hashCode, m_size);
}


bool HashTable::insert(std::string key) {
    size_t hashValue = calculateHashValue(key);
    size_t existingKeyIdx = findKeyIndex(hashValue, key);
    if (existingKeyIdx != -1) return false;

    m_container.at(hashValue).push_back(key);
    updateLargestBucketIdx(hashValue);

    return true;
}


bool HashTable::find(const std::string& key) {
    size_t hashValue = calculateHashValue(key);
    size_t keyIdx = findKeyIndex(hashValue, key);
    if (keyIdx == -1) return false;
    return true;
}


void HashTable::displayKeysOfBucket(size_t bucketIdx) const {
    int bucketSize = m_container[bucketIdx].size();
    for (size_t i = 0; i < bucketSize; i++) {
        std::cout << m_container[bucketIdx][i];
        if (i < bucketSize - 1) {
            std::cout << " | ";
        }
    }
    if (bucketSize > 0) { std::cout << std::endl; }
}


void HashTable::displayKeys() const {
    for (size_t i = 0; i < m_size; i++) {
        displayKeysOfBucket(i);
    }
}


void HashTable::displayMaxCollisionBucket() const {
    size_t targetSize = m_container.at(m_largest_bucket_idx).size();

    if (targetSize == 0) return;

    // Look for hash values that happen to have that much
    // size (which is largest)
    
    for (size_t i = 0; i < m_size; i++) {
        size_t bucketSize = m_container[i].size();
        if (bucketSize != targetSize) continue;

        std::cout << std::endl;
        std::cout << "Hash value: ";

        const std::string& sampleKey = m_container[i].front();
        size_t hashValue = calculateHashValue(sampleKey);

        std::cout << hashValue << std::endl;
        std::cout << "Keys: ";

        displayKeysOfBucket(i);
        std::cout << std::endl;
    }
}
