
#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace util {

std::vector<std::string> split(const std::string& str, char sep) {
  if (str.empty()) return {};

  std::vector<std::string> res;
  auto start = str.begin();
  auto end = str.end();
  auto next = std::find(start, end, sep);

  while (next != end) {
    res.emplace_back(start, next);
    start = next + 1;
    next = std::find(start, end, sep);
  }

  res.emplace_back(start, next);
  
  return res;
}

void ltrim(std::string &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
    return !std::isspace(ch);
  }));
}

void rtrim(std::string &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
    return !std::isspace(ch);
  }).base(), s.end());
}

void trim(std::string &s) {
  ltrim(s);
  rtrim(s);
}

} // util
