#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN_1(V,W) \
        ((V) < (W)?(V):(W))
#define MIN(X,Y,Z) \
        (MIN_1(X,Y) < (Z)?MIN_1(X,Y):(Z))

void getInput();
