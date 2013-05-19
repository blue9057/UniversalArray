#include <iostream>
#include <sstream>
#include <vector>

class BaseArrayElement
{
public:
    virtual std::string toJSONString()
    {
    	return std::string("nil");
    }
};

namespace universal
{
	typedef std::vector<BaseArrayElement*> array;
}


template <typename T>
class ArrayElement : public BaseArrayElement
{
public:
    ArrayElement(T &t);
    ArrayElement(T t);
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

template <typename T>
std::string ArrayElement<T>::toJSONString()
{
	std::ostringstream oss;
	oss << "{ " << typeid(element).name() << " : " << element << " }";
	return oss.str();
}

