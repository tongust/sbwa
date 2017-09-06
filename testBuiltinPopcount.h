#ifndef TESTBUILTINPOPCOUNT_H
#define TESTBUILTINPOPCOUNT_H
/* GNU library built-in function, it will call the processor
 * instruction instead of function.
 * __builtin_popcountll(unsigned long long)
   __builtin_popcountl (unsigned long)
   __builtin_popcount (unsigned int x)*/

#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <time.h> // time
#include <stdlib.h> // srand, rand
#include <ctime>
#include "naiveBwt.h"
#include "verification.h"

#ifdef  BITCOUNT32
#undef  BITCOUNT32
#endif
#define BITCOUNT32(v, c) {c = (v & 0xAAAAAAAA) | ((v & 0x55555555)<<1);\
                        c = c - ((c >> 1) & 0x55555555);\
                        c = ((c >> 2) & 0x33333333) + (c & 0x33333333);\
                        c = ((c >> 4) + c) & 0x0F0F0F0F;\
                        c = ((c >> 8) + c) & 0x00FF00FF;\
                        c = ((c >> 16) + c) & 0x0000FFFF;}

#ifdef   BUILTIN_BITCOUNT32
#undef  BUILTIN_BITCOUNT32
#endif
#define  BUILTIN_BITCOUNT32(v,c) {c = (v & 0xAAAAAAAA) | ((v & 0x55555555)<<1);\
                                 c = __builtin_popcount(c);}

#ifdef  BUILTIN_BITCOUNT64
#undef  BUILTIN_BITCOUNT64
#endif
//#define BUILTIN_BITCOUNT64(v,c) {c = (v & 0xAAAAAAAAAAAAAAAA) | ((v & 0x5555555555555555)<<1);\
//                                 c = __builtin_popcountll(c);}
#define BUILTIN_BITCOUNT64(v,c) {c = (v | (v<<1)) & 0xAAAAAAAAAAAAAAAA;\
                                 c = __builtin_popcountll(c);}

using std::cout;
using std::endl;
//#define aligned_64_mem(pt, N) {mem = malloc(N+8);\
//                            pt =  (reinterpret_cast<uintptr_t>((char*)mem + 8)) & uintptr_t(0xFFFFFFFFFFFFFFF0);}
typedef unsigned int unint;
typedef unsigned long long un64_t;
inline

void testBuiltinPopcount()
{
    srand (time(nullptr));
    typedef std::chrono::milliseconds millitype;
    using std::chrono::duration_cast;
    const un64_t Ntest = 1<<28;
    cout << Ntest << " samples\n";
    std::chrono::time_point<std::chrono::system_clock> time_b, time_e;
    auto now = std::chrono::system_clock::now;
    register un64_t i = 0;
    unint c = 0;
    unint v = rand()%(1<<30);
    v = 0x1007F030;
    un64_t tmp = 0;

    c = 0;
    tmp = 0;
    time_b = now();
    {
        for(i = 0; i != Ntest; ++i)
        {   
            BUILTIN_BITCOUNT32(v, c)
            if (c>4) tmp++;
        }
        time_e = now();
        auto elapsed1 = duration_cast<millitype>(time_e - time_b).count();
        cout << "GNU elapsed time\t" << elapsed1 
            << "ms\tcounts\t" << c 
            << "\tvalue\t" << v 
            << "\ttimes\t" << tmp <<endl;
    }

    c = 0;
    tmp = 0;
    time_b = now();
    {
        for(i = 0; i != Ntest; ++i)
        {
            BITCOUNT32(v, c)
            if (c>4) tmp++;
        }
        time_e = now();
        auto elapsed1 = duration_cast<millitype>(time_e - time_b).count();
        cout << "bitcount elapsed time\t" << elapsed1 
            << "ms\tcounts\t" << c 
            << "\tvalue\t" << v 
            << "\ttimes\t" << tmp <<endl;
    }
    un64_t c64 = 0;
    un64_t v64 = rand()%(1<<30);

    c64 = 0;
    un64_t tmp64 = 0;
    time_b = now();
    {
        for(i = 0; i != Ntest; ++i)
        {
            BUILTIN_BITCOUNT64(v64, c64)
            if (c64>4) tmp64++;
        }
        time_e = now();
        auto elapsed1 = duration_cast<millitype>(time_e - time_b).count();
        cout << "GNU 64 elapsed time\t" << elapsed1 
            << "ms\tcounts\t" << c64 
            << "\tvalue\t" << v64 
            << "\ttimes\t" << tmp64 <<endl;
    }

    c64 = 5;
    tmp64 = 0;
    un64_t tmp1 = 123;
    un64_t* unl = &v64;
    un64_t* unr = &tmp1;
    time_b = now();
    {un64_t mlk = 0;
        for(i = 0; i != Ntest; ++i)
        {
            if(memcmp(unl, unr, 8))tmp64++;
        }
        time_e = now();
        auto elapsed1 = duration_cast<millitype>(time_e - time_b).count();
        cout << "memcmp 64 elapsed time\t" << elapsed1 
            << "ms\tcounts\t" << c64 
            << "\tvalue\t" << v64 
            << "\ttimes\t" << tmp64 <<endl;
    }
    return;
}
// 0xC0 = 11000000
// 0xF0 = 11110000
#define CHARPOPCOUNT64(c,v) {c = v | (v << 4);\
                             c |= c << 2;\
                             c |= c << 1;\
                             c &= 0x8080808080808080;\
                             c = __builtin_popcountll(c);}
