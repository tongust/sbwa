#ifndef SBWT_H
#define SBWT_H
#include <numeric>
#include <chrono>

#include <vector>
#include <cstring>
#include <vector> // std::begin()
#include <time.h> // time
#include <stdlib.h> // srand, rand
#include <tuple>
#include <map>
//#include <unordered_map>
#include <iostream>
#include <memory>
#include <string.h> /*strcmp memcmp*/
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include "patternShadow.h"
#include "verification.h"
using std::vector;
using std::tuple;
using std::map;
using std::shared_ptr;
using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::system_clock;

//using std::unordered_map
typedef unsigned int unint;
typedef vector<unint> vunint;
typedef vector<char *> vcharp;
class sBwt
{   
public:
   sBwt():
        period(2), 
        N(0), 
        X(nullptr), 
        SA(nullptr), 
        B(nullptr), 
        bigO(nullptr), 
        num_dollar(2),
        num_block(4)
    {
        bigC[0] =  bigC[1] =  bigC[2] = bigC[3] = 0; 
    }
    sBwt(char * str, const size_t& n, const unint &per = 2, const unint &nb = 4): 
        X(str), N(n), period(per), num_block(nb)
    {  
		 // reallocate the memory of X
         num_dollar = period - (N%period);
         N += num_dollar;
         X = (char *)realloc(str, N*sizeof(char));
         for (unint i = 0; i != num_dollar; i++)
         {
             X[N-i-1] = '$';
         }		 
         bigC[0] =  bigC[1] =  bigC[2] = bigC[3] = 0; 
         bigO = new unint*[4];///////////////new
         for (int i = 0; i != 4; ++i)
         {
             bigO[i] = new unint[N]();//////////new
             bigO[i][0] = 0;
         }
         SA = new unint[N];////////////////new new
         B = new char[N]; /////////////////new
         // initialize SA with 0,1,...,N-1
         for (size_t i = 0; i != N; ++i)
             {SA[i] = i;}
        
    }
    virtual ~sBwt()
    {
       // cout << endl;for (int i = 0; i != N; ++i)cout << X[i] << ", ";
        if (X)
            delete[] X;
        if (SA)
            delete[] SA;
        if (bigO) {
            for (int i = 0; i != 4; ++i)
            {
                if (bigO[i])
                    delete[] bigO[i];
            }
            delete[] bigO;
        }
        if (B)
            delete[] B;
    }
public: /* function member */
	void sort(const char *x, unint *xindex, unint beg, unint end, unint depth, const unint &len_x, const unint &);
    void sort(unint beg, unint end, unint depth, const unint &len_x, const unint &);
    void sort();
    inline
    void vecswap(unint, unint, unint,  unint *);
    void sBWT();
    void calBigOC();
    void showFM();
    void buildIndex();
    void buildIndexBlockwise();     /* build the index blockwise for large genomes */
    bool spacedBackwardSearch(const char *, const unint&, vunint &);
    bool spacedBackwardSearch(const char *, const unint&, vcharp &, const unint&);
    bool ckMatch(const char*, const char *,/*pattern*/const unint &/*nth part*/, const patternShadow &);
public: /* variables member */
    unint period;       /* the period for spaced BWT */
    unint num_dollar;   /* the number of $ to append at the end of reference */
    unint N;            /* the length of reference */
    char *X;            /* the reference reads */
    unint *SA;          /* Suffix Array */
    char *B;            /* the transformed reference */
    unint **bigO;       /* Occurency */
    unint bigC[4];      /* the bigC, from the First column of bwt matrix */
    unint num_block;    /* the number of block, eg. 4 for 256 pieces*/
protected:
    static map<char, int> base2num;     /* {{'A', 0},{'C', 1},{'G', 2},{'T',3}} */
    static const char num2base[5];      /* {'A','C','G','T'};*/
    
};
/*=======================Definition of Member===============================*/
#define MY_DEBUG_MSG 0
using std::cout;
using std::endl;
#define swap(beg, a) {auto tmpv = xindex[beg];\
        xindex[beg] = xindex[a];\
        xindex[a] = tmpv;}
