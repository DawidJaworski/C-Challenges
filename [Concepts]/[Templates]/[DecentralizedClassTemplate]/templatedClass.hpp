#ifndef TEMPLATEDCLASS_HPP
#define TEMPLATEDCLASS_HPP

template <typename T>
class templatedClass {
  private:
    T value;
  public:
    T getValue();
    void setValue(T const&);
};

template <typename T>
T templatedClass<T>::getValue(){
  return value;
}

template <typename T>
void templatedClass<T>::setValue(T const& input){
   value = input;
}

#endif