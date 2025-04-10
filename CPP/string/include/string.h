#pragma once
// 因为库中已经有string类 所以我们要把string类定义成namespace和库中作区分
#include <string>
namespace bit
{
    class string
    {
    public:
        string(const char *str) : _size(strlen(str)), _capacity(strlen(str)), _str(new char[_capacity + 1])
        {
            strcpy(_str, str);
        }

    private:
        size_t _size;
        size_t _capacity;
        char *_str;
    };
}