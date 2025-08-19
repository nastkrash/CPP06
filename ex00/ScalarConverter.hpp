#pragma once
#include <string>    // for std::string
#include <iostream>  // for std::cout
#include <iomanip>   // for std::fixed, std::setprecision
#include <cstdlib>   // for std::strtol, std::strtof, std::strtod, std::atoi
#include <cctype>    // for std::isprint, std::isdigit
#include <climits>   // for INT_MIN, INT_MAX
#include <cerrno>    // for errno
#include <cmath>     // for std::isnan, std::isinf

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter & operator= (const ScalarConverter & other);
        ~ScalarConverter();

    public:
        static void convert(const std::string& literal);  
    };