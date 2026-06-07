#define TEC_IMPLEMENTATION

#include "tec.h"


TEC(addition, test_addition)
{
    TEC_ASSERT_EQ(2 + 2, 4);
    TEC_ASSERT_NE(2 + 2, 5);
}

TEC_MAIN();
