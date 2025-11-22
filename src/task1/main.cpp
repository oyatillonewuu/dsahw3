#include "../../hashtable/src.h"
#include "../../hashutils/src.h"
#include "../../utils/src.h"

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        return -1;
    }
    NaiveCompression naive_compression; 
    HashTable ht(1999, 33, naive_compression); // size, accumulation const., compression class
    populateHashTableFromFile(argv[1], ht);
    taskPrettyPrint("Display keys in ascending order by hash values", 20);
    ht.displayKeys();
    taskPrettyPrint("Display buckets with max. number of collisions", 20);
    ht.displayMaxCollisionBuckets();

    return 0;
}
