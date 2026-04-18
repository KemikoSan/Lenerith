#pragma once

#ifdef _WIN32
#ifdef LENERITH_EXPORT
#define LENERITH_API __declspec(dllexport)
#else
#define LENERITH_API __declspec(dllimport)
#endif
#else
#define LENERITH_API
#endif
