#include <iostream>
#include <climits>
#include <vector>
#include "accumulation_const_bench.h"
#include "../../utils/src.h"

void NaiveCompressionBench(const char* filePath) {
    NaiveCompression naive_compression; 
    taskPrettyPrint("Collision comparison (Naive compression)", 4);
    printChar('-', 50);
    printChar('\n', 1);
    bench(naive_compression, filePath);
}

void MadCompressionBench(const char* filePath) {
    MadCompression mad_compression(11, 23); 
    taskPrettyPrint("Collision comparison (MAD compression with a=11, b=23)", 4);
    printChar('-', 50);
    printChar('\n', 1);
    bench(mad_compression, filePath);
}

void bench(Compression& compression, const char* filePath) {

    std::vector<int> a_consts = {33, 37, 39, 41};
    std::vector<int> containerSizes = {1999, 2003};


    for (int size: containerSizes) {
        std::vector<int>  minimumCollision = {INT_MAX, 0};
        std::vector<int>  maximumCollision = {INT_MIN, 0};

        for (int a: a_consts) {

            HashTable ht(size, a, compression); // size, accumulation const., compression class
            populateHashTableFromFile(filePath, ht); 

            std::cout << "Container size        | ";
            std::cout << size << std::endl;

            std::cout << "Accumulation Constant | ";
            std::cout << a << std::endl;

            std::cout << "Collisions            | ";
            int collisions = ht.totalCollisions();
            std::cout << collisions << std::endl;

            if (collisions < minimumCollision.front()) {
                minimumCollision.front() = collisions;
                minimumCollision.back() = a;
            }

            if (collisions > maximumCollision.front()) {
                maximumCollision.front() = collisions;
                maximumCollision.back() = a;
            }

            printChar('-', 50);
            printChar('\n', 1);
        }

        std::cout << "Maximum collisions    | ";
        std::cout << "a=" << maximumCollision.back() << " collisions=" << maximumCollision.front();
        printChar('\n', 1);
        std::cout << "Minimum collisions    | ";
        std::cout << "a=" << minimumCollision.back() << " collisions=" << minimumCollision.front();
        printChar('\n', 1);
        printChar('-', 50);
        printChar('\n', 1);
    }
}
