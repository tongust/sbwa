#ifndef PATTERNSHADOW_H
#define  PATTERNSHADOW_H



#include <iostream>

using std::cout;
using std::endl;
typedef unsigned int unint;

struct patternShadow // Auxillary class for the search
{
    patternShadow():
        period(0), Nperiod(0), lastPos(nullptr), 
        tailPos(nullptr), K(0), lenTail(0), diff(0),
        nthindex(nullptr),
        lenindex(nullptr),
        conindex(nullptr),
        lenconindex(nullptr)
    {}
    patternShadow(const unint &a1, const unint &a2):
        np(a1), period(a2), diff(a2-1)
    {
        if (a2 == 0) period = 1;
        init();
    }
    ~patternShadow()
    {
        clear();
    }
    unint period; 
    unint diff; /*permited disfferences*/
    unint np; /*length of pattern*/
    unint Nperiod; /*length of periodic pattern*/
    unint K; /* Nperiod =  K * period, the number of period */
    unint *tailPos; /*consisting the nth in the tail of pattern*/
    unint lenTail;
    unint *lastPos; /*the nth period last position*/
    unint **nthindex; /*consisting of the index for searching*/
    unint *lenindex; /*the length of nth part*/
    unint **conindex; /*continuous index of nth part*/
    unint *lenconindex;

    void clear();
    void init();
    void show();
/*
 * For exemple:
 * p = 0 1 2 3 4 5 6 7
 * np = 8
 * period = 3 
 * Npriod = 6
 * K = 2
 * tailPos ptr to [6, 7]
 * lastPos ptr to [6, 7, 5]
 */


};
void patternShadow::clear()
{
    if (lastPos)
    {
        delete[] lastPos;
        lastPos = nullptr;
    }
    if (tailPos)
    {
     
        delete[] tailPos;
        tailPos = nullptr;
    }
    if (nthindex)
    {
        for (unint i = 0; i != period; ++i)
        {
            if (nthindex[i])
                delete[] nthindex[i];
        }
        delete[] nthindex;
        nthindex = nullptr;
    }
    if (lenindex)
    {
        delete[] lenindex;
        lenindex = nullptr;
    }
    if(lenconindex)
    {
        delete[] lenconindex;
        lenconindex = nullptr;
    }
    if (conindex)
    {
        for (unint nth = 0; nth != period; ++nth)
            if (conindex[nth])
                delete[] conindex[nth];
        delete[] conindex;
        conindex = nullptr;
    }
    if (tailPos || lastPos || nthindex || lenindex || lenconindex || conindex) std::cerr << "WRONG" << "\n";
    return;
}
void patternShadow::init()
{
    lenTail = np%period;
    Nperiod = np - lenTail;
    K = Nperiod / period;
    tailPos = new unint[lenTail];
    lastPos = new unint[period];
    nthindex = new unint*[period];
    lenindex = new unint[period];
    unint **tpp = nthindex;
    unint *tp1 = nthindex[0];
    unint *lenp = lenindex;
    for (unint nth = 0; nth != period; ++nth, tpp++, lenp++)
    {
        if (nth < lenTail)
        {
            *lenp = K+1;
            *tpp = new unint[K+1];
        }
        else
        {
            *lenp = K;
            *tpp = new unint[K];
        }
        tp1 = tpp[0];
        for (unint j = 0; j != (*lenp); ++j)
        {
            *tp1 = j*period + nth;
            tp1++;
        }
    }
    {
        for (unint nth = 0; nth != period; ++nth)
        {
            if (lenTail)
            {
                lastPos[nth] = Nperiod + nth;
                if (lastPos[nth] + 1 > np)
                {
                    lastPos[nth] -= period;
                }
            }
            else
            {
                lastPos[nth] = np - period + nth;
            }
        }// end of nth iteration

        for (unint i = 0; i != lenTail; ++i)
        {
            tailPos[i] = i + Nperiod;
        }

    }// end of small block
    {// continuous index
        conindex = nullptr;
        lenconindex = new unint [period];
        conindex = new unint* [period];
        unint **tpp  = conindex;
        unint *tp1 = nullptr;
        unint *tp2 = lenconindex;
        for (unint nth = 0; nth != period; nth++)
        {
            *tp2 =  np - lenindex[nth];
            *tpp = new unint [*tp2];
            tp1 = tpp[0];
            bool mfg = false;
            for (unint i = 0; i != np; ++i)
            {
                if ((i%period) == nth) {
                    mfg = true;
                    continue;}
                if(!mfg) *tp1 = 1;
                else {*tp1 = 2;mfg = false;}
                tp1++;
            }
            tp2++;
            tpp++;
        }
    }
    return;
}
void patternShadow::show()
{
    cout << "length of pattern:\n" 
        << np 
        << "\nperiod:\n"
        << period << "\n";

    cout << "nthindex:\n";
    for (unint i = 0; i != period; ++i)
    {
        unint LMT = lenindex[i];
        unint *tp = nthindex[i];
        for (unint j = 0; j != LMT; ++j)
        {
            cout << *tp << ","; 
            tp++;
        }
        cout << "\n";
    }
    cout << "continuous index\n";
    for (unint i = 0; i != period; ++i)
    {
        unint LMT = lenconindex[i];
        unint *tp = conindex[i];
        for (unint j = 0; j != LMT; ++j)
        {
            cout << *tp << ",";
            tp++;
        }
        cout << "\n";
    }
    
    return;
}


#endif
