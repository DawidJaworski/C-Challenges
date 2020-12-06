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



#endif