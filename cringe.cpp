/* pragmas */
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,bmi,bmi2")


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
