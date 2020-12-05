#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#include <utility>

typedef std::pair<int**, size_t> data;

struct edge {
  char v;
  char u;
  int weight;
};

#endif /* !TYPEDEFS_HPP */