/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    status = CxxTest::Main<CxxTest::ErrorPrinter>( tmp, argc, argv );
    return status;
}
bool suite_SuiteIndex_init = false;
#include "test/test_index.h"

static SuiteIndex suite_SuiteIndex;

static CxxTest::List Tests_SuiteIndex = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SuiteIndex( "test/test_index.h", 6, "SuiteIndex", suite_SuiteIndex, Tests_SuiteIndex );

static class TestDescription_suite_SuiteIndex_test_all : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SuiteIndex_test_all() : CxxTest::RealTestDescription( Tests_SuiteIndex, suiteDescription_SuiteIndex, 10, "test_all" ) {}
 void runTest() { suite_SuiteIndex.test_all(); }
} testDescription_suite_SuiteIndex_test_all;

static class TestDescription_suite_SuiteIndex_test_ring_by_rind_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SuiteIndex_test_ring_by_rind_0() : CxxTest::RealTestDescription( Tests_SuiteIndex, suiteDescription_SuiteIndex, 17, "test_ring_by_rind_0" ) {}
 void runTest() { suite_SuiteIndex.test_ring_by_rind_0(); }
} testDescription_suite_SuiteIndex_test_ring_by_rind_0;

static class TestDescription_suite_SuiteIndex_test_ring_by_rind_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SuiteIndex_test_ring_by_rind_1() : CxxTest::RealTestDescription( Tests_SuiteIndex, suiteDescription_SuiteIndex, 33, "test_ring_by_rind_1" ) {}
 void runTest() { suite_SuiteIndex.test_ring_by_rind_1(); }
} testDescription_suite_SuiteIndex_test_ring_by_rind_1;

static class TestDescription_suite_SuiteIndex_test_ring_by_rind_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SuiteIndex_test_ring_by_rind_2() : CxxTest::RealTestDescription( Tests_SuiteIndex, suiteDescription_SuiteIndex, 85, "test_ring_by_rind_2" ) {}
 void runTest() { suite_SuiteIndex.test_ring_by_rind_2(); }
} testDescription_suite_SuiteIndex_test_ring_by_rind_2;

static class TestDescription_suite_SuiteIndex_test_pinr_by_rind_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SuiteIndex_test_pinr_by_rind_0() : CxxTest::RealTestDescription( Tests_SuiteIndex, suiteDescription_SuiteIndex, 119, "test_pinr_by_rind_0" ) {}
 void runTest() { suite_SuiteIndex.test_pinr_by_rind_0(); }
} testDescription_suite_SuiteIndex_test_pinr_by_rind_0;

static class TestDescription_suite_SuiteIndex_test_pinr_by_rind_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SuiteIndex_test_pinr_by_rind_1() : CxxTest::RealTestDescription( Tests_SuiteIndex, suiteDescription_SuiteIndex, 135, "test_pinr_by_rind_1" ) {}
 void runTest() { suite_SuiteIndex.test_pinr_by_rind_1(); }
} testDescription_suite_SuiteIndex_test_pinr_by_rind_1;

static class TestDescription_suite_SuiteIndex_test_pinr_by_rind_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SuiteIndex_test_pinr_by_rind_2() : CxxTest::RealTestDescription( Tests_SuiteIndex, suiteDescription_SuiteIndex, 187, "test_pinr_by_rind_2" ) {}
 void runTest() { suite_SuiteIndex.test_pinr_by_rind_2(); }
} testDescription_suite_SuiteIndex_test_pinr_by_rind_2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
