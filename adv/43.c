#include "myint.h"
#include "singletest.c"
static int madd(int a, int b) {
    // please match main function
    return a + b;
}
static int msub(int a, int b) {
    // please match main function
    return a - b;
}
int getmyheart(int (*FUNC[])(int, int)) {
    secret();
    test_heart();
    // set your function into FUNC[0] and FUNC[1]
    FUNC[0] = &madd;
    FUNC[1] = &msub;
    return 2;
}