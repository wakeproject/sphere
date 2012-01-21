#include "src/index.h"
#include <cxxtest/TestSuite.h>

using namespace sphere;

class SuiteIndex : public CxxTest::TestSuite
{

public:
    void test_all(void)
    {
        TS_ASSERT_EQUALS(all(0), 12);
        TS_ASSERT_EQUALS(all(1), 48);
        TS_ASSERT_EQUALS(all(2), 192);
    }

    void test_ring_by_rind_0(void)
    {
        TS_ASSERT_EQUALS(ring_by_rind(0,  0), 1);
        TS_ASSERT_EQUALS(ring_by_rind(0,  1), 1);
        TS_ASSERT_EQUALS(ring_by_rind(0,  2), 1);
        TS_ASSERT_EQUALS(ring_by_rind(0,  3), 1);
        TS_ASSERT_EQUALS(ring_by_rind(0,  4), 2);
        TS_ASSERT_EQUALS(ring_by_rind(0,  5), 2);
        TS_ASSERT_EQUALS(ring_by_rind(0,  6), 2);
        TS_ASSERT_EQUALS(ring_by_rind(0,  7), 2);
        TS_ASSERT_EQUALS(ring_by_rind(0,  8), 3);
        TS_ASSERT_EQUALS(ring_by_rind(0,  9), 3);
        TS_ASSERT_EQUALS(ring_by_rind(0, 10), 3);
        TS_ASSERT_EQUALS(ring_by_rind(0, 11), 3);
    }

    void test_ring_by_rind_1(void)
    {
        TS_ASSERT_EQUALS(ring_by_rind(1,  0), 1);
        TS_ASSERT_EQUALS(ring_by_rind(1,  1), 1);
        TS_ASSERT_EQUALS(ring_by_rind(1,  2), 1);
        TS_ASSERT_EQUALS(ring_by_rind(1,  3), 1);
        TS_ASSERT_EQUALS(ring_by_rind(1,  4), 2);
        TS_ASSERT_EQUALS(ring_by_rind(1,  5), 2);
        TS_ASSERT_EQUALS(ring_by_rind(1,  6), 2);
        TS_ASSERT_EQUALS(ring_by_rind(1,  7), 2);
        TS_ASSERT_EQUALS(ring_by_rind(1,  8), 2);
        TS_ASSERT_EQUALS(ring_by_rind(1,  9), 2);
        TS_ASSERT_EQUALS(ring_by_rind(1, 10), 2);
        TS_ASSERT_EQUALS(ring_by_rind(1, 11), 2);
        TS_ASSERT_EQUALS(ring_by_rind(1, 12), 3);
        TS_ASSERT_EQUALS(ring_by_rind(1, 13), 3);
        TS_ASSERT_EQUALS(ring_by_rind(1, 14), 3);
        TS_ASSERT_EQUALS(ring_by_rind(1, 15), 3);
        TS_ASSERT_EQUALS(ring_by_rind(1, 16), 3);
        TS_ASSERT_EQUALS(ring_by_rind(1, 17), 3);
        TS_ASSERT_EQUALS(ring_by_rind(1, 18), 3);
        TS_ASSERT_EQUALS(ring_by_rind(1, 19), 3);
        TS_ASSERT_EQUALS(ring_by_rind(1, 20), 4);
        TS_ASSERT_EQUALS(ring_by_rind(1, 21), 4);
        TS_ASSERT_EQUALS(ring_by_rind(1, 22), 4);
        TS_ASSERT_EQUALS(ring_by_rind(1, 23), 4);
        TS_ASSERT_EQUALS(ring_by_rind(1, 24), 4);
        TS_ASSERT_EQUALS(ring_by_rind(1, 25), 4);
        TS_ASSERT_EQUALS(ring_by_rind(1, 26), 4);
        TS_ASSERT_EQUALS(ring_by_rind(1, 27), 4);
        TS_ASSERT_EQUALS(ring_by_rind(1, 28), 5);
        TS_ASSERT_EQUALS(ring_by_rind(1, 29), 5);
        TS_ASSERT_EQUALS(ring_by_rind(1, 30), 5);
        TS_ASSERT_EQUALS(ring_by_rind(1, 31), 5);
        TS_ASSERT_EQUALS(ring_by_rind(1, 32), 5);
        TS_ASSERT_EQUALS(ring_by_rind(1, 33), 5);
        TS_ASSERT_EQUALS(ring_by_rind(1, 34), 5);
        TS_ASSERT_EQUALS(ring_by_rind(1, 35), 5);
        TS_ASSERT_EQUALS(ring_by_rind(1, 36), 6);
        TS_ASSERT_EQUALS(ring_by_rind(1, 37), 6);
        TS_ASSERT_EQUALS(ring_by_rind(1, 38), 6);
        TS_ASSERT_EQUALS(ring_by_rind(1, 39), 6);
        TS_ASSERT_EQUALS(ring_by_rind(1, 40), 6);
        TS_ASSERT_EQUALS(ring_by_rind(1, 41), 6);
        TS_ASSERT_EQUALS(ring_by_rind(1, 42), 6);
        TS_ASSERT_EQUALS(ring_by_rind(1, 43), 6);
        TS_ASSERT_EQUALS(ring_by_rind(1, 44), 7);
        TS_ASSERT_EQUALS(ring_by_rind(1, 45), 7);
        TS_ASSERT_EQUALS(ring_by_rind(1, 46), 7);
        TS_ASSERT_EQUALS(ring_by_rind(1, 47), 7);
    }

