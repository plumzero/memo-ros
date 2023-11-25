
#pragma once

#include <cstdio>
#include <sys/time.h>
#include "rosbag/bag.h"

#include "roslog/detail.h"

std::string clocktime()
{
  struct timeval t;
  gettimeofday(&t, 0);

  char buf[64] = {0};
  struct tm* tm = localtime(&t.tv_sec);
  int n = snprintf(buf, sizeof(buf), "%02d:%02d:%02d.%03ld", tm->tm_hour, tm->tm_min, tm->tm_sec, t.tv_usec / 1000);

  return std::string(buf, n);
}

inline uint64_t GetCurrentTicks()
{
  struct timeval t;
  gettimeofday(&t, 0);
  return static_cast<uint64_t>(t.tv_sec) * 1000 + static_cast<uint64_t>(t.tv_usec) / 1000;
}

inline roslog::detail genlog(uint8_t loglevel, std::string filename, uint32_t lineno, const std::string& msg)
{
  roslog::detail detail;
  detail.loglevel = loglevel;
  detail.filename = filename;
  detail.lineno = lineno;
  detail.timestamp = GetCurrentTicks();
  detail.clocktime = clocktime();
  detail.detail = msg;
  return detail;
}

inline void print(const roslog::detail& detail)
{
  printf("%s %d [%d] [%s]: %s\n", detail.filename.c_str(), detail.lineno, detail.loglevel, detail.clocktime.c_str(), detail.detail.c_str());
  return ;
}