#define i2c(i) ((i)>=len_x?'$':x[(i)])
#define min(a, b) (a)>(b)?(b):(a)
#define max(a, b) (a)<(b)?(b):(a)
#define coutputXin(ap, N) {for (int i =0; i != (N);++i) cout << (ap)[i]<<"("<<char(i2c((xindex[i]+depth)))<<") ,";cout << endl;}
// static member have to be defined outside the class body.
std::map<char, int> sBwt::base2num = {{'A', 0},{'C', 1},{'G', 2},{'T',3}};
const char sBwt::num2base[5] = "ACGT";
inline 
void sBwt::vecswap(unint i, unint j, unint n,  unint *xindex)
{
    while (n-- > 0)
    {
        swap(i, j);
        i++;
        j++;
    }
    return;
}
void sBwt::sort(const char *x, unint *xindex, unint beg, unint end, unint depth, const unint &len_x, const unint &step)
{
//    static unint mccc = 0;mccc++;if (mccc == 3)return;
    if (beg+1>= end || depth >= len_x)
    {   
        return;
    }
//    int a = 0,b = 0,c = 0,d = 0,r = 0,v = 0, diff_be = 0; // old parameter
    long long a = 0,b = 0,c = 0,d = 0,r = 0,v = 0, diff_be = 0;
    unint tmpv = 0, tmpv1 = 0;
#if MY_DEBUG_MSG
    static int mtr = 0;
    mtr++;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ " << mtr << endl;
    cout << beg << "---------depth:"<<depth<<"-------------"  << end << endl;
    coutputXin(xindex,len_x);
#endif
    diff_be  = end - beg;
    a = (rand() % diff_be) + beg;
    swap(beg, a);  

#if MY_DEBUG_MSG
    coutputXin(xindex,len_x);
#endif
    tmpv1 = xindex[beg]+depth;
    v = i2c(tmpv1);
    a = b = beg+1;
    c = d = end-1;
    for(;;)
    {
        while (b <= c && (tmpv1 = xindex[b]+depth, r = i2c(tmpv1) - v) <= 0)
        {
            if (r == 0)
            {
                swap(a,b);
                a++;
            }
            b++;
        }

        while (b <= c && (tmpv1 = xindex[c]+depth, r = i2c(tmpv1) - v) >= 0)
        {
            if (r == 0)
            {
                swap(c, d);
                d--;
            }
            c--;
        }
        if (b > c)
            break;
        swap(b, c);
        b++;
        c--;
    }
    r = min(a-beg, b-a);
    vecswap(beg, b-r, r, xindex);
    r = min(d-c, end-1-d);
    vecswap(b, end-r, r, xindex);
    r = b-a+beg;
#if MY_DEBUG_MSG
    cout <<" after set the middle, before <= region-----v "<<char(v)<<endl;coutputXin(xindex,len_x);
    cout << "::::::::::::::::<= region::::::::::::::::::::::" << beg<< ", " << r << ", "<< depth << endl;
#endif
    sort(x, xindex, beg, r, depth, len_x, step);
#if MY_DEBUG_MSG
    cout <<"After <= region "<<endl;coutputXin(xindex,len_x);
#endif
    tmpv1 = xindex[r] + depth;
//    if ((tmpv1 = xindex[r]+depth, i2c(tmpv1)) != '\0' && tmpv1 < len_x) /////////////////////////////////////////////////debuging
    if(tmpv1 < len_x)
    {
#if MY_DEBUG_MSG
        cout << "a" << a <<", b" << b << ", c"<< c << ", d" << d << ", beg"<< beg << ", end" << end;
        cout << "::::::::::::::::== region::::::::::::::::::::::" << r<< ", " << (end-d+c)<<", "<< depth << endl;
#endif
        sort(x, xindex, r, end-d+c/*a+(end-d-1)*/, depth+step, len_x, step);
#if MY_DEBUG_MSG
        cout <<"After == region "<<endl;coutputXin(xindex,len_x);
#endif
    }
    r = d - c;
#if MY_DEBUG_MSG
    cout << "a" << a <<", b" << b << ", c"<< c << ", d" << d << ", beg"<< beg << ", end" << end;
    cout << "::::::::::::::::::::::>= region::::::::::::::::" << (end-r)<< ", " << end << ", "<< depth << endl;
#endif
    sort(x, xindex, end-r, end, depth, len_x, step);
#if MY_DEBUG_MSG
    cout <<"After >= region "<<endl;coutputXin(xindex,len_x);
#endif
    return;    
}
void sBwt::sort()
{
    return sort(X, SA, 0, N, 0, N, period);
}

