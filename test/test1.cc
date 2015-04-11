#include "UniversalArray.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <complex>

using namespace std;
int main()
{
    Universal::array v;
    ArrayElement<int> aeint(1);
    ArrayElement<unsigned long long> aeull(123456789010111213llu);
    ArrayElement<string> aestring(string("str"));
    ArrayElement<char> aechar('a');
    ArrayElement<float> aefloat(3.14159265358979f);
    ArrayElement<double> aedouble(3.14159265358979);
    ArrayElement<complex<double> > aecomplex(complex<double>(2.7, 3.1));
    v.push_back(&aeint);
    v.push_back(&aeull);
    v.push_back(&aestring);
    v.push_back(&aechar);
    v.push_back(&aefloat);
    v.push_back(&aedouble);
    v.push_back(&aecomplex);

    for(auto it = v.begin(); it != v.end(); ++it)
    {
    	cout << (*it)->toJSONString() << endl;
    }
}
