#ifndef DISJOINEDSET_HPP
#define DISJOINEDSET_HPP

#include <unordered_map>
#include <vector>
#include <iostream>

template <class T>
class disjointSet {
  std::unordered_map<T, int> *data;
  public:
    disjointSet();
    void MakeSet(std::vector<T> const &);
    void Union(T, T);
    T Find(T);
    void Print();
};

#endif /* !DISJOINEDSET_HPP */