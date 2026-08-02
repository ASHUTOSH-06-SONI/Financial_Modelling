#ifndef LOADER_H
#define LOADER_H
#include<vector>
#include<string>
std::vector<std::vector<std::string>> loadCSV(const std::string& filename); // keep immutable to prevent corruption
#endif