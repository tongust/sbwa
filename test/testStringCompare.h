#ifndef TESTSTRINGCOMPARE_H
#define  TESTSTRINGCOMPARE_H
#include "../verification.h"
#include "../patternShadow.h"
#include <time.h> // time
#include <stdlib.h> // srand, rand

#include <string.h>

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif



#include <iostream>
#include <chrono>
#include <ctime>

using std::chrono::duration;
using std::cout;
using std::endl;
typedef unsigned int unint;
struct bruteForceMatch
{
    static unint method1(const char*, 
            const char*, const unint&, 
            const patternShadow& );
};
inline
unint bruteForceMatch::method1(
        const char *Xb,
        const char *P, 
        const unint& nth, 
        const patternShadow& pS )
{
    unint mcount = 0;
    const char *ref = Xb-1;
    const char *query = P-1;
    unint tmp1 = 0;
    unint pos = 0;
    unint *mindex =  pS.conindex[nth];
    unint lenindex = pS.lenindex[nth];
    unint *mi_b = mindex,
          *mi_e = mindex+lenindex;
    for(;mi_b != mi_e; )
    {
        tmp1 = *mi_b;
        ref += tmp1;
        query += tmp1;
        cout << "-"<<*ref<<","<<*query<<"-";
        if (*ref != *query)
        {
            mcount++;
            if (mcount>pS.diff)
                return mcount;
        }
        mi_b++;
    }
    return mcount;
    // check the tail of P
    {
        for (unint i = 0; i != pS.lenTail; ++i)
        {
            pos = pS.tailPos[i];
            ref += pos;
            query += pos;
            if (*ref != *query)
                mcount++;
        }
        if (mcount == pS.diff)
        {
            if(memcmp(Xb, P, pS.Nperiod) == 0)
                return true;
            else
                return false;
        }
    }
    // check the periodic string
    {
        ref = Xb + nth;
        query = P + nth;
        for (unint i = 0; i != pS.K; ++i)
        {
            for (unint j = 0; j != pS.period; ++j)
            {
                 if (j==nth)continue;
            }
            ref += nth;
            query += nth;
        }
    }
    return 0;
}




void testStrCmp()
{ 
    srand (time(nullptr));
	std::chrono::time_point<std::chrono::system_clock> time_b, time_e;
    time_b = std::chrono::system_clock::now();
    auto genstr = verifySBWA::genRandDNA;
    unint N = 100000000;// 100M
    char *ref = new char[N+1];
    unint np = rand()%10+10;
    char *query = new char [np+1];
    genstr(ref, N);
    unint offset = rand()%(N-np);
    memcpy(query, ref+offset, np*sizeof(char));
    char * ref_b = ref,
         *ref_e = ref+N;
    for (char *tp = ref_b; tp != ref_e; tp++)
    {
//        cout << char(*tp);
    }
	time_e = std::chrono::system_clock::now();
	auto elapsed1 =  std::chrono::duration_cast
						<std::chrono::milliseconds>(time_e - time_b).count();
    char *qb = query, 
         *qe = query + np,
         *qt = query;
    while(qt!=qe)
    {
        cout << *qt;
        qt++;
    }

    // search
    unint period  = 3;
    patternShadow pS(np, period);
    pS.show();
    cout << "\ndiff: \t" << bruteForceMatch::method1(ref+offset, query, 0, pS) <<"\t"<< pS.diff<< "\n";
    for (unint i = offset; i != np+offset; ++i)cout << ref[i];cout << "\n";
    for (unint i = 0; i != np; ++i)cout << query[i];cout << "\n";
    // deletes
    delete[] query;
    delete[] ref;
    return;
}

#endif
