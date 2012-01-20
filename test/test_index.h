#include "<cxxtest/TestSuite.h>"
#include "../src/index.h"

using sphere;

class SuiteIndex : public CxxTest::TestSuite
{
public:
    void test_scale(void)
    {
        TS_ASSERT_EQUALS(scale(0), 12);
        TS_ASSERT_EQUALS(scale(1), 48);
        TS_ASSERT_EQUALS(scale(2), 192);
    }
};
