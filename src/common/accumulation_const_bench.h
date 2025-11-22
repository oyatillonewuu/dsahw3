#pragma once
#include "../../hashtable/src.h"
#include "../../hashutils/src.h"

void NaiveCompressionBench(const char* filePath);
void MadCompressionBench(const char* filePath);
void bench(Compression& compression, const char* filePath);
