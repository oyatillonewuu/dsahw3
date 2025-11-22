#include "../../hashtable/src.h"
#include "../../hashutils/src.h"
#include "../../utils/src.h"

int main(void) {
    NaiveCompression naive_compression; 
    HashTable ht(1999, 33, naive_compression); // size, accumulation const., compression class
    populateHashTableFromFile("../../materials/src.txt", ht);
    taskPrettyPrint("Display keys in ascending order by hash values", 20);
    ht.displayKeys();
    taskPrettyPrint("Display buckets with max. number of collisions", 20);
    ht.displayMaxCollisionBuckets();

    return 0;
}
