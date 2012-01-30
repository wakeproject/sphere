#include "src/sphere-field.h"
#include <cxxtest/TestSuite.h>

using namespace sphere;

class SuiteField : public CxxTest::TestSuite
{

public:
    void test_constructor(void)
    {
        ScalarField* field = new ScalarField(0, 1);
        TS_ASSERT_EQUALS((*field)[0], 1);
        TS_ASSERT_EQUALS((*field)[1], 1);
        TS_ASSERT_EQUALS((*field)[2], 1);
        TS_ASSERT_EQUALS((*field)[3], 1);
        TS_ASSERT_EQUALS((*field)[4], 1);
        TS_ASSERT_EQUALS((*field)[5], 1);
        TS_ASSERT_EQUALS((*field)[6], 1);
        TS_ASSERT_EQUALS((*field)[7], 1);
        TS_ASSERT_EQUALS((*field)[8], 1);
        TS_ASSERT_EQUALS((*field)[9], 1);
        TS_ASSERT_EQUALS((*field)[10], 1);
        TS_ASSERT_EQUALS((*field)[11], 1);
    }

    void test_lhs(void)
    {
        ScalarField* field = new ScalarField(0, 1);
        (*field)[3] = 3;
        (*field)[6] = 6;
        (*field)[9] = 9;
        TS_ASSERT_EQUALS((*field)[3], 3);
        TS_ASSERT_EQUALS((*field)[6], 6);
        TS_ASSERT_EQUALS((*field)[9], 9);
    }
};
