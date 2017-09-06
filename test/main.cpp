#include <iostream>
#include <string.h>
#include <stdio.h>
#include "naiveFastSort.h"
#include "testStringCompare.h"
#include "../verification.h"
#include "../sBwt.h"
#include <stdlib.h>     /* srand, rand */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using std::cout;
using std::endl;

#define M_BUF_SIZE 65536
inline void  mstrcpy(char* des,const char* source) {
    char* r=des;
    while (*source != '\0') {
        if (*source == 'N') 
            *r = 'A';
        else 
            *r = *source;
        ++r;
        ++source;
    }
    return;
}

char * readFromFq(char **argv, unsigned int &lenRead) {


    int inputFd = open(argv[1], O_RDONLY);
    int numRead  = 0;
    lseek(inputFd, 0, SEEK_SET); /* Start of file */
    off_t tlen = lseek(inputFd, -1, SEEK_END);
    lenRead = tlen;
    char * rds = new char[lenRead];
    char *p = rds;

    char buf[M_BUF_SIZE+1];
    buf[M_BUF_SIZE] = '\0';
    lseek(inputFd, 0, SEEK_SET); /* Start of file */
    while ((numRead = read(inputFd, buf, M_BUF_SIZE)) > 0) {
        if (numRead == M_BUF_SIZE) {
            mstrcpy(p,buf);
            p += M_BUF_SIZE;
        } else {
            numRead -= 1;
            buf[numRead] = '\0';
            mstrcpy(p,buf);
            break;
        }
    }
    return rds;

}

void run(int argc, char **argv)
{
    //srand (time(NULL));
    /* the total test time  */
    int N = 1000;
    N = 1;
    for (int i = 0; i != N; ++i)
    {
        unsigned int lenref = rand()%100 + 10;
        lenref = (unint)1<<30;
        lenref *= 3;
        int period  = rand()%4 + 1;
        period = 1;
#if 0
        char *ref = new char[lenref];
        verifySBWA::genRandDNA(ref, lenref);
#endif 
        char *ref = readFromFq(argv, lenref);
        sBwt sb(ref, lenref, period);
        cout << "begin" << endl;
        cout << "length\t" << lenref << endl;
        sb.buildIndexBlockwise();
        cout << "done" << endl;
        //sb.showFM();
        //cout << period << "\t";
        //for (int i =0; i != sb.N; ++i)cout << sb.X[i];
        //cout << "\t";
        //for (int i =0; i != sb.N; ++i){cout << sb.SA[i];if (i != sb.N-1)cout <<"\t";}
        //if (i+1 != N)cout << "\n";

    }
    cout << endl;
    return;
}

int main(int argc, char **argv)
{
//    unsigned int lenRead;
//    readFromFq(argv, lenRead);
    run(argc, argv);
    return 0;
}
