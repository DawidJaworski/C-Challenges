#ifndef DISJOINEDSET_HPP
#define DISJOINEDSET_HPP

#include <iostream>
#include <vector>
#include <unordered_map>

#include "typeDefs.hpp"

class disjoinedSet {
  private:
    std::unordered_map<edge, int> data;
  public:
    disjoinedSet() { MakeSet(std::vector<edge>()); };
    void MakeSet(std::vector<edge> const &);
    void Union(edge, edge);
    edge Find(edge);
    void Print();
};



#endif /* !DISJOINEDSET_HPP */