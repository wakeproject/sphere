<CxxTest preamble>

#include "cxxtest/cxxtest/TestListener.h"
#include "cxxtest/cxxtest/TestTracker.h"
#include "cxxtest/cxxtest/TestRunner.h"
#include "cxxtest/cxxtest/RealDescriptions.h"
#include "cxxtest/cxxtest/TestMain.h"
#include "cxxtest/cxxtest/ErrorPrinter.h"

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    status = CxxTest::Main<CxxTest::ErrorPrinter>( tmp, argc, argv );
    return status;
}

<CxxTest world>
