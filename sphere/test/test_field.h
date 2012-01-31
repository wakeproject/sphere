#include "src/sphere-field.h"
#include <cxxtest/TestSuite.h>

using namespace sphere;

class SuiteField : public CxxTest::TestSuite
{

public:
    void test_constructor(void)
    {
        ScalarField field = ScalarField(0, 1);
        TS_ASSERT_EQUALS(field[0], 1);
        TS_ASSERT_EQUALS(field[1], 1);
        TS_ASSERT_EQUALS(field[2], 1);
        TS_ASSERT_EQUALS(field[3], 1);
        TS_ASSERT_EQUALS(field[4], 1);
        TS_ASSERT_EQUALS(field[5], 1);
        TS_ASSERT_EQUALS(field[6], 1);
        TS_ASSERT_EQUALS(field[7], 1);
        TS_ASSERT_EQUALS(field[8], 1);
        TS_ASSERT_EQUALS(field[9], 1);
        TS_ASSERT_EQUALS(field[10], 1);
        TS_ASSERT_EQUALS(field[11], 1);
    }

    void test_bracket_lhs(void)
    {
        ScalarField field = ScalarField(0, 1);
        field[3] = 3;
        field[6] = 6;
        field[9] = 9;
        TS_ASSERT_EQUALS(field[0], 1);
        TS_ASSERT_EQUALS(field[1], 1);
        TS_ASSERT_EQUALS(field[2], 1);
        TS_ASSERT_EQUALS(field[3], 3);
        TS_ASSERT_EQUALS(field[4], 1);
        TS_ASSERT_EQUALS(field[5], 1);
        TS_ASSERT_EQUALS(field[6], 6);
        TS_ASSERT_EQUALS(field[7], 1);
        TS_ASSERT_EQUALS(field[8], 1);
        TS_ASSERT_EQUALS(field[9], 9);
        TS_ASSERT_EQUALS(field[10], 1);
        TS_ASSERT_EQUALS(field[11], 1);
    }

    void test_assignment(void)
    {
        ScalarField* field1 = new ScalarField(0, 1);
        ScalarField* field2 = new ScalarField(0, 2);
        (*field1) = (*field2);
        (*field1)[3] = 3;
        (*field1)[6] = 6;
        (*field1)[9] = 9;
        TS_ASSERT_EQUALS((*field1)[0], 2);
        TS_ASSERT_EQUALS((*field1)[1], 2);
        TS_ASSERT_EQUALS((*field1)[2], 2);
        TS_ASSERT_EQUALS((*field1)[3], 3);
        TS_ASSERT_EQUALS((*field1)[4], 2);
        TS_ASSERT_EQUALS((*field1)[5], 2);
        TS_ASSERT_EQUALS((*field1)[6], 6);
        TS_ASSERT_EQUALS((*field1)[7], 2);
        TS_ASSERT_EQUALS((*field1)[8], 2);
        TS_ASSERT_EQUALS((*field1)[9], 9);
        TS_ASSERT_EQUALS((*field1)[10], 2);
        TS_ASSERT_EQUALS((*field1)[11], 2);
        TS_ASSERT_EQUALS((*field2)[0], 2);
        TS_ASSERT_EQUALS((*field2)[1], 2);
        TS_ASSERT_EQUALS((*field2)[2], 2);
        TS_ASSERT_EQUALS((*field2)[3], 2);
        TS_ASSERT_EQUALS((*field2)[4], 2);
        TS_ASSERT_EQUALS((*field2)[5], 2);
        TS_ASSERT_EQUALS((*field2)[6], 2);
        TS_ASSERT_EQUALS((*field2)[7], 2);
        TS_ASSERT_EQUALS((*field2)[8], 2);
        TS_ASSERT_EQUALS((*field2)[9], 2);
        TS_ASSERT_EQUALS((*field2)[10], 2);
        TS_ASSERT_EQUALS((*field2)[11], 2);
    }

    void test_add(void)
    {
        ScalarField* field1 = new ScalarField(0, 1);
        ScalarField* field2 = new ScalarField(0, 2);
        ScalarField field = (*field1) + (*field2);
        TS_ASSERT_EQUALS(field[0], 3);
        TS_ASSERT_EQUALS(field[1], 3);
        TS_ASSERT_EQUALS(field[2], 3);
        TS_ASSERT_EQUALS(field[3], 3);
        TS_ASSERT_EQUALS(field[4], 3);
        TS_ASSERT_EQUALS(field[5], 3);
        TS_ASSERT_EQUALS(field[6], 3);
        TS_ASSERT_EQUALS(field[7], 3);
        TS_ASSERT_EQUALS(field[8], 3);
        TS_ASSERT_EQUALS(field[9], 3);
        TS_ASSERT_EQUALS(field[10], 3);
        TS_ASSERT_EQUALS(field[11], 3);
    }

    void test_minus(void)
    {
        ScalarField* field1 = new ScalarField(0, 5);
        ScalarField* field2 = new ScalarField(0, 2);
        ScalarField field = (*field1) - (*field2);
        TS_ASSERT_EQUALS(field[0], 3);
        TS_ASSERT_EQUALS(field[1], 3);
        TS_ASSERT_EQUALS(field[2], 3);
        TS_ASSERT_EQUALS(field[3], 3);
        TS_ASSERT_EQUALS(field[4], 3);
        TS_ASSERT_EQUALS(field[5], 3);
        TS_ASSERT_EQUALS(field[6], 3);
        TS_ASSERT_EQUALS(field[7], 3);
        TS_ASSERT_EQUALS(field[8], 3);
        TS_ASSERT_EQUALS(field[9], 3);
        TS_ASSERT_EQUALS(field[10], 3);
        TS_ASSERT_EQUALS(field[11], 3);
    }

    void test_product(void)
    {
        ScalarField* field1 = new ScalarField(0, 1);
        ScalarField field = (*field1) * 3;
        TS_ASSERT_EQUALS(field[0], 3);
        TS_ASSERT_EQUALS(field[1], 3);
        TS_ASSERT_EQUALS(field[2], 3);
        TS_ASSERT_EQUALS(field[3], 3);
        TS_ASSERT_EQUALS(field[4], 3);
        TS_ASSERT_EQUALS(field[5], 3);
        TS_ASSERT_EQUALS(field[6], 3);
        TS_ASSERT_EQUALS(field[7], 3);
        TS_ASSERT_EQUALS(field[8], 3);
        TS_ASSERT_EQUALS(field[9], 3);
        TS_ASSERT_EQUALS(field[10], 3);
        TS_ASSERT_EQUALS(field[11], 3);
    }

    void test_divid(void)
    {
        ScalarField* field1 = new ScalarField(0, 6);
        ScalarField field = (*field1) / 2;
        TS_ASSERT_EQUALS(field[0], 3);
        TS_ASSERT_EQUALS(field[1], 3);
        TS_ASSERT_EQUALS(field[2], 3);
        TS_ASSERT_EQUALS(field[3], 3);
        TS_ASSERT_EQUALS(field[4], 3);
        TS_ASSERT_EQUALS(field[5], 3);
        TS_ASSERT_EQUALS(field[6], 3);
        TS_ASSERT_EQUALS(field[7], 3);
        TS_ASSERT_EQUALS(field[8], 3);
        TS_ASSERT_EQUALS(field[9], 3);
        TS_ASSERT_EQUALS(field[10], 3);
        TS_ASSERT_EQUALS(field[11], 3);
    }
};
