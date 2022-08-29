/* pragmas */
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,abm,bmi,bmi2,lzcnt,popcnt,tune=native")
//or
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("rename-registers")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")


/* allocator */
const int MAXMEM = 1e8;
char mem[MAXMEM];
int mempos = 0;
inline void * operator new(size_t n)
{
    char * cur = mem + mempos;
    mempos += n;
    assert(mempos <= MAXMEM);
    return (void*)cur;
}
inline void operator delete(void*) { };


/* strange floating-point optimization */
#include <xmmintrin.h>
int main() {
    _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
}
