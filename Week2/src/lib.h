#pragma once
#include <vector>
#include <string>


std::vector<std::string> split(const std::string &str, char d);
std::vector<int> splitToFourInts(const std::string &str, char d);
std::vector<std::vector<int>> filter(const std::vector<std::vector<int>>& ips, int pos1, int pos2 = -1);
std::vector<std::vector<int>> filter_any(const std::vector<std::vector<int>>& ips, int val);