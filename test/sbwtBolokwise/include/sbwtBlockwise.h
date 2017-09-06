#ifndef SBWT_BLOCKWISE_H
#define SBWT_BLOCKWISE_H
#include "sBwt.h"

class sbwtBlockwise: public sBwt{
public:
    sbwtBlockwise(): sBwt() {};
    sbwtBlockwise(char * str, const size_t& n, const unint &per = 2):
        sBwt(str, n, per) { }
    void buildIndexBlockwise() override; /* build index blockwise  */
    /* function member  */
    ~sbwtBlockwise() = default;
};
//void sbwtBlockwise::buildIndexBlockwise() {
//    return;
//}
#endif /* SBWT_BLOCKWISE_H  */
