#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iostream>
using boost::multiprecision::cpp_dec_float_50;
template <typename T> inline T area_of_circle(T r) {
    using boost::math::constants::pi;
    return pi<T>()*r*r;
}
int main() {
    float rad_f = 123.0/100;
    float area_f = area_of_circle(rad_f);
    double rad_d = 123.0/100;
    double area_d = area_of_circle(rad_d);
    cpp_dec_float_50 rad_mp = 123.0/100;
    cpp_dec_float_50 area_mp = area_of_circle(rad_mp);
    boost::multiprecision::cpp_dec_float_100 rad_mp2 = 123.0/100;
    boost::multiprecision::cpp_dec_float_100 area_mp2 = area_of_circle(rad_mp2);

    std::cout << "Float " << std::setprecision(std::numeric_limits<float>::digits10) << area_f << '\n';
    std::cout << "Double " << std::setprecision(std::numeric_limits<double>::digits10) << area_d << '\n';
    std::cout << "Cpp_dec_float_50 " << std::setprecision(std::numeric_limits<cpp_dec_float_50>::digits10) << area_mp << '\n';
    std::cout << "Cpp_dec_float_100 " << std::setprecision(std::numeric_limits<boost::multiprecision::cpp_dec_float_100>::digits10) << area_mp2 << '\n';

}
