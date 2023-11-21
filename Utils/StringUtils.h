#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>
#include <vector>

class StringUtils
{
public:
    StringUtils() = default;
    ~StringUtils() = default;

    static std::vector< std::string > Split( const char* str, char separator );
    static std::vector< std::string > Split( const std::string &str, char separator );
};

#endif //STRINGUTILS_H
