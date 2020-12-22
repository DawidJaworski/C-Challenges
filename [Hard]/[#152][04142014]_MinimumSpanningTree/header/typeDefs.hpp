#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#include <cstddef>
#include <utility>

typedef std::pair<int**, size_t> data;

struct edge {
  char v;
  char u;
  int weight;
  edge(char const& start = '\0', char const& end = '\0', int const& weight = 0) : v(start), u(end), weight(weight) {};
};

#endif /* !TYPEDEFS_HPP */