    void test_ring_by_rind_2(void)
    {
        TS_ASSERT_EQUALS(ring_by_rind(2,   0), 1);
        TS_ASSERT_EQUALS(ring_by_rind(2,   3), 1);
        TS_ASSERT_EQUALS(ring_by_rind(2,   4), 2);
        TS_ASSERT_EQUALS(ring_by_rind(2,  11), 2);
        TS_ASSERT_EQUALS(ring_by_rind(2,  12), 3);
        TS_ASSERT_EQUALS(ring_by_rind(2,  23), 3);
        TS_ASSERT_EQUALS(ring_by_rind(2,  24), 4);
        TS_ASSERT_EQUALS(ring_by_rind(2,  39), 4);
        TS_ASSERT_EQUALS(ring_by_rind(2,  40), 5);
        TS_ASSERT_EQUALS(ring_by_rind(2,  55), 5);
        TS_ASSERT_EQUALS(ring_by_rind(2,  56), 6);
        TS_ASSERT_EQUALS(ring_by_rind(2,  71), 6);
        TS_ASSERT_EQUALS(ring_by_rind(2,  72), 7);
        TS_ASSERT_EQUALS(ring_by_rind(2,  87), 7);
        TS_ASSERT_EQUALS(ring_by_rind(2,  88), 8);
        TS_ASSERT_EQUALS(ring_by_rind(2, 103), 8);
        TS_ASSERT_EQUALS(ring_by_rind(2, 104), 9);
        TS_ASSERT_EQUALS(ring_by_rind(2, 119), 9);
        TS_ASSERT_EQUALS(ring_by_rind(2, 120), 10);
        TS_ASSERT_EQUALS(ring_by_rind(2, 135), 10);
        TS_ASSERT_EQUALS(ring_by_rind(2, 136), 11);
        TS_ASSERT_EQUALS(ring_by_rind(2, 151), 11);
        TS_ASSERT_EQUALS(ring_by_rind(2, 152), 12);
        TS_ASSERT_EQUALS(ring_by_rind(2, 167), 12);
        TS_ASSERT_EQUALS(ring_by_rind(2, 168), 13);
        TS_ASSERT_EQUALS(ring_by_rind(2, 179), 13);
        TS_ASSERT_EQUALS(ring_by_rind(2, 180), 14);
        TS_ASSERT_EQUALS(ring_by_rind(2, 187), 14);
        TS_ASSERT_EQUALS(ring_by_rind(2, 188), 15);
        TS_ASSERT_EQUALS(ring_by_rind(2, 191), 15);
    }

    void test_pinr_by_rind_0(void)
    {
        TS_ASSERT_EQUALS(pinr_by_rind(0,  0), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  1), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  2), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  3), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  4), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  5), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  6), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  7), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  8), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(0,  9), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(0, 10), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(0, 11), 4);
    }

    void test_pinr_by_rind_1(void)
    {
        TS_ASSERT_EQUALS(pinr_by_rind(1,  0), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  1), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  2), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  3), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  4), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  5), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  6), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  7), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  8), 5);
        TS_ASSERT_EQUALS(pinr_by_rind(1,  9), 6);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 10), 7);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 11), 8);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 12), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 13), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 14), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 15), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 16), 5);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 17), 6);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 18), 7);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 19), 8);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 20), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 21), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 22), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 23), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 24), 5);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 25), 6);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 26), 7);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 27), 8);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 28), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 29), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 30), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 31), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 32), 5);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 33), 6);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 34), 7);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 35), 8);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 36), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 37), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 38), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 39), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 40), 5);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 41), 6);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 42), 7);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 43), 8);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 44), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 45), 2);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 46), 3);
        TS_ASSERT_EQUALS(pinr_by_rind(1, 47), 4);
    }

    void test_pinr_by_rind_2(void)
    {
        TS_ASSERT_EQUALS(pinr_by_rind(2,   0), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2,   3), 4);
        TS_ASSERT_EQUALS(pinr_by_rind(2,   4), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  11), 8);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  12), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  23), 12);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  24), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  39), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  40), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  55), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  56), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  71), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  72), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  87), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2,  88), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 103), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 104), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 119), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 120), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 135), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 136), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 151), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 152), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 167), 16);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 168), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 179), 12);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 180), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 187), 8);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 188), 1);
        TS_ASSERT_EQUALS(pinr_by_rind(2, 191), 4);
    }
};
