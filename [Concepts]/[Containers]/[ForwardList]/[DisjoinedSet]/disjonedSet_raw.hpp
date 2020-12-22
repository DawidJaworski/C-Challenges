#ifndef DISJOINED_SET_HPP
#define DISJOINED_SET_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T>
class disjoinedSet{
  private:
    std::vector<std::pair<T, int>> data {};
  public:
    disjoinedSet(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end);
    void mergeSets(T parent, T child);
    typename std::vector<T>::iterator find(T element);
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    int getCount();
    void print();
};

template<typename T>
disjoinedSet<T>::disjoinedSet(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end){
  int counter {0};
  for (auto it = begin; it != end; it++, counter++) {
    data.push_back(std::pair<T, int>{*it, counter});
  }

  //std::sort(data.begin(), data.end(), [](std::pair<T, int> a, std::pair<T, int> b){ return a.second < b.second; });
}

template <typename T>
void disjoinedSet<T>::print(){
  std::for_each(std::begin(data), std::end(data), [](std::pair<T, int> setID){ std::cout << setID.first << '\t' << setID.second << '\n'; });
}

template <typename T>
typename std::vector<T>::iterator disjoinedSet<T>::find(T element){
  return std::find(data.begin(), data.end(), [element](std::pair<T, int> item){ return item.first == element; });
}

template <typename T>
typename std::vector<T>::iterator disjoinedSet<T>::begin(){
  return data.begin();
}

template <typename T>
typename std::vector<T>::iterator disjoinedSet<T>::end(){
  return data.end();
}

#endif