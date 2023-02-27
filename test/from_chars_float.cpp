// Copyright 2023 Matt Borland
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/charconv.hpp>
#include <boost/core/lightweight_test.hpp>
#include <type_traits>
#include <limits>
#include <cstring>
#include <cstdint>
#include <cerrno>
#include <utility>

template <typename T>
void simple_integer_test()
{
    const char* buffer1 = "12";
    T v1 = 0;
    auto r1 = boost::charconv::from_chars(buffer1, buffer1 + std::strlen(buffer1), v1);
    BOOST_TEST_EQ(r1.ec, 0);
    BOOST_TEST_EQ(v1, static_cast<T>(12));

    const char* buffer2 = "1200";
    T v2 = 0;
    auto r2 = boost::charconv::from_chars(buffer2, buffer2 + std::strlen(buffer2), v2);
    BOOST_TEST_EQ(r2.ec, 0);
    BOOST_TEST_EQ(v2, static_cast<T>(1200));
}

template <typename T>
void simple_hex_integer_test()
{
    const char* buffer1 = "-2a";
    T v1 = 0;
    auto r1 = boost::charconv::from_chars(buffer1, buffer1 + std::strlen(buffer1), v1, boost::charconv::chars_format::hex);
    BOOST_TEST_EQ(r1.ec, 0);
    BOOST_TEST_EQ(v1, static_cast<T>(-42));
}

int main()
{
    simple_integer_test<float>();
    simple_integer_test<double>();
    
    simple_hex_integer_test<float>();
    simple_hex_integer_test<double>();

    return boost::report_errors();
}
