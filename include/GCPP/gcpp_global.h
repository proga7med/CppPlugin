#ifndef GCPP_GLOBAL_H
#define GCPP_GLOBAL_H

#if defined(GCPP_LIBRARY)
#  define GCPPSHARED_EXPORT __declspec(dllexport)
#else
#  define GCPPSHARED_EXPORT __declspec(dllimport)
#endif

#endif // GCPP_GLOBAL_H