#define CHARPOPCOUNT64_(c,v) {c = (v & 0xF0F0F0F0F0F0F0F0) | ((v & 0x0F0F0F0F0F0F0F0F)<<4);\
c = (c & 0xC0C0C0C0C0C0C0C0) | ((c & 0x3030303030303030)<<2);\
c = (c & 0x8080808080808080) | ((c & 0x4040404040404040)<<1);\
c = __builtin_popcountll(c);}
inline 
bool/*Attention the real length of char a and b should be longer than  N at least 7*/
m_charcmp64(un64_t *a, un64_t *b, const unint &N, un64_t &c)
{
    un64_t v = 0;
    un64_t tmpc = 0;

    unint res = 0;
    unint tail = N%8;
    unint Nmod = N - tail;
    unint K = N/8;
    // the tail
    un64_t * ae = a + K;
    if(tail) {
        v =  *(ae) ^ *(b+K);
        v &= 0xFFFFFFFFFFFFFFFF<<(8*(8-tail));
        CHARPOPCOUNT64(tmpc, v)
        c = tmpc;
    }
    for (; a != ae; )
    {
        v =  *(a) ^ *(b);
        CHARPOPCOUNT64(tmpc, v)
        a++;
        b++;
        c += tmpc;
    }
    if (c  == 0)
        return true;
    else
        return false;
}
inline
bool naiveCharPopcount(const char*a, const char*b, const unint& N, un64_t & c)
{
    const char *ae = a + N;
    c = 0;
    for (;a!=ae;)
    {
        if (*a != *b)
            c += 1;
        a++;
        b++;
    }
    if (c)
        return false;
    else 
        return true;
}
void testCharPopcount()
{
    srand (time(nullptr));
    typedef std::chrono::milliseconds millitype;
    using std::chrono::duration_cast;
    unint N = 1<<30;
    N += 13123;
    N *= 10;
    cout << N << " bp\n";
    std::chrono::time_point<std::chrono::system_clock> time_b, time_e;
    auto now = std::chrono::system_clock::now;
    const unint Nerr =  1000000;
    char *a = new char[N];
    char *b = new char[N];
    verifySBWA::genRandDNA(a, N);
    memcpy(b,a, N);
    for (unint i = 0; i != Nerr; ++i)
        verifySBWA::genMutateDNA(b, N);
    un64_t c = 0;
    {
        time_b = now();
        m_charcmp64((un64_t*)a, (un64_t*)b, N, c);
        time_e = now();
        auto elapsed1 = duration_cast<millitype>(time_e - time_b).count();
        cout << "GNU elapsed time\t" << elapsed1 
            << "ms\tcounts\t" << c 
            << "\n";
    }
    {
        time_b = now();
        naiveCharPopcount(a, b, N, c);
        time_e = now();
        auto elapsed1 = duration_cast<millitype>(time_e - time_b).count();
        cout << "naive elapsed time\t" << elapsed1 
            << "ms\tcounts\t" << c 
            << "\n";
    }
    delete[] a;
    delete[] b;
    return;
}

#endif /*testBuiltinPopcount_h*/
