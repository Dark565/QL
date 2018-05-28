#include <Files/files.hpp>

#include <string.h>

std::string ql::readFormat(const char* format) {
    const char* f2 = format;
    while(*f2 != '\0') {
        if(*f2 == '.') return readFormat(f2+1);
        f2++;
    }
    return std::string(format);
}
