#ifndef DISJOINED_SET_HPP
#define DISJOINED_SET_HPP

#include <forward_list>
#include <vector>
#include <algorithm>

template <typename T>
class disjoinedSet{
  private:
    std::vector<std::forward_list<T>> data {};
  public:
    void makeSet(T element);
    void mergeSets(std::forward_list<T> parent, std::forward_list<T> child);
    typename std::vector<std::forward_list<T>>::iterator find(T element);
    typename std::vector<std::forward_list<T>>::iterator Begin();
    typename std::vector<std::forward_list<T>>::iterator End();
    int getCount();
};

// Member functions
template <typename T>
void disjoinedSet<T>::makeSet(T element){
  data.push_back(std::forward_list<T>{element});
}

template <typename T>
void disjoinedSet<T>::mergeSets(std::forward_list<T> parent, std::forward_list<T> child){

}

template <typename T>
typename std::vector<std::forward_list<T>>::iterator disjoinedSet<T>::find(T element){
  return std::find_if(std::begin(data), std::end(data), 
    [element](auto x) { return (std::find(std::begin(x), std::end(x), element) != std::end(x)); });
}

template <typename T>
typename std::vector<std::forward_list<T>>::iterator disjoinedSet<T>::Begin(){
  return std::begin(data);
}

template <typename T>
typename std::vector<std::forward_list<T>>::iterator disjoinedSet<T>::End(){
  return std::end(data);
}

template <typename T>
int disjoinedSet<T>::getCount(){
  return data.size();
}

#endif