void sBwt::sBWT()
{
    if(!B)return;
    unint tmp = 0;
    for (size_t i = 0; i != N; i++)
        {
            tmp = SA[i];
            if (tmp < period)
            {
#if DEBUG_SBWT
                cout << __LINE__ << "\t" << i
                     << "\t" << tmp << "\n";
#endif
                B[i] = '$';
            }
            else
            {
#if DEBUG_SBWT
            cout << __LINE__ << "\t" << i
                 << "\t" << tmp << "\n";
#endif
                B[i] = X[tmp-period];
            }
        }
    return;
}
void sBwt::calBigOC()
{
    if(!B)return;
    switch (B[0]) {
        case 'A':
            bigO[0][0] = 1;
            bigC[0]++;
            break;
        case 'C':
            bigO[1][0] = 1;
            bigC[1]++;
            break;
        case 'G':
            bigO[2][0] = 1;
            bigC[2]++;
            break;
        case 'T':
            bigO[3][0] = 1;
            break;
        default:
            break;
    }
#ifndef CODEBIGO
#define CODEBIGO() {bigO[0][i] = bigO[0][i-1];\
                bigO[1][i] = bigO[1][i-1];\
                bigO[2][i] = bigO[2][i-1];\
                bigO[3][i] = bigO[3][i-1];} 
