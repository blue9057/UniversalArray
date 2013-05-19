#include "UniversalArray.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <complex>

using namespace std;
int main()
{
    universal::array v;
    ArrayElement<int> aeint(1);
    ArrayElement<string> aestring(string("str"));
    ArrayElement<char*> aechar(const_cast<char*>("asdf"));
    ArrayElement<double> aedouble(3.14);
    ArrayElement<complex<double> > aecomplex(complex<double>(2.7, 3.1));
    v.push_back(&aeint);
    v.push_back(&aestring);
    v.push_back(&aechar);
    v.push_back(&aedouble);
    v.push_back(&aecomplex);

    for(universal::array::iterator it = v.begin(); it != v.end(); ++it)
    {
    	cout << (*it)->toJSONString() << endl;
    }
}
