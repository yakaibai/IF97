#ifdef _WIN32  
    /* You should define IF97EXPORTS *only* when building the DLL. */  
    #ifdef IF97EXPORTS  
        #define IF97API __declspec(dllexport)  
    #else  
        #define IF97API __declspec(dllimport)  
    #endif
    /* Define calling convention in one place, for convenience. */  
    #define IF97CALL __cdecl
#else /* _WIN32 not defined. */  
    /* Define with no value on non-Windows OSes. */
    #define IF97API
    #define IF97CALL
#endif
//
#define IF97INT IF97API int IF97CALL
#define IF97DOUBLE IF97API double IF97CALL
#define IF97VOID IF97API void IF97CALL