#endif
    {
        /* A, C, G, T */
        for (size_t i = 1; i < N; ++i) {
            switch (B[i]) {
                case 'A': 
                    CODEBIGO();
                    bigC[0]++;
                    bigO[0][i] = bigO[0][i-1] + 1;
                    break;
                case 'C': 
                    CODEBIGO();
                    bigC[1]++;
                    bigO[1][i] = bigO[1][i-1] + 1;
                    break;
                case 'G': 
                    CODEBIGO();
                    bigC[2]++;
                    bigO[2][i] = bigO[2][i-1] + 1;
                    break;
                case 'T': 
                    CODEBIGO();
                    bigO[3][i] = bigO[3][i-1] + 1;
                    break;
                default:
                    CODEBIGO();
                    break;
            }

        }
        bigC[3]=bigC[0]+bigC[1]+bigC[2];
        bigC[2]=bigC[0]+bigC[1];
        bigC[1]=bigC[0];
        bigC[0]=0;
    } // End of calculating big-o and big-c
    return;
}
void sBwt::showFM() {
    auto count10 = [](unint i)->unint{
        unint res = 0;
        for (;;) {
            i /= 10;
            if (i==0)break;
            res++;
        }
        return res;
    };
    if (!X || !SA)return;
    cout << "\nRef: "<<endl;
    for (int i = 0; i != N; ++i)cout << X[i];
    std::cout << endl << "i\tSA\tFM\tBWT\n \t ";
    int tcc = 0;
    for (unint i = 0; i != N; ++i)
    {
        if (i%5 == 0) {
            cout << "\t" <<  i;
            tcc = count10(i);
        }
        else {
            if (tcc<=0)
            cout << " ";
            else tcc--;
        }
    }cout << endl;
    for (unint i = 0; i != N; ++i) {
        cout << i << "\t" << SA[i] <<"\t";
        unint j = 0;
        for (j = 0; j < N-1; ++j) {
            if (j && j%5 == 0)cout << "\t";
            cout << X[(j+SA[i])%N];
        }
        j = N - 1; 
        if (j%5 == 0)cout << "\t";
        cout << "" << X[(j+SA[i])%N];
        cout << endl;
    }
    cout << "\nspaced BWT:\n";
    for (unint i = 0; i != N-1; ++i) {
        cout << B[i] << ",";
    }
    cout << B[N-1] << "\n";
    cout << "Occ\nA\tC\tG\tT\n";
    for (int i = 0; i != 4; i++)
        cout << bigC[i] << "\t";
    cout << "\nOcc\nindex\tA\tC\tG\tT\n";
    for (unint i = 0; i != N; ++i) {
        cout << i << "\t";
        for (int j = 0; j != 4; ++j)
            cout << bigO[j][i] << "\t";
        cout << "\n";
    }
    return;
}
void sBwt::buildIndex() {
    if(SA && X)
    {
        sort();
        sBWT();
        calBigOC();
    }
    return;
}
inline
bool sBwt::spacedBackwardSearch(
        const char *P, 
        const unint& len_p, 
        vcharp & res,
        const unint &nth)
{
    res.clear(); 
    const char *pb = P + nth;
    const char *pe = nullptr;
    unint ned = 0;
    {// assigned the end of the pointer. 
        unint tmp1 = len_p%period;
        if (tmp1)// tmp1 != 0
        {
            ned = len_p - (len_p%period) + nth;
            if (ned + 1 > len_p) {
                ned -= period;
            }
            pe = P + ned;
        } else {
            ned = len_p - period + nth;
            pe = P + ned;
        }
    }
    char a;
    unint L= 0, R = N-1;
    for (unint i = 0; i <= ned; i += nth, pe -= nth) { 
        a = *pe;
        L = bigC[base2num[a]] 
            + (L==0?0:bigO[base2num[a]][L-1])+1;
        R = bigC[base2num[a]] 
            + bigO[base2num[a]][R];
        if (L>R) return false;
    }
    if (L <= R) {
        res.resize(R-L+1, nullptr);
        unint LIMT = R-L+1;
        auto iter = res.begin();
        for (unint i = 0; i != LIMT; ++i) {
            iter += i;
            *iter = X + SA[L+i];
        }
        return true;
    } else return false;
}
bool sBwt::ckMatch(
        const char * Xb/*the start position of reference to match*/,
        const char * P/*Pattern*/,
        const unint & nth/*nth part*/,
        const patternShadow& pS)
{
// method one
#if 1
    unint mcount = 0;
    const char *ref = Xb;
    const char *query = P;
    unint pos = 0;
    // check the tail of P
    {
        for (unint i = 0; i != pS.lenTail; ++i) {
            pos = pS.tailPos[i];
            ref += pos;
            query += pos;
            if (*ref != *query)
                mcount++;
        }
        if (mcount == pS.diff) {
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
        for (unint i = 0; i != pS.K; ++i) {
            for (unint j = 0; j != period; ++j) {
                 if (j==nth)continue;
            }
            ref += nth;
            query += nth;
        }
    }

#endif
}
bool sBwt::spacedBackwardSearch(
        const char * p, 
        const unint& num_p,
        vunint &res)
{
    // report all results

    return (!res.empty());
}
void testSBwt() {
    const unint N = 1<<25;
    const unint len_p = 10;
    char *ref = new char[N];
    char *X = new char[len_p];
    verifySBWA::genRandDNA(ref, N);
    //for (int i =0; i != N; ++i)cout << ref[i];
    sBwt sb(ref, N, 12);
    sb.buildIndex();
    cout <<"endof "<<N<<endl;
    return;
    sb.showFM();
    char *a = new char[4];
    a[0] = '1',a[1] = '2',a[2] = '3';
    char *b = new char[6];
    b[0] = '0',b[1] = '2',b[2] = 'w';
    unsigned char ac = 255;
    delete [] a;    delete[] b;
    patternShadow ps(19, 5);
    ps.show();
    return;
}
 /* build the index blockwise for large genomes */
void sBwt::buildIndexBlockwise()
{
    auto start_time = system_clock::now();
    sort(0/* begin */, N/* end */, 0/*depth*/, N/*length of reference*/, period/*period*/); // block wise
    {
        sort(X, SA, 0, 1, num_block, N, period);
        vector<char> tmpcv(num_block, '\0');
        unint j = 0;
        unint t0 = 0;
        bool flg = 0;
        unint beg0 = 0, end0 = 1;
        for (j = 0; j < num_block; ++j) {
            tmpcv[j] = X[(j*num_block+SA[0])%N];
        }
        for (unint i = 1; i < N; ++i) {
            flg = true;
            for (j = 0; j < num_block; ++j)
            {
                t0 = (j*period+SA[i]) % N;
                if (X[t0] != tmpcv[j] && flg) {
                    flg = false;
                }
                tmpcv[j] = X[t0];//X[(j*num_block+SA[i])%N];
            }
            if (!flg) {
                end0 = i;
                if (end0-beg0 > 1) {
                    sort(X, SA, beg0, end0, num_block, N, period);
                }
                beg0 = i;
            }
        }
    }
    sBWT();
    calBigOC();
//    showFM();
    auto end_time = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end_time-start_time;
    std::cout << "elapsed time\t" 
             << diff.count() << " s\n";
    return;
}

void sBwt::sort(unint beg, unint end, unint depth, const unint &len_x, const unint &step)
{
    char *x = X;
    auto xindex = SA;
    if (depth >= num_block)return;
    if (beg+1>= end || depth >= len_x) {   
        return;
    }
    //int a = 0,b = 0,c = 0,d = 0,r = 0,v = 0, diff_be = 0; // Old parameter
    long long a = 0,b = 0,c = 0,d = 0,r = 0,v = 0, diff_be = 0;

    unint tmpv = 0, tmpv1 = 0;
#if MY_DEBUG_MSG
    static int mtr = 0;
    mtr++;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ " << mtr << endl;
    cout << beg << "---------depth:"<<depth<<"-------------"  << end << endl;
    coutputXin(SA,len_x);
#endif
    diff_be  = end - beg;
    a = (rand() % diff_be) + beg;
    swap(beg, a);  

#if MY_DEBUG_MSG
    coutputXin(SA,len_x);
#endif
    tmpv1 = SA[beg]+depth;
    v = i2c(tmpv1);
    a = b = beg+1;
    c = d = end-1;
    for(;;) {
        while (b <= c && (tmpv1 = SA[b]+depth, r = i2c(tmpv1) - v) <= 0) {
            if (r == 0) {
                swap(a,b);
                a++;
            }
            b++;
        }

        while (b <= c && (tmpv1 = SA[c]+depth, r = i2c(tmpv1) - v) >= 0) {
            if (r == 0) {
                swap(c, d);
                d--;
            }
            c--;
        }
        if (b > c)
            break;
        swap(b, c);
        b++;
        c--;
    }
    r = min(a-beg, b-a);
    vecswap(beg, b-r, r, SA);
    r = min(d-c, end-1-d);
    vecswap(b, end-r, r, SA);
    r = b-a+beg;
#if MY_DEBUG_MSG
    cout <<" after set the middle, before <= region-----v "<<char(v)<<endl;coutputXin(SA,len_x);
    cout << "::::::::::::::::<= region::::::::::::::::::::::" << beg<< ", " << r << ", "<< depth << endl;
#endif
    sort(beg, r, depth, len_x, step);
#if MY_DEBUG_MSG
    cout <<"After <= region "<<endl;coutputXin(SA,len_x);
#endif
    tmpv1 = SA[r] + depth;
//    if ((tmpv1 = SA[r]+depth, i2c(tmpv1)) != '\0' && tmpv1 < len_x) /////////////////////////////////////////////////debuging
    if(tmpv1 < len_x)
    {
#if MY_DEBUG_MSG
        cout << "a" << a <<", b" << b << ", c"<< c << ", d" << d << ", beg"<< beg << ", end" << end;
        cout << "::::::::::::::::== region::::::::::::::::::::::" << r<< ", " << (end-d+c)<<", "<< depth << endl;
#endif
        sort(r, end-d+c/*a+(end-d-1)*/, depth+step, len_x, step);
#if MY_DEBUG_MSG
        cout <<"After == region "<<endl;coutputXin(SA,len_x);
#endif
    }
    r = d - c;
#if MY_DEBUG_MSG
    cout << "a" << a <<", b" << b << ", c"<< c << ", d" << d << ", beg"<< beg << ", end" << end;
    cout << "::::::::::::::::::::::>= region::::::::::::::::" << (end-r)<< ", " << end << ", "<< depth << endl;
#endif
    sort(end-r, end, depth, len_x, step);
#if MY_DEBUG_MSG
    cout <<"After >= region "<<endl;coutputXin(SA,len_x);
#endif
    return;    
}
#endif
