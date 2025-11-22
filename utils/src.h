#pragma once
#include <string>
#include "../hashtable/src.h"

void populateHashTableFromFile(const std::string& path, HashTable& ht);
void taskPrettyPrint(std::string taskName, int n); // n -- n times print special char
void printChar(char ch, int n);
