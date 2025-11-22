#include <iostream>
#include <fstream>
#include <string>
#include "src.h"
#include "../hashtable/src.h"


void populateHashTableFromFile(const std::string& path, HashTable& ht) {
    std::string line;
    std::ifstream file(path);

    while (std::getline(file, line)) {
        if (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }

        ht.insert(line);
    }
    file.close();
}

void taskPrettyPrint(std::string taskName, int n) {
    printChar('=', n);
    printChar(' ', 1);
    std::cout << taskName;
    printChar(' ', 1);
    printChar('=', n);
    printChar('\n', 1);
}

void printChar(char ch, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << ch;
    }
}
