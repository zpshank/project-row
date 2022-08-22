#include "utest.h"
#include "boat.h"

UTEST_MAIN()

UTEST(test, foo) {
    boat_t b = {0};
    EXPECT_EQ(0, b.x);
    update_boat(&b);
}