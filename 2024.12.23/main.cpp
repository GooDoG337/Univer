#include <iostream>
#include <boost/multiprecision//cpp_int.hpp>
using namespace boost::multiprecision;

int128_t boost_product(long long A, long long B) {
    int128_t ans = (int128_t)A*B;
    return ans;
}
int main()
{
    long long first = 37468798760246874;
    long long second = 4367527589754436;
    std::cout << "Product of " << first << " and " << second << " is " << boost_product(first,second);
    return 0;
}
