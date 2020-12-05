#include "../header/disjoinedSet.hpp"

template <class T>
disjointSet<T>::disjointSet(){
  data = std::unordered_map<T,int>();
  return;
}

template <class T>
void disjointSet<T>::MakeSet(std::vector<T> const &dataset){
  int setID = 0;
  for (T e : dataset){
    data[e] = setID++;
  }
}

template <class T>
T disjointSet<T>::Find(T value){
  int setID = data[value];
  int elementIndex = std::distance(data.begin(), data.find(value));
  if(setID == elementIndex) // check for root element
    return value;
  return Find(data.begin()+elementIndex);
}

template <class T>
void disjointSet<T>::Union(T parent, T child){
  T parentRoot = Find(parent);
  T childRoot = Find(child);

  data[childRoot] = data.find(parentRoot)->second; 
}

template <class T>
void disjointSet<T>::Print(){
  printf("========================================\n");
  for(T e : data){
    printf("edge:|%c%c| id:%d pos:%d \n");
  }
  printf("========================================\n");
}