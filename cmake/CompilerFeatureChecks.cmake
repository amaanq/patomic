function(zero_if_blank var)
    if(${var} STREQUAL "")
        set(${var} 0 PARENT_SCOPE)
    endif()
endfunction()

check_c_source_compiles(
    "int main(void) { long long x = 0; return (int)x; }"
    COMPILER_HAS_LONG_LONG
)
zero_if_blank(COMPILER_HAS_LONG_LONG)

check_c_source_compiles(
    "__forceinline static int inc(int x) { return ++x; } \n\
     int main(void) { return inc(0); }"
    COMPILER_HAS_FORCEINLINE
)
zero_if_blank(COMPILER_HAS_FORCEINLINE)

check_c_source_compiles(
    "__attribute__((always_inline)) static \n\
     int inc(int x) { return ++x; } \n\
     int main(void) { return inc(0); }"
    COMPILER_HAS_ALWAYS_INLINE_ATTR
)
zero_if_blank(COMPILER_HAS_ALWAYS_INLINE_ATTR)

check_c_source_compiles(
    "inline __attribute__((always_inline)) static \n\
     int inc(int x) { return ++x; } \n\
     int main(void) { return inc(0); }"
    COMPILER_HAS_INLINE_ALWAYS_INLINE_ATTR
)
zero_if_blank(COMPILER_HAS_INLINE_ALWAYS_INLINE_ATTR)

check_c_source_compiles(
    "int main(void) { _Alignas(_Alignof(int)) int x = 0; return x; }"
    COMPILER_HAS_ALIGNOF
)
zero_if_blank(COMPILER_HAS_ALIGNOF)

check_c_source_compiles(
    "#include <stdatomic.h> \n\
     int main(void) { return (int)sizeof(_Atomic(int)); }"
    COMPILER_HAS_STD_ATOMIC
)
zero_if_blank(COMPILER_HAS_STD_ATOMIC)

check_c_source_compiles(
    "#include <Windows.h> \n\
     #include <memoryapi.h> \n\
     int main(void) { \n\
        void* m = VirtualAlloc(NULL, 4, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE); \n\
        DWORD old; \n\
        (void) VirtualProtect(m, 4, PAGE_EXECUTE_READ, &old); \n\
        (void) VirtualFree(m, 0, MEM_DECOMMIT|MEM_RELEASE); \n\
     }"
    COMPILER_HAS_WIN32_MEMORYAPI_VIRTUAL
)
zero_if_blank(COMPILER_HAS_WIN32_MEMORYAPI_VIRTUAL)
