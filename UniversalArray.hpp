#include <iostream>
#include <sstream>
#include <vector>
#include <typeinfo>

// Base class for every object
class BaseArrayElement
{
public:
    // Make this pure virtual to not to be called at Runtime.
    virtual std::string toJSONString()=0;
};

namespace Universal
{
    // define Universal::array as universal array vector.
	typedef std::vector<BaseArrayElement*> array;
}


// A template class for element.
template <typename T>
class ArrayElement : public BaseArrayElement
{
public:
    ArrayElement(T &t);
    ArrayElement(T t);
    // Virtual, it must be implemented.
    virtual std::string toJSONString();
private:
    T element;
};

template <typename T>
ArrayElement<T>::ArrayElement(T &t)
{
	element = t;
}

template <typename T>
ArrayElement<T>::ArrayElement(T t)
{
	element = t;
}

// Implementation of toJSONString
template <typename T>
std::string ArrayElement<T>::toJSONString()
{
	std::ostringstream oss;
	oss << "{ " << typeid(element).name() << " : " << element << " }";
	return oss.str();
}

