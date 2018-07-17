#include <windows.h>

inline void* lib::load(const char* p) {
    return (void*)LoadLibrary(p);
}

inline void lib::free(void* t) {
    FreeLibrary((HMODULE)t);
}

void* lib::getFunc(void* t, const char* p) {
    return GetProcAddress((HMODULE)t,p);
}