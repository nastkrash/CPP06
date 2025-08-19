#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string &s)
{
    return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

static bool isInt(const std::string &s)
{
    char *end;
    errno = 0;
    long int i = std::strtol(s.c_str(), &end, 10);
    return *end == '\0' && errno == 0 && i >= INT_MIN && i <= INT_MAX;
}

static bool isFloat(const std::string &s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return true;
    char *end;
    errno = 0;
    std::strtof(s.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0' && errno == 0;
}
static bool isDouble(const std::string &s)
{
    if (s == "-inf" || s == "+inf" || s == "nan")
        return true;
    char *end;
    errno = 0;
    std::strtod(s.c_str(), &end);
    return *end == '\0' && errno == 0;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isChar(literal))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }
    else if (isInt(literal))
    {
        int i = std::atoi(literal.c_str());
        if (i >= 32 && i <= 126)
            std::cout << "char: '" << static_cast<char>(i) << "'\n";
        else
            std::cout << "char: Non displayable\n";
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
        std::cout << "double: " << static_cast<double>(i) << "\n";
    }
    else if (isFloat(literal))
    {
        float f = std::strtof(literal.c_str(), 0);
        if (std::isnan(f) || std::isinf(f))
            std::cout << "char: impossible\nint: impossible\n";
        else
        {
            if (f >= 32 && f <= 126)
                std::cout << "char: '" << static_cast<char>(f) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << static_cast<int>(f) << "\n";
        }

        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << "\n";
    }
    else if (isDouble(literal))
    {
        double d = std::strtod(literal.c_str(), 0);
        if (std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible\nint: impossible\n";
        else
        {
            if (d >= 32 && d <= 126)
                std::cout << "char: '" << static_cast<char>(d) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << static_cast<int>(d) << "\n";
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << d << "f\n";
        std::cout << "double: " << d << "\n";
    }
    else
        std::cout << "Error: Unknown literal format\n";
}