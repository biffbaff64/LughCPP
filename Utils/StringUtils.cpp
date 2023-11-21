#include "StringUtils.h"

std::vector< std::string > StringUtils::Split( const char* str, const char separator )
{
    const std::string s = str;

    return Split( s, separator );
}

std::vector< std::string > StringUtils::Split( const std::string &str, const char separator )
{
    std::vector< std::string > strings;

    int startIndex = 0;
    int endIndex   = 0;

    for (int i = 0; i <= str.size(); i++)
    {
        if (str[ i ] == separator || i == str.size())
        {
            endIndex = i;
            std::string temp;

            temp.append(str, startIndex, endIndex - startIndex);

            strings.push_back(temp);

            startIndex = endIndex + 1;
        }
    }

    return strings;
}
