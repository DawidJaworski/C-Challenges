#include "../header/disjoinedSet.hpp"

void disjoinedSet::MakeSet(std::vector<edge> const &dataset){
  int setID = 0;
  for (edge e : dataset){
    data.at(e) = setID++;
  }
}

edge disjoinedSet::Find(edge value){
  auto it = data.begin();
  int setID = data[value];
  int elementIndex = std::distance(it, data.find(value));
  if(setID == elementIndex) // check for root element
    return value;

  std::advance(it, elementIndex);
  return Find(it->first);
}

void disjoinedSet::Union(edge parent, edge child){
  edge parentRoot = Find(parent);
  edge childRoot = Find(child);

  data[childRoot] = data.find(parentRoot)->second; 
}

void disjoinedSet::Print(){
  printf("========================================\n");
  for(auto &e : data)
    printf("edge:|%c%c| id:%d pos:%d \n", 'A', 'A', 0, 0);
  printf("========================================\n");
}